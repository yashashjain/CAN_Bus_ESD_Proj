# CAN Bus to Bluetooth Data Logger
This repository presents the implementation of CAN Bus to Bluetooth Data Logger using Tiva Lauchpads.

## Table of content

- [Introduction](#Introduction)<br/>
- [Propsed Plan](#OpAmp)<br/>
- [Component Used](#Tools)<br/>
- [Design Stages](#xyz)<br/>
- [Circuit Digram](#BGR)<br/>
- [Results](#Simulations)<br/>
- [Conclusion](#Netlist)<br/>
- [Acknowledgements](#Acknowledgements)<br/>
- [References](#References)



## <a name="Introduction"></a>Introduction
A Controller Area Network (CAN Bus) is a robust vehicle bus standard designed to allow microcontrollers and devices to communicate with each other's applications without a host computer.

For each device, the data in a frame is transmitted sequentially but in such a way that if more than one device transmits at the same time, the highest priority device can continue while the others back off.

Frames are received by all devices, including by the transmitting device.

## <a name="OpAmp"></a>OpAmp 
#### Objective:

Sending simulated vehicle data through Bluetooth (CAN Master 1).<br/>

Implement a Bluetooth interfaced CAN data logger/ bus monitor.<br/>

Shows real time traffic on CAN bus on a Bluetooth receiver (through mobile App).<br/>

Store the bus data on the Bluetooth receiver for detailed analysis.

#### Implementation:
The CAN bus traffic is simulated using two TIVA board and two CAN transceivers (MCP2551). Where Master 1 will send the vehicle simulated data through Bluetooth and Master 2 will flow some message continuously.<br/><br/>

The CAN data logger / bus monitor shall be implemented using an additional TIVA board and a CAN transceivers (MCP2551).<br/>
This node shall not participate in the CAN bus transmission but will log all the traffic in the bus<br/>
The captured  bus transactions shall be transmitted using Bluetooth in near real time through Bluetooth to a Bluetooth receiver (a mobile in this case) <br/>
The Bluetooth receiver shall also store the bus transaction for offline analysis



## <a name="Tools"></a>Tools Used
- Synopsys Custom Compiler: This tool helped in designing various circuits at transistor level.
- Synopsys Primewave: This tool helped in various types of simulations of the above designed circuit.




## <a name="xyz"></a>Design Parameters 
> RESISTANCE VALUES AND TRANSISTOR DIMENSIONS IN BAND GAP CIRCUIT  

|         Component           |      Parameter       | 
|-----------------------------|----------------------|
| Q1 , Q3 , Q4                | Normalized Area = 1  | 
| Q2                          | Normalized Area = 23 |                            
| M1  , M2 , M3 , M10 , M11   | W= 200 μm, L= 2 μm   | 
| M12                         | W= 30μm, L= 230nm    | 
| MS2 , MS3                   | W= 14 μm, L= 800nm   |  
| MS1                         | W= 16 μm, L= 160nm   | 
| M4 , M5                     | W= 150 μm, L= 800nm  | 
| M6 , M7 , M8 , M9           | W= 10 μm, L= 400nm   |  
| R0                          |      13.5K           | 
| R1,R2                       |       80K            | 
| R3                          |       35K            | 
| Rs                          |      170K            | 

## <a name="Simulation"></a>Simulations
#### *Power Supply Variation:*
![Vref Vs Vdd](/files/simulation_images/vref_vs_vdd.png)
> Fig 4. Measured bandgap voltage as a function of the power supply.
#### *Temperature Variation:*
![Vref vs Temperature](/files/simulation_images/vref_vs_temp_curvaure_compensation.png)
> Fig 5. Measured bandgap voltage as a function of temperature with curvature compensation

## <a name="Netlist"></a>Netlist
Refer to the netlist of the circuits here: [Netlist](/files/Netlists)

## Author
Yashash Jain, MTech in Microelectronics and VLSI Design, Indian Institute of Science, Bangalore, India

## <a name="Acknowledgements"></a>Acknowledgements
- Kunal Ghosh, Co-founder, VSD Corp. Pvt. Ltd.<br/>
- Cloud Based Analog IC Design Hackathon, IIT Hyderabad<br/>
- Synopsys India<br/>
- Chinmay panda, IIT Hyderabad<br/>
- Sameer Durgoji, NIT Karnataka


## <a name="References"></a>References
[1] Malcovati,   P.,   et   al.   (2001).   Curvature-compensated   BiCMOS bandgap  with  1-V  supply  voltage.IEEE  Journal  of  Solid  State Circuits, 36, 1076–1081.<br/>
[2] Banba, H., et al. (1999). A CMOS bandgap reference circuit with sub 1-V operation. IEEE Journal of Solid State Circuits, 34(5), 670–674.<br/>
[3] Leung,  K.  N.,  Mok,  P.  K.  T.  (2002).  A  sub  1-V  15-ppm/°C  CMOS bandgap  voltage  reference  without  requiring  low  threshold  voltage device. IEEE Journal of Solid-State Circuits, 37, 526–530.<br/>


