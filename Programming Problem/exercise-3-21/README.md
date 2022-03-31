# Operation System Homework 1
## Programming Problems 3.14
The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
- if n is even:
$$n= n/2 \space$$
- if n is odd:
$$n= 3*n+1$$

The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1.
For example, if n=35, the sequence is: 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1. 

- Write a C program using the **fork()** system call that generates this sequence in the child process. The starting number will be provided from the command line. 

- Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence.

- Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. 

- Perform necessary error checking to ensure that a positive integer is passed on the command line. 


## Workflow
![](https://i.imgur.com/PeRkW8O.png)

1. main function calls fork().
2. Parent process wait until child process complete execution.
3. User input number in child process
    i. If number negative, pring error message then require user input a number again.
    ii. If number positve, executes the calculation and print result.
3. After child process complete execution, parent process merge then finish program.
## Result
### Input positive number
![](https://i.imgur.com/IrEHs4O.png)
### Input negative number
![](https://i.imgur.com/MTy6vRr.png)






