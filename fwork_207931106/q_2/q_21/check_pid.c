# include <errno.h>
# include <stdio.h>
# include <signal.h>

// program to check if a proccess (with spesific pid) exists
// using kill(<pid>, 0) 

int main(int argc, char **argv) {
    int pid;
    sscanf(argv[1],"%d",&pid);
    if(kill(pid, 0) == 0)  // call to kill() is successful
        printf("Process %d exists", pid);
    else {  // call to kill() is fail [negative value returned]
        if(errno == ESRCH) 
            printf("Process %d does not exist", pid);
        else if(errno == EPERM) 
            printf("Process %d exists but we have no permission", pid);
        else
            printf("call to kill() failed for some reason");
    }
    return 0; 
}

