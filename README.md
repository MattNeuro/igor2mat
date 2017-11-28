# igor2mat

Convert packed experiment files (.pxp) into Matlab's binary .mat data format. In its current state, this will only convert raw wave data, nothing else: no meta-data, no notebooks, etc: unless it's a wave, it does not get converted. 

To use, simply drop the igor2mat executable into a directory containing Igor Pro experiment files and run it. It will search the directory for experiment files and convert each in turn, creating matlab files with the same name but different file extension. 

Cobbled together from the ANSI C Matlab File Exporter library created by Malcolm McLean, and Igor Pro sample code for reading experiment files. 

May have a teensy tinsy bit of a memory leak, so tends to crash after a few experiment files. 
