OBJS	= rayTracer.o init_image_data.o saveppm.o threadfunction.o vector_operations.o
SOURCE	= rayTracer.c init_image_data.c saveppm.c threadfunction.c vector_operations.c
HEADER	= functions.h
OUT	= runme
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	rm -f $(OBJS) 

rayTracer.o: rayTracer.c
	$(CC) $(FLAGS) rayTracer.c 

init_image_data.o: init_image_data.c
	$(CC) $(FLAGS) init_image_data.c 

saveppm.o: saveppm.c
	$(CC) $(FLAGS) saveppm.c 

threadfunction.o: threadfunction.c
	$(CC) $(FLAGS) threadfunction.c 

vector_operations.o: vector_operations.c
	$(CC) $(FLAGS) vector_operations.c 


clean:
	rm -f  $(OUT)