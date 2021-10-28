NAME = circle

OBJS = bmp.c circle_demo.c

CC = gcc

all:
	$(CC) $(OBJS) -o $(NAME)