#include <stdio.h>
#include "functions.h"

void writeToFile(FILE* file, char* name, char* text)
{
    fopen(name, "w");
    fprintf(file, "%s", text);
    fclose(file);
}

char* filename = "temp.txt";

int main()
{

    float min = 0, max = 0, average = 0;
    int count = 0;
    int flag = 1;
    FILE* tfile = fopen(filename, "w");
    fclose(tfile);

    writeToFile(tfile, filename, "");
    fopen(filename, "r");
    if (min_max_found(tfile, &min, &max, &average) != -2)
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "1");
    fopen(filename, "r");
    if (min_max_found(tfile, &min, &max, &average) != -4)
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "1 2 3 4");
    fopen(filename, "r");
    if (min_max_found(tfile, &min, &max, &average) != 0)
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "1 2 3 4 5 6 7 8 9");
    fopen(filename, "r");
    min_max_found(tfile, &min, &max, &average);
    if( min != 1 || max != 9 )
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "1 1 1 1 1 1");
    fopen(filename, "r");
    min_max_found(tfile, &min, &max, &average);
    if( min != 1 || max != 1 )
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "9 5");
    fopen(filename, "r");
    min_max_found(tfile, &min, &max, &average);
    if( min != 5 || max != 9 )
        flag = 0;
    fclose(tfile);

    if (flag == 1)
        printf("success\n");
    else
        printf("fail\n");
    //num_of_greater test
    flag = 1;

    writeToFile(tfile, filename, "9 5");
    fopen(filename, "r");
    num_of_greater(tfile, 7, &count);
    if (count != 1)
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "1 7 5 5 5");
    fopen(filename, "r");
    num_of_greater(tfile, 4, &count);
    if (count != 4)
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "9 5 7 7 7 8");
    fopen(filename, "r");
    num_of_greater(tfile, 7, &count);
    if (count != 2)
        flag = 0;
    fclose(tfile);

    writeToFile(tfile, filename, "1 1 1 1 1");
    fopen(filename, "r");
    num_of_greater(tfile, 1, &count);
    if (count != 0)
        flag = 0;
    fclose(tfile);

    if (flag == 1)
        printf("function num_of_greater is succe\n");
    else
        printf("function num_of_greater is not ok\n");

    remove(filename);
    return 0;
}
