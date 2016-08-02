#include <stdio.h>
int main(void)
{
        int max = 0, count;
        count = scanf("%d", &max);
        if (count != 1)
        {
            return -1;
        }
        while (scanf("%d", &num) == 1)
    	{
        	if (num > max)
                {
            		max = num;
                        count = 1;
                }
        	else
                        if (num == max)
				count++;
	}
        printf("max %d, count %d\n", max, count);
	
	return 0; 
}
