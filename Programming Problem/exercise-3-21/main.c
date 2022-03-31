//
//  main.c
//  EX_3-14
//
//  Created by 黃慧 on 2022/3/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t pid;
    
    /* fork a child process*/
    pid = fork();
    
    if (pid < 0){
        /* error occured*/
        fprintf(stderr, "Fork failed");
        return 1;
    }
    
    else if (pid == 0){
        /* child process*/
        int num;
        printf("Executing child process\n");
        printf("Please input positive number: \n");
        scanf("%d", &num);
        while (num < 0){
            printf("You input a negative number. Please input positive number: \n");
            scanf("%d", &num);
            if (num > 0){
                break;
            }
        }
        printf("%d ", num);
        while (num > 1){
            if(num % 2 ==0){
                num = num / 2;
            }
            else{
                num = 3 * num + 1;
            }
            printf("%d ", num);
        }
        printf("\nChild process complete\n");
    }
    
    else {
        /* parent process*/
        wait(NULL);
        printf("Parent process wait done!");
    }
    // system("pause");
    return 0;
}
