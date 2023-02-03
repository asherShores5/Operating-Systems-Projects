//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Authors: Asher Shores & Philip Varkey
//Assignment: Assignment 2: Monitors and Semaphores
//Instructor: CST-315, Operating Systems Lecture & Lab
//Date: February 13, 2022,
//This is my own work
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>


//define functions so driver code can be shown at top of file
void waitTime();
void TATime();
void avgTime();

// Driver code
int main()
{

   //id's for process
   int processes[] = {1, 2, 3};
   int n = sizeof processes / sizeof processes[0];

   // Burst time
   int burst_time[] = {15, 4, 6};

   // Time quantum
   int quantum = 2;
   avgTime(processes, n, burst_time, quantum);
   return 0;
}


// calculates wait time for a process
void waitTime(int processes[], int n,
           int bt[], int wt[], int quantum)
{
   //store burst times int bt[]
   int rem_bt[n];
   for (int i = 0 ; i < n ; i++)
       rem_bt[i] = bt[i];

   int t = 0; // Current time

   // round robin manner process traversal
   while (1)
   {
       bool done = true;

       // iterate through the process
       for (int i = 0 ; i < n; i++)
       {

           // Cont. for burst time of > 0
           if (rem_bt[i] > 0)
           {
               done = false;
               // Process pending

               if (rem_bt[i] > quantum)
               {

                   // Increment t for time elapsed
                   t += quantum;

                   // Decrement the burst time of the process
                   rem_bt[i] -= quantum;
               }

               // If burst time is <= q, final cycle
               else
               {
                  // Increment t for time elapsed
                   t = t + rem_bt[i];

                   // Waiting time is time - burst time
                   wt[i] = t - bt[i];

                   rem_bt[i] = 0;
               }
           }
       }

       // If all processes are done
       if (done == true)
       break;
   }
}

// Calculate turn around time
void TATime(int processes[], int n,
                       int bt[], int wt[], int tat[])
{
   // calculating turn around time
   for (int i = 0; i < n ; i++)
       tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void avgTime(int processes[], int n, int bt[],
                                   int quantum)
{
   int wt[n], tat[n], total_wt = 0, total_tat = 0;

   // call bacl to wait time for all processes
   waitTime(processes, n, bt, wt, quantum);

   // call back for turn around
   TATime(processes, n, bt, wt, tat);

   // Write details of processes
   printf( "Processes Burst time, Waiting time, Turn around time\n");

   // Calculate total w time and ta time
   for (int i=0; i<n; i++)
   {
       total_wt = total_wt + wt[i];
       total_tat = total_tat + tat[i];
       printf(" %d \t\t %d \t %d \t\t %d",i+1, bt[i] ,wt[i] ,tat[i]);
       printf("\n");
   }

   printf("Mean waiting time = %f"
       ,(float)total_wt / (float)n);
   printf("\nMean turn around time = %f"
       ,(float)total_tat / (float)n);
}
