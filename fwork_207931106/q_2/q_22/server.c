# include <stdio.h>
# include <signal.h>

// gets signals (SIGINT or SIGUSR1) from the client

static int count_sigint = 0;

void handle_sigint(int sig) { 
    count_sigint++; 
} 

void handle_sigusr1(int sig) { 
    printf("number of SIGINTs that arrived to server: %d", count_sigint); 
}
  
int main() { 
    signal(SIGINT, handle_sigint); 
    signal(SIGINT, handle_sigint); 
    while (1) ; 
    return 0; 
} 
