# Operation System Homework 1
## Programming Problems 3.22
In Exercise 3.14, the child process must output the sequence of numbers generated from the algorithm specified by the Collatz conjecture because the parent and child processes have their own copies of the data. 

Another approach to redesign this program is to establish a shared-memory object between the parent and child processes. This technique allows the child to write the contents of the sequence to the shared-memory object. The parent can then output the sequence when the child completes. 

This program will be structured using *POSIX* shared memory as described in Sec.3.5.1. The parent process will progress though the following steps: 

- Establish the shared-memory object (shm_open(), ftruncate(), and mmap())
- Create the child process and wait for it to terminate
- Output the contents of shared memory
- Remove the shared-memory object 
 
**One area of concern with cooperating process involves synchronization issues.** In this exercise, the parent and child processes must be coordinated so that the parent does not output the sequence until the child finishes execution. These two processes will be synchronized using the **wait()** system call: **the parent process will invoke wait(), which will suspend until the child process exits.**

## Workflow
![](https://i.imgur.com/M8rAUzH.png)


1. Create shared memory object
2. Create child process and wait.
3. User input number in child process.
4. Child process calculates Collatz conjecture and stores result in shared memory.
5. Parent print Collatz conjecture from shared memory after child process completes calculation.
6. Parent process unlink shared memory and terminate process.
## Result
![](https://i.imgur.com/NL14VPO.png)
