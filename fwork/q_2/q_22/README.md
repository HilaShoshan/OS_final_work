<div dir="rtl" lang="he">

# How to run my code

! for this run you'll need two different terminals

### 1. complie my code using the attached make file
     # thats will complie both client and server
    
### 2. in the first terminal: 
### - run the server (it will enter an infinite loop)

### 3. in the second terminal: 
### - run some command to find out the pid of server process, for example:
     $ ps -xj
### - choose two parameters: 
    (1) signal_num - the number of the signal you want to send:
    * 2 for SIGINT
    * 10 for SIGUSR1
    (2) signal_count - the number of signals to send (from client to server)
### - run the client with the chosen parameters, like that: 
      $ ./client server_pid signal_num signal_count
     
### 4. on server's terminal you can see a printing of number of SIGINTs that arrived to server
    # !!! note that this number is probably lower from the signal_count you've chose 
    # the reason is that standard signals do not enter to queue

</div>
