# HV-Scan_roll_to_CH
This code will asign a working point value to every RPC high voltage channel. There is a difference between barrel and endcap, in the barrel one chamber is connected to one high voltage channel (two or three rolls), and in the endcaps two chambers are connected to one high voltage channel (six rolls).

To run the code you have to do the following steps.

#####I. To create a directory called "data" (the directory is included by default, it contains the info for the 2016 HV Scan with the parameter emax fixed between 0 to 100) and include in it the following files:

barrel_summary.txt  -> Summary with parameters of the HV Scan for Barrel

endcap_summary.txt  -> Summary with parameters of the HV Scan for Endcaps

AveragedAll.txt     -> The list of chambers that are connected together according to WP in the endcaps

Alone_chambers.txt  -> A group of chambers that are not connected to other ones in the endcaps

#####II. To create a directory called "results" (the directory is included by default with the results of running the code with the 2016 HV Scan with emax fixed between 0 to 100) that will store the output of the code. As a result of running the code you will find the following files:


ch_diference_barrel.txt:
It will contain the following columns: chamber name, the difference between the roll with higher wp and lower wp within a chamber and the working point that has to be applied to the chamber. 

con3_rolls_barrel.txt:
It will contain the list of chambers coming from the barrel_summary.txt that have three rolls (Backward, Middle and Forward).

roll_difference_barrel.txt: 
It will contain the same info as ch_diference_barrel.txt, additionally it has the info of the "working point" for all the rolls that belongs to a chamber.

alone_ch_endcap.txt: 
It will contain the name of the chambers that are connected alone to one high voltage channel, the difference between the roll with higher wp and lower wp within the chamber and the working point that has to be applied to that chamber that finally means the voltage applied to that channel.

alone_rolls_endcap.txt:
It will contain the same info as alone_ch_endcap.txt, additionally it has the info of the "working point" for all the rolls that belongs to a chamber (in this case, three rolls).

ch_diference_endcap.txt:
It will contain the following columns: chamber name of one of the two chambers that belongs to that channel, the difference between the roll with higher wp and lower wp within a channel and the working point that has to be applied to the channel.

roll_difference_endcap.txt:
It will contain the same info as ch_diference_endcap.txt, additionally it has the info of the "working point" for all the rolls that belongs to the same channel (in total six rolls).

#####III. To run the code you have to compile and run the provided files:

Compiling:
g++ -o endcap channel_difference_endcap.cpp 

g++ -o alone alone.cpp

g++ -o barrel channel_difference_barrel.cpp 

Running:

./barrel

./endcap

./alone

By default the compiled files are included. 
