//Author: Jake Waytus
//Date: 2/6/2024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int x;
    int i;
    int proc = 0;
    int simul = 0;
    int iter = 0;

    pid_t pid;

    char iter_string[10];

    while ((x = getopt(argc, argv, "hn:s:t:")) != -1)
    {

        switch (x)
        {

            case 'h':
                printf("Usage: oss [-h] [-n proc] [-s simul] [-t iter] \n");
                 return 0;
            
            case 'n':
                proc = atoi(optarg);
                break;
            
            case 's':
                simul = atoi(optarg);
                break;

            case 't':
                iter = atoi(optarg);
                break;

            default:
                printf("invalid option \n");
                return 1;

        }

    }

    sprintf(iter_string, "%d", iter);

    for (i = 0; i < proc; i++)
    {

        if ((pid = fork()) == 0)
        {

            execl("./user", "./user", iter_string, NULL);

        }

        if (i % simul == 0 && i !=0)
        {

            wait(NULL);

        }

    }

    while (wait(NULL) > 0);

    return 0;

}
