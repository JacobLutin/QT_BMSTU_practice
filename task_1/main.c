#include <stdio.h>
#include <string.h>


#define EMPTY_FILE -1            // I/O error. File is empty.
#define FILE_DOESNT_EXIST -2     // I/O error. File doesn't exist.
#define WRONG_DATA -3            // I/O error. File contains wrong data.

int process(FILE *f, int *count);


/**
 * @brief main
 * @param argc[in] - count of command arguments
 * @param argv[in] - array of command arguments
 * @return 0
 */

int main(int argc, char** argv)
{       
        int cmd_input = 0;
        int count_of_errors = 0;
        int count;
        int result;
        FILE *f;

        if (argc < 2)
        {
                cmd_input = 1;
                argc++;
        }

        for (int i = 1; i < argc; i++)
        {
                count = 0;

                if (cmd_input == 1)
                {
                        puts("Input sequence of integer numbers:");
                        result = process(stdin, &count);
                }
                else
                {
                        f = fopen(argv[i], "r"); 
                        result = process(f, &count);
                }
                switch (result)
                {
                        case EMPTY_FILE:
                                fprintf(stderr, "I/O error. File is empty.\n");
                                count_of_errors++;
                                break;
                        case FILE_DOESNT_EXIST:
                                fprintf(stderr, "I/O error. File doesn't exist.\n");
                                count_of_errors++;
                                break;
                        case WRONG_DATA:
                                fprintf(stderr, "I/O error. File contains wrong data.\n");
                                count_of_errors++;
                                break;
                        case 0:
                                fprintf(stdout, "Change of sign count in sequence = %d\n", count);
                                break;
                }

                //fclose(f);
        }

        if (cmd_input == 0) 
        {
                if (count_of_errors == 0)
                {
                        printf("All test are successfuly passed.\n");
                }
                else
                {
                        printf("Count of unsuccesesful tests = %d\n", count_of_errors);
                }
        }
        
        return 0;
}

/**
 * @brief proccess
 * @param f[in] - input file
 * @param count[out] - count of sign changes
 * @return 0
 */


int process(FILE *f, int *count)
{
        int num, prev_num;

        if (f == NULL)
        {
                return FILE_DOESNT_EXIST;
        }

        if (count == NULL)
        {
                return WRONG_DATA;
        }

        switch (fscanf(f, "%d", &prev_num))
        {
                case -1:
                        return EMPTY_FILE;
                case 0:
                        return WRONG_DATA;
        }



        while (fscanf(f, "%d", &num) == 1)
        {
                if ((prev_num < 0 && num >= 0) || (prev_num >= 0 && num < 0))
                {
                        *count += 1;
                }

                prev_num = num;
        }

        return 0;
}
