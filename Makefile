# A simple Makefile
# # Saad Arshad 00857432
# # CS 262, Lab Section 208
# # Project1 
# The compiler: gg for C programs, g++ for C++ programs, etc

CC = gcc
CFLAGS = -g -Wall
TARGET = project1

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm $(TARGET)
