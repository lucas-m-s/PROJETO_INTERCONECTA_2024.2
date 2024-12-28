#!/bin/bash

freq=( 258.1	220.5	242.5	230.3 236.4	228.5	228.5	214 227.3	224.3	221.7	220.2 220	210.5	212	215.4 206	222	211.6	219.2 206	197.7	199.5	198 207.6	202.3	215.3	205 196.7	213.7	182.7	213.4 219.6	226.7	240	152.2 170.4	173.6	165.6	171.9 211.8	251.4	312.4	281.5 221.5	223.2	228.9	228.7 300.4	274.7	272.8	270.1 184.8	200.7	196	196.6 212.9	219	242.3	237.1 233	229.1	240.3	243.5 215.7	202.6	203.5	212.6 185.8	183.3	201.5	187.9 202.4	227.7	209.3	170 199.6	203	209.1	199 254.8	238	260.9	261.2 183.4	200.9	186.5	195 236.8	216.1	201.1	201.2 202	199.4	199	194.6 208.6	214	214.6	216 170.4	184.6	187.6	186.7 186.8	191.7	185.8	200.5 201.8	204.3	195.3	211.2 181.3	185.9	177.2	182.6 215	212.2	197	200 199.2	199.3	198.6	211.3 210	218	199.5	204.1 )
arq=( Ana1_mode.txt Ana2_mode.txt Ana3_mode.txt Ana4_mode.txt Analice1_mode.txt Analice2_mode.txt Analice3_mode.txt Analice4_mode.txt Andressa1_mode.txt Andressa2_mode.txt Andressa3_mode.txt Andressa4_mode.txt daiana1_mode.txt daiana2_mode.txt daiana3_mode.txt daiana4_mode.txt deyviane1_mode.txt deyviane2_mode.txt deyviane3_mode.txt deyviane4_mode.txt Duda1_mode.txt Duda2_mode.txt Duda3_mode.txt Duda4_mode.txt fernanda1_mode.txt fernanda2_mode.txt fernanda3_mode.txt fernanda4_mode.txt Gabi1_mode.txt Gabi2_mode.txt Gabi3_mode.txt Gabi4_mode.txt GabiA1_mode.txt GabiA2_mode.txt GabiA3_mode.txt GabiA4_mode.txt Jessica1_mode.txt Jessica2_mode.txt Jessica3_mode.txt Jessica4_mode.txt Joelly1_mode.txt Joelly2_mode.txt Joelly3_mode.txt Joelly4_mode.txt Joseane1_mode.txt Joseane2_mode.txt Joseane3_mode.txt Joseane4_mode.txt Julia1_mode.txt Julia2_mode.txt Julia3_mode.txt Julia4_mode.txt larissa1_mode.txt larissa2_mode.txt larissa3_mode.txt larissa4_mode.txt Lidia1_mode.txt Lidia2_mode.txt Lidia3_mode.txt Lidia4_mode.txt liz1_mode.txt liz2_mode.txt liz3_mode.txt liz4_mode.txt maisa1_mode.txt maisa2_mode.txt maisa3_mode.txt maisa4_mode.txt Manu1_mode.txt Manu2_mode.txt Manu3_mode.txt Manu4_mode.txt mariac1_mode.txt mariac2_mode.txt mariac3_mode.txt mariac4_mode.txt marinalda1_mode.txt marinalda2_mode.txt Marinalda3_mode.txt Marinalda4_mode.txt nery1_mode.txt nery2_mode.txt nery3_mode.txt nery4_mode.txt patricia1_mode.txt patricia2_mode.txt patricia3_mode.txt patricia4_mode.txt pauliny1_mode.txt pauliny2_mode.txt pauliny3_mode.txt pauliny4_mode.txt Poliana1_mode.txt Poliana2_mode.txt Poliana3_mode.txt Poliana4_mode.txt Priscila1_mode.txt Priscila2_mode.txt Priscila3_mode.txt Priscila4_mode.txt Raquel1_mode.txt Raquel2_mode.txt Raquel3_mode.txt Raquel4_mode.txt ravena1_mode.txt ravena2_mode.txt ravena3_mode.txt ravena4_mode.txt Rebeca1_mode.txt Rebeca2_mode.txt Rebeca3_mode.txt Rebeca4_mode.txt Sara1_mode.txt Sara2_mode.txt Sara3_mode.txt Sara4_mode.txt Silvana1_mode.txt Silvana2_mode.txt Silvana3_mode.txt Silvana4_mode.txt Taina1_mode.txt Taina2_mode.txt Taina3_mode.txt Taina4_mode.txt Thalita1_mode.txt Thalita2_mode.txt Thalita3_mode.txt Thalita4_mode.txt )


for (( i=0; i<128; i++)) do 
  echo "${freq[$i]} 1" > ./frequencias/${arq[$i]}
done