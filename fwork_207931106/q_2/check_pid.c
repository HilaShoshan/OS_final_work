# include <errno.h>
# include <stdio.h>

// program to check if a proccess (with spesific pid) exists
// using kill(<pid>, 0) 

int main(int argc, char **argv) {
    int pid = argv[0]; 
    int kill_res = kill(pid, 0); 
    printf(kill_res);
    if(kill_res == -1) {}
    return 0; 
}

