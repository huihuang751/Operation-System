# Operation System Homework 3
## Programming projects Chap.7 Banker's Algorithm 
* Write a **multithreaded** program that implements the *banker’s algorithm* discussed in Section 7.5.3. This assignment combines three topics: (1) `multithreading` (2) `preventing race conditions` (3) `deadlock avoidance`.
* Create *n* customer threads that request and release resources from the bank. The customers will continually loop, requesting and then releasing random numbers of resources. The banker will grant a request if it satisfies the safety algorithm.
* Since multiple threads will concurrently access shared data, access must be controlled through mutex locks to prevent race conditions.
* You should invoke your program by passing the number of resources of each type on the command line.

## Workflow


## Result

## Refs
https://github.com/ahmedwael19/CIE302---Project2---BankerAlgorithm

## Team Members
110054835 陳宥融：協助實作code

110054817 黃慧：討論架構及內容，協助製作document

107440020 楊宗翰：討論架構及內容

110598111 謝成彥：討論架構及內容
