// main.c

#include <stdio.h>
#include "main.h"

int array;

int main(void)
{
	int a, b, s;

	scanf("%d %d", &a, &b);
	s = sum(a, b);

	printf("%d\n", s);
}
