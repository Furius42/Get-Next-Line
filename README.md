# Get-Next-Line

Getting started here..

Studying read() function, file descriptors as files, static functions.

Getting and idea of basic structure of the function.

Added main.c, lorem.txt fallback and headder updates..

// SO 
one buffer for each FD
buffer loads in whole
segment of buffer till \n or end of buffer loaded, remains moved to the front of the buffer, end of remains location stored, remaining space calculated 
	-if \n or EOF NOT encountered, there are no remains to be moved, end of remains location is 0 - buffer start.
		load buffer in whole

	-in \n encountered, call read, to buffer position one char beyond end of remains location, read till the end (remaining space calculated)

