
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>     
 #include <sched.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <stdint.h>
 #include <linux/sched.h>


// CPU Scheduling in Linux
// program that set policy of timing and priorities of a process

/* parameters to send (from terminal):
    1) number that represents a spesific policy
        SCHED_OTHER ------ 0
        SCHED_FIFO ------- 1
        SCHED_RR --------- 2
        SCHED_BATCH ------ 3
        SCHED_IDLE ------- 5
        SCHED_DEADLINE --- 6
    2) number that represents priority
*/


struct sched_attr {
    uint32_t size;              /* Size of this structure */
    uint32_t sched_policy;      /* Policy (SCHED_*) */
    uint64_t sched_flags;       /* Flags */
    int32_t sched_nice;         /* Nice value (SCHED_OTHER, SCHED_BATCH) */
    uint32_t sched_priority;    /* Static priority (SCHED_FIFO, SCHED_RR) */
    /* Remaining fields are for SCHED_DEADLINE */
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint64_t sched_period;
};

static int sched_setattr (pid_t pid, const struct sched_attr *attr, unsigned int flags) {
    return syscall (SYS_sched_setattr, pid, attr, flags);
}


int main(int argc, char **argv) {

    int policy, priority; 
    sscanf(argv[1], "%d", &policy);
    sscanf(argv[2], "%d", &priority);

    if(priority < 0 || priority > 99) {
        printf("priority value is not in range, please choose number between 0 to 99 \n");
        exit(1);
    }

    if(policy == 0 || policy == 3 || policy == 5)  
        priority = 0;  // param->sched_priority must be 0 for each of the above policies

    int ret_val = 0;
    struct sched_param param;
    param.sched_priority = priority;

    struct sched_attr attr = {
        .size = sizeof (attr),
        .sched_policy = SCHED_DEADLINE,
        .sched_runtime = 10 * 1000 * 1000,
        .sched_period = 2 * 1000 * 1000 * 1000,
        .sched_deadline = 11 * 1000 * 1000
    };

    if(policy != 6)
        ret_val = sched_setscheduler(0, policy, &param);
    else  // policy is SCHED_DEADLINE
        ret_val =  sched_setattr(0, &attr, 0);

    if(ret_val == -1) {  // sched_setattr command failed
        printf("An error occurred on sched_setscheduler command");
        exit(1);
    }

    while(1) {}

    return 0;
}