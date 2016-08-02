#include <stdio.h>

#define EMPTY_FILE -1
#define WRONG_DATA -2

/**
 * @brief calc_average - calculates average value of sequence
 * @param f[in] - input file
 * @param average[out] - average value
 * @param count[out] - count of elements
 * @return 0
 */

int calc_average(FILE *f, float *average, float *count)
{
	float x;
	float sum = 0;

	if (f == NULL)
	{
		return WRONG_DATA;
	}

	if (average == NULL)
	{
		return WRONG_DATA;
	}

	if (count == NULL)
	{
		return WRONG_DATA;
	}

	switch (fscanf(f, "%f", &x))
	{
		case -1:
			return EMPTY_FILE;
		case 0:
			return WRONG_DATA;
	}

	*count = 1;

	sum = x;

	while (fscanf(f, "%f", &x) == 1)
	{
		sum += x;
		*count += 1;
	}

	*average = sum / *count;

	return 0;
}

/**
 * @brief disperse - calculates disperse of sequence
 * @param f[in] - input file
 * @param average[in] - input file
 * @param D[out] - dispserse value
 * @return 0
 */

int disperse(FILE *f, float average, float *D)
{
	float x;
	int count = 1;

	if (f == NULL)
	{
		return WRONG_DATA;
	}

	if (D == NULL)
	{
		return WRONG_DATA;
	}

	switch(fscanf(f, "%f", &x))
	{
		case -1:
			return EMPTY_FILE;
		case 0:
			return WRONG_DATA;
	}

	*D = (x - average) * (x - average);


	while (fscanf(f, "%f", &x) == 1)
	{
		*D += (x - average) * (x - average);
		count++;
	}

	*D /= count;

	return 0;
}
