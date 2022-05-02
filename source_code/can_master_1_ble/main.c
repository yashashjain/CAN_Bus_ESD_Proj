/*
 * CAN bus LED controller master firmware
 * Written for TI Tiva TM4C1294NCPDT
 */

#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"

#include "uartstdio.h"

#define PI 3.14159265359f
#define BLE_CMD_LEN 422

volatile bool errFlag = 0; // transmission error flag
unsigned int sysClock; // clockspeed in hz
unsigned long err_status;

void CANIntHandler(void);
void delay(unsigned int );


int main(void) {

    tCANMsgObject msg; // the CAN message object
    unsigned int msgData[2]; // the message data is four bytes long which we can allocate as an int32
    unsigned char *msgDataPtr = (unsigned char *)&msgData; // make a pointer to msgData so we can access individual bytes

    // Run from crystal at 50Mhz
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    // Set up bluetooth UART
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    GPIOPinConfigure(GPIO_PC4_U1RX);
    GPIOPinConfigure(GPIO_PC5_U1TX);
    GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    // Set up debugging UART
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTStdioConfig(0, 115200, SysCtlClockGet());

    // Set up CAN0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    GPIOPinConfigure(GPIO_PE4_CAN0RX);
    GPIOPinConfigure(GPIO_PE5_CAN0TX);
    GPIOPinTypeCAN(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
    CANInit(CAN0_BASE);
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
    CANIntRegister(CAN0_BASE, CANIntHandler); // use dynamic vector table allocation
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);
    IntEnable(INT_CAN0);
    CANEnable(CAN0_BASE);

    // Set up msg object
    msgData[0] = 0;
    msgData[1] = 0;
    msg.ui32MsgID = 1;
    msg.ui32MsgIDMask = 0xFFFFFFFF;
    msg.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    msg.ui32MsgLen = 8;
    msg.pui8MsgData = msgDataPtr;

    char val, cmd_str[4] = "";
    int j=0, ble_cmd[14];


    while(1) {

        // set up next colour (scale sinf (0-1) to 0-255)
        if (UARTCharsAvail(UART1_BASE))
        {
            val = UARTCharGet(UART1_BASE);
            if (val==',')
            {
                ble_cmd[j] = atoi (cmd_str);
                j++;
                cmd_str[0] = '\0';
                if (j>=14)              // One frame of BLE msg completed
                {
                    j=0;
                    msgDataPtr[0]=ble_cmd[0];
                    msgDataPtr[1]=ble_cmd[1];
                    msgDataPtr[2]=ble_cmd[2];
                    msgDataPtr[3]=ble_cmd[3];
                    msgDataPtr[4]=ble_cmd[4];
                    msgDataPtr[5]=ble_cmd[5];
                    msgDataPtr[6]=ble_cmd[6];
                    msgDataPtr[7]=ble_cmd[7];

                    UARTprintf("Sending msg\t:%02x%02x %02x%02x %02x%02x %02x%02x\n", msgDataPtr[0], msgDataPtr[1], msgDataPtr[2], msgDataPtr[3], msgDataPtr[4], msgDataPtr[5], msgDataPtr[6], msgDataPtr[7]);
                    CANMessageSet(CAN0_BASE, 1, &msg, MSG_OBJ_TYPE_TX); // send as msg object 1
                    delay(100); // wait 100ms
                    if(errFlag) { // check for errors
                        UARTprintf("CAN Bus Error  %x\n",err_status );
                    }

                    msgDataPtr[0]=ble_cmd[8];
                    msgDataPtr[1]=ble_cmd[9];
                    msgDataPtr[2]=ble_cmd[10];
                    msgDataPtr[3]=ble_cmd[11];
                    msgDataPtr[4]=ble_cmd[12];
                    msgDataPtr[5]=ble_cmd[13];
                    msgDataPtr[6]=0x00;
                    msgDataPtr[7]=0x00;

                    UARTprintf("Sending msg\t:%02x%02x %02x%02x %02x%02x %02x%02x\n", msgDataPtr[0], msgDataPtr[1], msgDataPtr[2], msgDataPtr[3], msgDataPtr[4], msgDataPtr[5], msgDataPtr[6], msgDataPtr[7]);
                    CANMessageSet(CAN0_BASE, 1, &msg, MSG_OBJ_TYPE_TX); // send as msg object 1
                    delay(100); // wait 100ms
                    if(errFlag) { // check for errors
                        UARTprintf("CAN Bus Error  %x\n",err_status );
                    }
                }

            }
            else
            {
                strncat(cmd_str, &val, 1);
            }
        }




    }

    return 0;
}


// CAN interrupt handler
void CANIntHandler(void) {

    unsigned long status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE); // read interrupt status

    if(status == CAN_INT_INTID_STATUS) { // controller status interrupt
        err_status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
        errFlag = 1;
    } else if(status == 1) { // message object 1
        CANIntClear(CAN0_BASE, 1); // clear interrupt
        errFlag = 0; // clear any error flags
        err_status = 0;
    } else { // should never happen
        UARTprintf("Unexpected CAN bus interrupt\n");
    }
}

void delay(unsigned int milliseconds)
{
    int i, j;
    for(i = 0 ; i < milliseconds; i++)
        for(j = 0; j < 3180; j++) {}   /* do nothing for 1 ms */
}
