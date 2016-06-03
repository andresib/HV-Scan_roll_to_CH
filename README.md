# HVScan-Code
To run the code you have to do the following steps.

1. To create a directory called "data" and include in it the following files:
barrel_summary.txt  -> Summary with parameters of the HV Scan for Barrel
endcap_summary.txt  -> Summary with parameters of the HV Scan for Endcaps
AveragedAll.txt     -> The list of chambers that are connected together according to WP
Alone_chambers.txt  -> A group of chambers that are not connected to other ones

2. To create a directory called "results" that will store the output of the code. As a result of running the code you will find the following files:

Alone_chamber_barrel.txt

ch_diference_barrel.txt
It will contain the following columns: chamber name, the difference between the roll with higher wp and lower wp within a chamber and the working point that has to be applied to the chamber. 

con3_rolls_barrel.txt
It will contain the list of chambers coming from the barrel_summary.txt that have three rolls (Backward, Middle and Forward).

roll_difference_barrel.txt 
It will contain the same info as ch_diference_barrel.txt, additionally it has the info of the "working point" for all the rolls that belongs to a chamber.
