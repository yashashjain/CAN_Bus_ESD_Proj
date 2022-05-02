# CAN Bus to Bluetooth Data Logger
This repository presents the implementation of CAN Bus to Bluetooth Data Logger using Tiva Lauchpads.

## Table of content

- [Introduction](#Introduction)<br/>
- [Proposed Plan](#Proposed)<br/>
- [Components](#Components)<br/>
- [Design Stages](#Design)<br/>
- [Circuit Digram](#Circuit)<br/>
- [Results](#Resultls)<br/>
- [Conclusion](#Conclusion)<br/>
- [Acknowledgements](#Acknowledgements)<br/>
- [References](#References)



## <a name="Introduction"></a>Introduction
A Controller Area Network (CAN Bus) is a robust vehicle bus standard designed to allow microcontrollers and devices to communicate with each other's applications without a host computer.

For each device, the data in a frame is transmitted sequentially but in such a way that if more than one device transmits at the same time, the highest priority device can continue while the others back off.

Frames are received by all devices, including by the transmitting device.

## <a name="Proposed"></a>Proposed Plan
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



## <a name="Components"></a>Components
Three Tiva Launchpads<br/>
Three MCP2551 Transceivers<br/>
Two 120 ohms resistor<br/>
Two Bluetooth Module (HC-05)<br/>
One Breadboard, Jumper wires<br/>
Two Android Devices


## <a name="Design"></a>Design Stages
![design](/images/1.png)

## <a name="Circuit"></a>Circuit Diagram
![design](/images/2.png)


## <a name="Resultls"></a>Results
#### *Sending Vehicle Simulated data through App:*
![Vref Vs Vdd](/images/3.png)

#### *Bus Monitor Output through BLE App:*
![Vref vs Temperature](/images/4.png)

#### *Log Data File Saves as .txt:*
![Vref vs Temperature](/images/5.png)


## <a name="Conclusion"></a>Conclusion
A detailed implementation of CAN Bus to Bluetooth data logger is done.
Through debug, we solved the problem of driving capability.
Hardware implementation give the better hand on learning experience.
Through this project, we realized how actually CAN Bus has important application in automotive and other industries.
Got the idea of embedded system design procedure through this mini project like specification to implementation, algorithm to architecture, partitioning, design blocks, Tiva implementation.


## Author
Yashash Jain & Paul Antony, MTech Students, Indian Institute of Science, Bangalore, India

## <a name="Acknowledgements"></a>Acknowledgements
- Prof. Haresh Dagale, Professor, IISc Bagalore <br/>
- Koya Naresh, Project Associate, IISc Bagalore


## <a name="References"></a>References
[1]	en.wikipedia.org/wiki/CAN_bus<br/>
[2]	Digital Interconnects from edwiki<br/>
[3]	Lecture Notes {Embedded System Design by Haresh Sir}<br/>
[4]	HC-05 Bluetooth Interfacing with TM4C123G Tiva C Launchpad – Keil uvision




