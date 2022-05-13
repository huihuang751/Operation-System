#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREADS 10 // Total Number of Threads

void Bridge(char arr[], int value);

int NorthValue = 0; // Number of North
int SouthValue = 0; // Number of South
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

/* North Farmer Thread */
void *NorthFarmer(void* arg){

	/* Critical Section Start */
	pthread_mutex_lock(&mutex1); 
	char arr[5] = "North";
	printf("%s Tunbridge #%d farmer can cross the bridge\n", arr, NorthValue);
	
	/* Entering Bridge */
	Bridge(arr,NorthValue); // Read File
	printf("%s Tunbridge #%d farmer has left the bridge\n", arr, NorthValue);
	NorthValue++; // Increase North Number
	/* Critical Section End */
	pthread_mutex_unlock(&mutex1);
	
	pthread_exit(0); // Exit Thread.
}

/* South Farmer Thread */
void *SouthFarmer(void* arg){

	/* Critical Section Start */
	pthread_mutex_lock(&mutex1);
	char arr[5] = "South";
	printf("%s Tunbridge #%d farmer can cross the bridge\n", arr, SouthValue);
	
	/* Entering Bridge */
	Bridge(arr,SouthValue); // Read File
	printf("%s Tunbridge #%d farmer has left the bridge\n", arr, SouthValue);
	SouthValue++; // Increase South Number
	/* Critical Section End */
	pthread_mutex_unlock(&mutex1);
	
	pthread_exit(0); // Exit Thread.
}

/* Read File Function */
void Bridge(char arr[], int value){ 

	srand(time(NULL));
   	printf("%s Tunbridge #%d is traveling on the bridge...\n", arr, value);
   	
   	/* Get Random number (0-3) and sleep up to 3 sec */
   	int randomnumber = rand() % 4;
   	sleep(randomnumber);
   	
   	printf("Sleep for %d seconds\n", randomnumber);
}


int main(){
	
	/* Initializing north and south threads */
	pthread_t North[THREADS];
	pthread_t South[THREADS];
	
	/* Initializing Mutex Lock */
	pthread_mutex_init(&mutex1,NULL);
	
	/* Creating threads */
	for(int i = 0; i < THREADS; i++){ 
		/* North Thread */
	    	int CreateFirst =  pthread_create(&North[i], NULL, NorthFarmer, NULL);
	    	/* South Thread */
	    	int CreateSecond = pthread_create(&South[i], NULL, SouthFarmer, NULL); 
	    	
	    	/* Thread Create Fails */
	   	if(CreateFirst != 0 || CreateSecond != 0){ 
	      	fprintf(stderr, "Thread Create Failed");
	      	return 1;
	   	}
   	}

	/* Joining threads */
   	for(int i = 0; i < THREADS; i++){
   		/* Joining North */
	      	int JoinFirst = pthread_join(North[i],NULL);
	      	/* Joining South */
	    	int JoinSecond = pthread_join(South[i],NULL);
	    	
	    	/* Thread Join Fails */
	     	if(JoinFirst != 0 || JoinSecond != 0){
			fprintf(stderr, "Thread Join Failed");
			return 1;
	      	}
   	}
   	
   	/* Destroying Mutex */
   	pthread_mutex_destroy(&mutex1);
   	return 0;
}
