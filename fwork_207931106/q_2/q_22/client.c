# include <stdio.h>
# include <signal.h>

// can send two types of signals to the server: SIGINT, SIGUSR1

int main(int argc, char **argv) {
    int server_pid, signal_num, signal_count;
    sscanf(argv[1],"%d",&server_pid);
    sscanf(argv[2],"%d",&signal_num);
    sscanf(argv[3],"%d",&signal_count);
    int i = 0;
    while(i < signal_count) {
        kill(server_pid, signal_num);
    } 
    return 0;
}