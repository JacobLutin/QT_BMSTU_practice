CC = gcc

CFLAGS = -std=c99 -Wall -Werror -pedantic
CLFLAGS = main *.o


ifeq ($(mode), debug)
	CFLAGS += -g3 -gdwarf-2
endif

ifeq ($(mode), release)
	CFLAGS += -g0 -DNDEBUG
endif


main: main.o functions.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(CLFLAGS)
