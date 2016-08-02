#include <stdio.h>
#include "functions.h"
#include "errors.h"

void write_to_file(FILE* file, char* name, char* text)
{
    fopen(name, "w");
    fprintf(file, "%s", text);
    fclose(file);
}

char* filename = "temp.txt";

int main()
{
    puts("TestMode=on");

    float average = 0;
    float D = 0;
    float count = 0;
    int flag = 1;

    FILE* temp = fopen(filename, "r");
    fclose(temp);


    // calc_average tests

    if (calc_average(NULL, &average, &count) != -2)
    {
        flag = 0;
    }

    write_to_file(temp, filename, "");
    fopen(filename, "r");
    if (calc_average(temp, &average, &count) != -1)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "qwerty");
    fopen(filename, "r");
    if (calc_average(temp, &average, &count) != -2)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "1 2 3 4");
    fopen(filename, "r");
    if (calc_average(temp, &average, &count) != 0)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "1 2 3 4 5 6 7 8 9");
    fopen(filename, "r");
    calc_average(temp, &average, &count);
    if (count != 9 || average != 5)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "1 1 1 1 1 1");
    fopen(filename, "r");
    calc_average(temp, &average, &count);
    if( count != 6 || average != 1 )
        flag = 0;
    fclose(temp);

    write_to_file(temp, filename, "9 5");
    fopen(filename, "r");
    calc_average(temp, &average, &count);
    if( count != 2 || average != 7 )
        flag = 0;
    fclose(temp);

    if (flag == 1)
    {
        printf("function calc_average tests are successfuly passed.\n");
    }
    else
    {
        printf("function calc_average tests are failed.\n");
    }

    // disperse tests

    flag = 1;

    write_to_file(temp, filename, "");
    fopen(filename, "r");
    if (disperse(temp, 0, &D) != -1)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "qwerty");
    fopen(filename, "r");
    if (disperse(temp, 0, &D) != -2)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "9 5");
    fopen(filename, "r");
    disperse(temp, 7, &D);
    if (D != 4)
    {
         flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "1 2 3 4");
    fopen(filename, "r");
    disperse(temp, 2.5, &D);
    if (D != 1.25)
    {
        flag = 0;
    }   
    fclose(temp);

    write_to_file(temp, filename, "9 9 1 3");
    fopen(filename, "r");
    disperse(temp, 5.5, &D);
    if (D != 12.75)
    {
        flag = 0;
    }
    fclose(temp);

    write_to_file(temp, filename, "1 1 1 1 1");
    fopen(filename, "r");
    disperse(temp, 1, &D);
    if (D != 0)
    {
        flag = 0;   
    }
       
    fclose(temp);

    if (flag == 1)
        printf("function calcDisperse tests are successfully passed.\n");
    else
        printf("function calcDisperse tests are failed.\n");

    remove(filename);
    return 0;
}
