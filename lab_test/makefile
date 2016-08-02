CC = gcc
FLAGS = -std=c99 -Wall -Werror -pedantic
CLFLAGS = main main.dsym *.o *.s

ifeq ($(mode), debug)
	FLAGS += -g3
endif

ifeq ($(mode), release)
	FLAGS += -g0 -DNDEBUG
endif

main: main.o sum.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(CLFLAGS)

main.dump: main
	gobjdump -S --disassemble main > main.dump

main.o.dump: main.o
	gobjdump -S --disassemble main.o > main.o.dump

sum.o.dump: sum.o
	gobjdump -S --disassemble sum.o > sum.o.dump
