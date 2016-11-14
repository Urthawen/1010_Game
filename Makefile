PROG=1010
CC=g++
FLAGS=-Wall
SRCS=main.cpp pieces.cpp window.cpp
EXT=*.o
OBJS=$(SRCS:.c=.o)

all:$(OBJS)
	$(CC) -o $(PROG) $(OBJS) -lncurses

%.o:%.c
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	rm -f $(EXT) $(PROG)
