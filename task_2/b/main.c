#include <stdio.h>
#include "functions.h"
#include "errors.h"
#include "sum.h"

/**
 * @brief main - calculates average value of sequence
 * @param f[in] - input file
 * @param error_code - code of error
 * @param count - count of elements in sequence
 * @param average - average value of sequence
 * @param D - disperse value
 * @return 0
 */

int main(int argc, char** argv)
{	

	int s;

	sum(1, 2, &s);
	printf("%d\n", s);

	FILE *f;
	int error_code = 0;
	float count;
	float average;
	float D = 0;

	if (argc < 2) 
	{
		puts("No file name.");
		error_code = -1;
	}

	f = fopen(argv[1], "r");

	if ((f == NULL) && (error_code == 0))
	{
		fprintf(stderr, "I/O error. File doesn't exist.\n");
		error_code = -1;
	}

	if (error_code == 0)
	switch (calc_average(f, &average, &count))
	{
		case EMPTY_FILE:
			fprintf(stderr, "I/O error. File is empty.\n");
			error_code = -1;
			break;
			
		case WRONG_DATA:
			fprintf(stderr, "I/O error. File contains wrong data.\n");
			error_code = -2;
			break;		

		case 0:
			rewind(f);

			switch(disperse(f, average, &D))
			{
				case EMPTY_FILE:
					fprintf(stderr, "I/O error. File is empty.\n");
					error_code = -1;
					break;

				case WRONG_DATA:
					fprintf(stderr, "I/O error. File contains wrong data.\n");
					error_code = -2;
					break;
			}
			break;

	}

	fclose(f);

	if (error_code == 0)
	{
		fprintf(stdout, "Average x = %f\n", average);
		fprintf(stdout, "Disperse = %f\n", D);
	}
	
	return error_code;
}
