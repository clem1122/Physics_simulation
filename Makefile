FLAGS = -O -Wall -Werror -Wshadow
OBJS = main.o ball.o wall.o

all: main

wall.o: wall.h wall.cpp
	c++ -c wall.cpp $(FLAGS)
	
ball.o : ball.h ball.cpp
	c++ -c ball.cpp $(FLAGS)
	
main.o: main.cpp ball.o wall.o
	c++ -c main.cpp $(FLAGS)
	
main: main.o
	c++ -o main $(OBJS) $(FLAGS) -lsfml-graphics -lsfml-window -lsfml-system

