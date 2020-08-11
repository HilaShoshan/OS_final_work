<div dir="rtl" lang="he">

# How to run my code

### 1. use the attached makefile to compile my code

### 2. choose the parameters of policy and priority that you want:
    # policy options: 
      SCHED_OTHER ------ 0
      SCHED_FIFO ------- 1
      SCHED_RR --------- 2
      SCHED_BATCH ------ 3
      SCHED_IDLE ------- 5
      SCHED_DEADLINE --- 6
    # priority options: 
      0 - for  "normal" (i.e., non-real-time) scheduling policies [SCHED_OTHER, SCHED_BATCH, SCHED_IDLE]
      1-99 - for real-time policies [SCHED_FIFO, SCHED_RR]
    # notes: 
      - If you select a value different from 0 in SCHED that are not 1 or 2, my code will correct it automatically - it will ask to set the priority to 0
      - If you select a value that is not in range [1,99] for SCHED_FIFO or SCHED_RR, you will be notified and the code will exit.
      
### 3. run the code on one terminal 
    # using command: $ sudo ./set_policy policy priority
    
## and if you want to check if it worked ... 
   
### 4. open a new terminal and run a command to check the PID of the ./set policy process
    (for example tou can use "top" command)

### 5. run the command: $ chrt -p pid 
    # you'll get an output that tells you: current policy and current priority
    # check if the values match those you chose before

</div>
