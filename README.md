# Sub 1-V Bandgap Reference Circuit
This repository presents the design of Sub 1-V Bandgap Reference Circuit implemented using Synopsis Custom Compiler on 28nm CMOS Technology.

## Table of content

- [Abstract](https://github.com/yashashjain/BGR_Circuit/edit/main/README.md)<br/>
- [Introduction](#Introduction)<br/>
- [Reference Circuit]()<br/>
- [Tools Used]()<br/>
- [OpAmp]()<br/>
- [Band gap reference]()<br/>
- [Design Parameters]()<br/>
- [Simulations]()<br/>
- [Netlist]()<br/>
- [Acknowledgements]()<br/>
- [References]()

## Abstract
Bandgap  references  (BGR),  which  are  an integral   part   of   analog   and   mixed   signal   integrated circuits, are circuits that provide temperature, supply and process independent  output voltage. The main challenge in  this domain  is  to  ensure  correct  operation  in  sub  1V supply  voltages  as  we  proceed  to  smaller  technology nodes.<br/>
*Keywords—Bandgap reference circuit, Analog integrated circuit, Operational amplifier, low voltage, Curvature Compensation.*

## <a name="Introduction"></a>Introduction
Bandgap references (BGR) are circuits that provide a
temperature and supply independent output voltage. Voltage
references are among the most important building blocks in
current analog and mixed signal circuits and are a critical
component of any SoC. This calls for low voltage opera-
tion, while simultaneously ensuring that the generated output
voltage is insensitive to temperature and power supply varia-
tions.

## Tools Used
- Synopsys Custom Compiler: This tool helped in designing various circuits at transistor level.
- Synopsys Primewave: This tool helped in various types of simulations of the above designed circuit.

## OpAmp 
#### *Schematic*
![Schematic of the two-stage operational amplifier [1]](/files/circuit_images/opamp_schematic.png)
> Fig 1. Schematic of OpAmp.
#### *Symbol*
![Schematic of the two-stage operational amplifier [1]](/files/circuit_images/opamp_symbol.png)
> Fig 2. Symbol of OpAmp.
## Band Gap Circuit
In this circuit, all three reference circuit is included (startup circuit, OpAmp, BGR)
#### *Schematic*
![Schematic of the two-stage operational amplifier [1]](/files/circuit_images/bgr_final.png)
> Fig 3. Schematic of the Band Gap circuit with curvature compensation


## Design Paramters 
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

## Simulations
#### *Power Supply Variation:*
![Schematic of the two-stage operational amplifier [1]](/files/simulation_images/vref_vs_vdd.png)
> Fig 4. Measured bandgap voltage as a function of the power supply.
#### *Temperature Variation:*
![Schematic of the two-stage operational amplifier [1]](/files/simulation_images/vref_vs_temp_curvature_compensation.png)
> Fig 5. Measured bandgap voltage as a function of temperature with curvature compensation

## Netlist
Refer to the netlist of the circuits here: [Netlist](/files/Netlists)

## Author
Yashash Jain, MTech in Microelectronics and VLSI Design, Indian Institute of Science, Bangalore, India

## Acknowledgements
- Kunal Ghosh, Co-founder, VSD Corp. Pvt. Ltd.<br/>
- Cloud Based Analog IC Design Hackathon, IIT Hyderabad<br/>
- Synopsys India<br/>
- Sameer Durgoji, NIT Karnataka<br/>
- Chinmay panda, IIT Hyderabad<br/>

## References
[1] Malcovati,   P.,   et   al.   (2001).   Curvature-compensated   BiCMOS bandgap  with  1-V  supply  voltage.IEEE  Journal  of  Solid  State Circuits, 36, 1076–1081.<br/>
[2] Banba, H., et al. (1999). A CMOS bandgap reference circuit with sub 1-V operation. IEEE Journal of Solid State Circuits, 34(5), 670–674.<br/>
[3] Leung,  K.  N.,  Mok,  P.  K.  T.  (2002).  A  sub  1-V  15-ppm/°C  CMOS bandgap  voltage  reference  without  requiring  low  threshold  voltage device. IEEE Journal of Solid-State Circuits, 37, 526–530.<br/>


