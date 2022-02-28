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
*Keywords—Bandgap reference circuit, Analog integrated circuit, Operational amplifier,low voltage, Curvature Compensation.*

## <a name="Introduction"></a>Introduction
The  bandgap  architecture  [1] based  on 80𝑛𝑚 BiCMOS shown in reference circuit section uses current mode principle for temperature compensation and add currents proportional to 𝑉𝐵𝐸1 and 𝑉𝑇. The operational amplifier is used to make the two voltages 𝑉𝐴and 𝑉𝐵equal thus producing a CTAT current in the nominally equal resistors R1 and R2 proportional to 𝑉𝐵𝐸. PTAT current proportional   to 𝑉𝐵𝐸1–𝑉𝐵𝐸2=𝑉𝑇𝑙𝑛𝑁 flows   through transistors  Q1  and  Q2.  

## Reference Circuit
### startup circuit
![Schematic of the two-stage operational amplifier [1]](/files/circuit_images/opamp_symbol.png)
### OpAmp
![Schematic of the two-stage operational amplifier [1]](/files/circuit_images/opamp_symbol.png)
### Band Gap Reference Circuit
![Schematic of the two-stage operational amplifier [1]](/files/circuit_images/opamp_symbol.png)

## Tools Used
- Synopsys Custom Compiler: This tool helped in designing various circuits at transistor level.
- Synopsys Primewave: This tool helped in various types of simulations of the above designed circuit.




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


