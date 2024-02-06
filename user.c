//Author: Jake Waytus
//Date: 2/6/2024

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv[])
{

    int x;
    int num;

    pid_t pid;
    pid_t ppid;

    if (argc != 2) 
    {

        printf("Usage: ./user <num> \n");
        return 1;

    }

    num = atoi(argv[1]);
    pid = getpid();
    ppid = getppid();

    for (x = 0; x < num; x++)
    {

        printf("USER PID:  PPID: %d Iteration: %d before sleeping \n", pid, ppid, x+1);

        sleep(1);

        printf("USER PID: %d PPID: %d Iteration: %d after sleeping \n",pid, ppid, x+1);

    }

    return 0;

}
