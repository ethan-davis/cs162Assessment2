# this is an example makefile file
# you can use this as a basis for
# creating a makefile file for your
# assessments. 

CC=g++
CFLAGS=-g -Wall -std=c++11
HEADERS=main.h game.h
OBJECTS=main.o game.o

main: $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main 
 
%.o: %.c 
	$(CC) -c  $(CFLAGS) $< 

clean:
	rm *.o main
