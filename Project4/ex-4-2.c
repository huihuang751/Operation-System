#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 2  // number of thread

int array[] = {10, 9, 15, 7, 16, 5, 4,  8, 2, 13};  // target array

/* Structure for array high and low index */
typedef struct Arr {
    int low;
    int high;
} ArrayIndex;

/* Merge function */
void merge(int low, int high)
{
        int mid = (low+high)/2;
        int left = low;
        int right = mid+1;
	int n = (high - low + 1);
        int array_b[n];
        int i, cur = 0;

        while(left <= mid && right <= high) {
                if (array[left] > array[right]){
                        array_b[cur++] = array[right++];
		}
		else{
                        array_b[cur++] = array[left++];
        	}
	}

        while(left <= mid){ 
		array_b[cur++] = array[left++];
	}
        while(right <= high){
		array_b[cur++] = array[right++];
	}
        for (i = 0; i < (high-low+1) ; i++){
		array[low+i] = array_b[i];
	}
}

void * mergesort(void *a)
{
        ArrayIndex *pa = (ArrayIndex *)a;
        int mid = (pa->low + pa->high)/2;

	/* Create sublist structure*/
        ArrayIndex aIndex[N];
	/* First sublist */
        aIndex[0].low = pa->low;
        aIndex[0].high = mid;
	/*Second sublist */
        aIndex[1].low = mid+1;
        aIndex[1].high = pa->high;

        /* An array of threads to joined upon */
        pthread_t thread[N];

        if (pa->low >= pa->high) return 0;

        int i;
        for(i = 0; i < N; i++){
	       /* Create 2 thread and call mergesort */
		pthread_create(&thread[i], NULL, mergesort, &aIndex[i]);
	};
	for(i = 0; i < N; i++){
	       /* Wait for the thread exit */
		pthread_join(thread[i], NULL);
	}

	/* Call Merge funtion */
        merge(pa->low, pa->high);

        pthread_exit(NULL);
        return 0;
}

int main()
{	
	/* Initialize array index structure */
        ArrayIndex ai;
        ai.low = 0;
        ai.high = sizeof(array)/sizeof(array[0])-1;
        
        /* Print unsorted array */
	printf("Unsorted array: \n");
	for (int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	};
	printf("\n");
	
	/* Thread identifier */
	pthread_t thread;
	/* Create thread */
        pthread_create(&thread, NULL, mergesort, &ai);
        /* Wait for thread to exit */
        pthread_join(thread, NULL);
	
	/* Print sorted array */
        printf("Sorted array: \n");
        for (int i = 0; i < 10; i++) {
		printf ("%d ", array[i]);
	};
	printf("\n");

        return 0;
}
