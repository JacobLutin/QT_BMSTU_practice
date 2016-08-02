CC = gcc
FLAGS = -std=c99 -Wall -Werror -pedantic
CLFLAGS = main main.exe.dsym *.o *.s


ifeq ($(mode), debug)
	FLAGS += -g3
endif

ifeq ($(mode), release)
	FLAGS += -g0 -DNDEBUG
endif


main: main.c
	$(CC) $(FLAGS) -o $@ $<

clean:
	rm -rf $(CLFLAGS)
