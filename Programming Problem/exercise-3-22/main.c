#include<unistd.h>        /*For ftruncate*/
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<sys/mman.h>      /* For mmap*/
#include<fcntl.h>         /* For O_CREAT, O_RDWR */
int main(){
    const char *shm_name = "Shared";
    int shm_fd = shm_open(shm_name, O_CREAT|O_RDWR, 0);  /* opend a shared memory*/
    if(shm_fd==-1)
        printf("Error in shm_open");
    
    int ftrunc_res = ftruncate(shm_fd, 64);    /* 512 is length of memory */
    
    if(ftrunc_res==-1)
        printf("Error in ftruncate");
    
    int *sh_mm = mmap(0, 64, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0); /* project into memory, PROT_READ: write, MAP_SHARED: shared doc in memory  */
    if(sh_mm==MAP_FAILED)
        printf("Error in mmap");
    
    /* Create child process */
    pid_t pid=fork();
    
    if(pid<0)
    {
        printf("Fork failed \n");
    }
    else if(pid==0)
    {
        /* Child process*/
        printf("Child process created \nPlease enter a positive integer: ");
        int n;
        scanf("%d",&n);
        
        while (n < 0){
            printf("You input a negative number. Please input positive number: \n");
            scanf("%d", &n);
            if (n > 0){
                break;
            }
        }
        
        sh_mm[0]=n;
        int i=1;
        while(n>1){
            if(n%2==0){
                sh_mm[i]=n/2;     // Stored in shared memory
                n=n/2;
                i++;
            }
            else{
                sh_mm[i]=3*n+1;   // Stored in shared memory
                n=3*n+1;
                i++;
            }
        }
        sh_mm[i]=-1;
        return 0;
    }
    else
    {
        /* Parent process */
        wait(NULL);
        printf("Child process complete \n Parent process shows Collatz conjecture: \n");
        
        int i=0;
        while(sh_mm[i]!=-1){
            printf("%d ",sh_mm[i]);
            i++;
        }
        int res=shm_unlink(shm_name); // unlink shared memory
        if(res==0)
            printf("\nParent process shared memory unlinked \n");
        else
            printf("Error while unlinking shared memory \n");
    }
    return 0;
}
