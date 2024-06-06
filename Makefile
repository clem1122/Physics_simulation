FLAGS = -O -Wall -Werror -Wshadow
OBJS = main.o ball.o

all: main

ball.o : ball.h ball.cpp
	c++ -c ball.cpp $(FLAGS)
	
main.o: main.cpp ball.o
	c++ -c main.cpp $(FLAGS)
	
main: main.o
	c++ -o main $(OBJS) $(FLAGS) -lsfml-graphics -lsfml-window -lsfml-system

