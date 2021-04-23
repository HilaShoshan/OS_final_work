#include <stdio.h>
#include <unistd.h>     
#include <signal.h>

// gets signals (SIGINT or SIGUSR1) from the client

int count_sigint = 0;

void handle_sigusr1() { 
    printf("number of SIGINTs that arrived to server: %d \n", count_sigint); 
}

void handle_sigint() { 
    count_sigint++; 
} 
  
int main() { 
    signal(SIGUSR1, handle_sigusr1); 
    signal(SIGINT, handle_sigint); 
    while (1) {}; 
    return 0; 
} 

