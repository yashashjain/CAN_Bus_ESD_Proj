# Sub 1-V Bandgap Reference Circuit
This repository presents the design of Sub 1-V Bandgap Reference Circuit implemented using Synopsis Custom Compiler on 28nm CMOS Technology.

## Table of content

- [Abstract](#Abstract)<br/>
- [Introduction](#Introduction)<br/>
- [Tools Used](#Tools)<br/>
- [OpAmp](#OpAmp)<br/>
- [Band Gap Circuit](#BGR)<br/>
- [Design Parameters](#xyz)<br/>
- [Simulations](#Simulations)<br/>
- [Netlist](#Netlist)<br/>
- [Acknowledgements](#Acknowledgements)<br/>
- [References](#References)

## <a name="Abstract"></a>Abstract
Bandgap  references  (BGR),  which  are  an integral   part   of   analog   and   mixed   signal   integrated circuits, are circuits that provide temperature, supply and process independent  output voltage. The main challenge in  this domain  is  to  ensure  correct  operation  in  sub  1V supply  voltages  as  we  proceed  to  smaller  technology nodes.<br/>
*Keywords—Bandgap reference circuit, Analog integrated circuit, Operational amplifier, low voltage, Curvature Compensation.*

## <a name="Introduction"></a>Introduction
Bandgap references (BGR) are circuits that provide a temperature and supply independent output voltage. Voltage references are among the most important building blocks in current analog and mixed signal circuits and are a critical component of any SoC. This calls for low voltage operation, while simultaneously ensuring that the generated output voltage is insensitive to temperature and power supply variations.

## <a name="Tools"></a>Tools Used
- Synopsys Custom Compiler: This tool helped in designing various circuits at transistor level.
- Synopsys Primewave: This tool helped in various types of simulations of the above designed circuit.

## <a name="OpAmp"></a>OpAmp 
#### *Schematic*
![Schematic of the two-stage operational amplifier](/files/circuit_images/opamp_schematic.png)
> Fig 1. Schematic of two stage OpAmp.
#### *Symbol*
![symbol of the two-stage operational amplifier](/files/circuit_images/opamp_symbol.png)
> Fig 2. Symbol of two stage OpAmp.
## <a name="BGR"></a>Band Gap Circuit
In this circuit, all three reference circuit is included (startup circuit, OpAmp, BGR)
#### *Schematic*
![Schematic of the BGR circuit](/files/circuit_images/bgr_final.png)
> Fig 3. Schematic of the Band Gap circuit with curvature compensation


## <a name="xyz"></a>Design Paramters 
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


