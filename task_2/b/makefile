CC = clang

CFLAGS = -Wall -Werror
CLFLAGS = main *.o *.gch *.gcov *.gcno *.gcda

ifeq ($(mode), gcov)
	CFLAGS += -fprofile-arcs -ftest-coverage
endif

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -g0 -DNDEBUG
endif


main: main.o functions.o sum.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(CLFLAGS)
