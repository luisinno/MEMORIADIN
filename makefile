OBJS = main.o matrizBidimensional.o
CC = gcc
#CTAGS = -c 
CTAGS = -c -g -DDEBUG

matrices : $(OBJS)
	$(CC) $(OBJS) -o matrices

main.o : main.c matrizBidimensional.h  
	$(CC) $(CTAGS) main.c

matrizBidimensional.o : matrizBidimensional.c matrizBidimensional.h
	$(CC) $(CTAGS) matrizBidimensional.c
	
