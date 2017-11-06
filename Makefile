	# 
# Small makefile
#
CC = g++

projet: projet.o  
	$(CC) -o projet projet.o  -L/usr/lib/x86_64-linux-gnu -L/usr/X11R6/lib64 /usr/lib/x86_64-linux-gnu/libGL.so /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/x86_64-linux-gnu/libglut.so /usr/lib/x86_64-linux-gnu/libGLEW.so -lm -lpthread 
all: projet
