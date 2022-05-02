/*
 * CAN bus LED controller slave firmware
 * Written for TI Tiva TM4C123GH6PM
 */

#include <stdint.h>
#include <stdbool.h>

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
#include "inc/tm4c123gh6pm.h"

#include "uartstdio.h"

volatile bool rxFlag = 0; // msg recieved flag
volatile bool errFlag = 0; // error flag
static unsigned long tick_time = 0;

unsigned long err_status=0;

void SysTick_Handler(void);
void CANIntHandler(void);

// CAN interrupt handler
void CANIntHandler(void) {

    unsigned long status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE); // read interrupt status

    if(status == CAN_INT_INTID_STATUS) { // controller status interrupt
        err_status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
        errFlag = 1;
    } else if(status == 1) { // msg object 1
        CANIntClear(CAN0_BASE, 1); // clear interrupt
        rxFlag = 1; // set rx flag
        errFlag = 0; // clear any error flags
        err_status = 0;
    } else { // should never happen
        UARTprintf("Unexpected CAN bus interrupt\n");
    }
}

int main(void) {

    int* p_time = (int*) &tick_time;

    tCANMsgObject msg; // the CAN msg object
    unsigned char msgData[8]; // 8 byte buffer for rx message data

    // Run from crystal at 50Mhz
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

//    // Set up debugging UART
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
//    GPIOPinConfigure(GPIO_PA0_U0RX);
//    GPIOPinConfigure(GPIO_PA1_U0TX);
//    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
//    UARTStdioConfig(0, 115200, SysCtlClockGet());


    // Set up debugging UART
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    GPIOPinConfigure(GPIO_PC4_U1RX);
    GPIOPinConfigure(GPIO_PC5_U1TX);
    GPIOPinTypeUART(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    UARTStdioConfig(1, 9600, SysCtlClockGet());

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

    SysTick_Init();



    // Use ID and mask 0 to recieved messages with any CAN ID
    msg.ui32MsgID = 0;
    msg.ui32MsgIDMask = 0;
    msg.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    msg.ui32MsgLen = 8; // allow up to 8 bytes

    // Load msg into CAN peripheral message object 1 so it can trigger interrupts on any matched rx messages
    CANMessageSet(CAN0_BASE, 1, &msg, MSG_OBJ_TYPE_RX);

    unsigned int colour[3];
    float intensity;
    UARTprintf("Starting  CAN Bus Monitor \n\n");

    UARTprintf("Time(ms)    Msd_ID    Msg_len   Flags   Data(0x)");

    while(1) {

        if(rxFlag) { // rx interrupt has occured

            msg.pui8MsgData = msgData; // set pointer to rx buffer
            CANMessageGet(CAN0_BASE, 1, &msg, 0); // read CAN message object 1 from CAN peripheral

            rxFlag = 0; // clear rx flag

            if(msg.ui32Flags & MSG_OBJ_DATA_LOST) { // check msg flags for any lost messages
                UARTprintf("CAN message loss detected\n");
            }

            UARTprintf("%u%u    %u    %u    %u    %02x%02x %02x%02x %02x%02x %02x%02x\n", p_time[0], p_time[1], msg.ui32MsgID, msg.ui32MsgLen, err_status , msgData[0], msgData[1], msgData[2], msgData[3], msgData[4], msgData[5], msgData[6], msgData[7]);

        }
    }

    return 0;
}

void SysTick_Handler(void)
{
    tick_time +=1;         /* toggle the red LED */
}

void SysTick_Init (void)
{
    /* Configure SysTick */
    NVIC_ST_RELOAD_R = 50000-1;  /* reload with number of clocks per second */
    NVIC_ST_CTRL_R = 7;             /* enable SysTick interrupt, use system clock */
    enable_irq();                   /* global enable interrupt */
}

void inline enable_irq(void)
{
    __asm  ("    CPSIE  I\n");
}
