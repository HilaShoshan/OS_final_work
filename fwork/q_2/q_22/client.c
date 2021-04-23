#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// can send two types of signals to the server: SIGINT, SIGUSR1

int main(int argc, char **argv) {
    int server_pid, signal_num, signal_count;
    sscanf(argv[1],"%d",&server_pid);
    sscanf(argv[2],"%d",&signal_num);
    sscanf(argv[3],"%d",&signal_count);
    if(signal_num != 2 || signal_num != 10) {
        printf("signal_num is illegal! \n please choose 2 for SIGINT or 10 for SIGUSR1");
        exit(1);
    }
    int i = 0;
    while(i < signal_count) {
        kill(server_pid, signal_num);
        i++;
    } 
    return 0;
}

