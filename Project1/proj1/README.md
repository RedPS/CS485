# Programming Assignment 1

There has been a lot of hard coding in this assignment. So please use the makefile uploaded with this document. 
The images have to go to a file named images and there has to be 2 sets in 2 different folders, S1 and S2. If you decided to 
change the data base for pictures then please modify the make file. 

All of the SVD functions that were provided to us have been modified so please use the ones that have been uploaded with the main driver to compile and execute the program. 

The SVD functions provided to us were weird as they were indexing from 1 and some other confusing matters. Future projects will not be writting using these functions as they caused too much confusion.

## NOTE about this program
Please note that this program does NOT require opencv, no opencv function was used in this program. 
Functions used to read and write PGM files are the files the user used in previous CS classes (Image Processing)
And we were provided the SVD functions so there was no need to use OPENCV

## To Execute the program 
```
make
```
The way this program runs is that it will look for command line arguments. 

```
./Project1 <Picture> <coordinates of the features>
```
### <Picture>
This is just the path to the picture

### <coordinates of the features>
You will need to enter the coordiates in order. 
Left eye, right eye, tip of nose, center of mouth

To make it easier the below are the coordinates for the data base of images provided to us please use these.
```
S1_1        26 51    63 50   45 70   44 88
S1_2        30 44    75 43   65 66   58 85
S1_3        24 48    62 45   44 72   45 89
S1_4        15 45    58 41   27 63   32 82
S1_5        33 44    74 42   68 63   63 83
S1_6        13 47    54 44   26 66   30 85
S1_7        23 45    62 43   43 59   43 79
S1_8        28 46    65 43   49 65   48 84
S1_9        30 37    67 35   52 48   52 72
S1_10       34 52    74 49   63 76   60 90


S1_1        24 51    59 53   40 68   39 87 
S1_2        35 50    68 51   54 66   53 86
S1_3        20 50    56 53   33 66   33 86
S1_4        32 53    65 52   50 69   49 88
S1_5        39 53    73 52   60 68   58 88
S1_6        16 51    50 52   24 67   27 88
S1_7        29 52    61 53   45 69   44 87
S1_8        21 50    57 51   35 66   35 87
S1_9        34 53    68 54   51 69   49 89
S1_10       46 53    77 52   72 68   67 87
```
The make file will take care of execution so you will not have to manually write those coordinates and execute one by one.

## To Execute the program with the parameters (feature coordinates)
Work on 1st set of images 
```
make S1
```
work on 2nd set of Images 
```
make S2
```
The result images will go to the same path as their source images. Their will be a "Result" appended to their names to make it easier to identify them.

## Executing on one image at a time 
You can use the below commands to execute the program on one image at a time 
```
	./Project1 Images/S1/1.pgm 26 51 63 50 45 70 44 88
	./Project1 Images/S1/2.pgm 30 44 75 43 65 66 58 85
	./Project1 Images/S1/3.pgm 24 48 62 45 44 72 45 89
	./Project1 Images/S1/4.pgm 15 45 58 41 27 63 32 82
	./Project1 Images/S1/5.pgm 33 44 74 42 68 63 63 83
	./Project1 Images/S1/6.pgm 13 47 54 44 26 66 30 85
	./Project1 Images/S1/7.pgm 23 45 62 43 43 59 43 79
	./Project1 Images/S1/8.pgm 28 46 65 43 49 65 48 84
	./Project1 Images/S1/9.pgm 30 37 67 35 52 48 52 72
	./Project1 Images/S1/10.pgm 34 52 74 49 63 76 60 90

	./Project1 Images/S2/1.pgm 24 51 59 53 40 68 39 87
	./Project1 Images/S2/2.pgm 35 50 68 51 54 66 53 86
	./Project1 Images/S2/3.pgm 20 50 56 53 33 66 33 86
	./Project1 Images/S2/4.pgm 32 53 65 52 50 69 49 88
	./Project1 Images/S2/5.pgm 39 53 73 52 60 68 58 88
	./Project1 Images/S2/6.pgm 16 51 50 52 24 67 27 88
	./Project1 Images/S2/7.pgm 29 52 61 53 45 69 44 87
	./Project1 Images/S2/8.pgm 21 50 57 51 35 66 35 87
	./Project1 Images/S2/9.pgm 34 53 68 54 51 69 49 89
	./Project1 Images/S2/10.pgm 46 53 77 52 72 68 67 87
```
## To clean up 
```
make clean
```
there might be some errors when cleaning, ignore those. This make file was written in a rush and it works perfectly fine for what it has to do. 

## Note to the grader
If you have any more questions about compiling or running the program please consult the author by emailing or sending a message on webcampus. 
