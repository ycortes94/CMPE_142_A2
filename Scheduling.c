#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

//    /*FIFO*/
void FIFO(int *arr1, int *arr2, int *arr3)
{
   int y = sizeof(arr2)/2;
   int waitTime[100], turnaroundTime[100], startTime[100], endTime[100], avgWaitTime = 0, avgTurnaroundTime = 0, i, j;
   int temp1, temp2, temp3;

   waitTime[0] = 0; //waiting time for first process is 0

   //sorting arrival time in ascending order using selection sort
   for(i = 0; i < y; i++) {
      for(j=i+1; j < y; j++) {
         if(arr2[j]< arr2[i])
         {
            temp1 = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp1;

            temp2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp2;

            temp3 = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp3;
         }
      }
   }

   //calculating waiting time
   for (i = 0; i < y; i++)
   {
      waitTime[i] = 0;
      for (j = 0; j <= i; j++){
         waitTime[i] += arr2[j];
      }
   }
   printf("FIFO Algorithm");
   printf("\nProcess\t\tArrival Time\tTurnAround Time\tStart Time\tEnd Time");
   //calculating turnaround time
   for (i = 0; i < y; i++)
   {
      if(i > 0) {
         startTime[i] = endTime[i-1];
         endTime[i] = startTime[i]+arr3[i];
         turnaroundTime[i] = endTime[i] - startTime[i];
      } else
      {
         startTime[i] = arr2[i];
         endTime[i] = startTime[i] + arr3[i];
         turnaroundTime[i] = endTime[i] - startTime[i];
      }
      printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t%d\t\t%d", arr1[i], waitTime[i], turnaroundTime[i], startTime[i], endTime[i]);
      avgWaitTime += waitTime[i];
      avgTurnaroundTime += turnaroundTime[i];
   }
}
/*SJF*/
int SJF(int *arr1, int *arr2, int *arr3)
{
   int y = sizeof(arr2)/2;
   int waitTime[100], turnaroundTime[100], startTime[100], endTime[100], avgWaitTime = 0, avgTurnaroundTime = 0, i, j;
   int pos1, pos2, pos3, temp1, temp2, temp3;

   //sorting duration in ascending order using selection sort
   for(i = 0; i < y; i++) {
      for(j=i+1; j < y; j++) {
         if(arr3[j] < arr3[i])
         {
            temp1 = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp1;

            temp2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp2;

            temp3 = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp3;
         }
      }
   }
   waitTime[0] = 0; //waiting time for first process will be zero

   //calculate waiting time
   for (i = 0; i < y; i++)
   {
      waitTime[i] = 0;
      for (j = 0; j <= i; j++)
         waitTime[i] += arr2[j];
   }
   printf("\n\nSJF Algorithm");
   printf("\nProcess\t\tArrival Time\tTurnAround Time\tStart Time\tEnd Time");
   for (i = 0; i < y; i++)
   {
      if(i > 0) {
         startTime[i] = endTime[i-1];
         // printf("%d\n", endTime[i-1]);
         endTime[i] = startTime[i]+arr3[i];
         turnaroundTime[i] = endTime[i] - startTime[i];
      } else
      {
         startTime[i] = waitTime[i];
         endTime[i] = startTime[i] + arr3[i];
         turnaroundTime[i] = endTime[i] - startTime[i];
      }
      avgWaitTime += waitTime[i];
      avgTurnaroundTime += turnaroundTime[i];
      printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t%d\t\t%d", arr1[i], waitTime[i], turnaroundTime[i], startTime[i], endTime[i]);
   }
   return 0;
}
//    /*BJF*/
int BJF(int *arr1, int *arr2, int *arr3)
{
   int y = sizeof(arr2)/2;
   int waitTime[100], turnaroundTime[100], startTime[100], endTime[100], avgWaitTime = 0, avgTurnaroundTime = 0, i, j;
   int pos1, pos2, pos3, temp1, temp2, temp3;

   //sorting duration in descending order using selection sort
   for(i = 0; i < y; i++) {
      for(j=i+1; j < y; j++) {
         if(arr3[j] > arr3[i])
         {
            temp1 = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp1;

            temp2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp2;

            temp3 = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp3;
         }
      }
   }
   waitTime[0] = 0; //waiting time for first process will be zero
   //calculate waiting time
   for (i = 1; i < y; i++)
   {
      waitTime[i] = 0;
      for (j = 0; j <= i; j++)
         waitTime[i] += arr2[j];
   }
   printf("\n\nBJF Algorithm");
   printf("\nProcess\t\tArrival Time\tTurnAround Time\tStart Time\tEnd Time");
   for (i = 0; i < y; i++)
   {
      if(i > 0) {
         startTime[i] = endTime[i-1];
         // printf("%d\n", endTime[i-1]);
         endTime[i] = startTime[i]+arr3[i];
         turnaroundTime[i] = endTime[i] - startTime[i];
      } else
      {
         startTime[i] = waitTime[i];
         endTime[i] = startTime[i] + arr3[i];
         turnaroundTime[i] = endTime[i] - startTime[i];
      }
      avgWaitTime += waitTime[i];
      avgTurnaroundTime += turnaroundTime[i];
      printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t%d\t\t%d", arr1[i], waitTime[i], turnaroundTime[i], startTime[i], endTime[i]);
   }
   return 0;
}

//    /*STCF*/
int STCF(int *arr1, int *arr2, int *arr3)
{
   int y = sizeof(arr2)/2;
   int waitTime[100], turnaroundTime[100], startTime[100], endTime[100], avgWaitTime = 0, avgTurnaroundTime = 0, i, j;
   int temp[100];
   int temp1, temp2, temp3;
   int smallest, count = 0, time;
   double end;

   //sorting duration in ascending order using selection sort
   for(i = 0; i < y; i++) {
      for(j=i+1; j < y; j++) {
         if(arr3[j] < arr3[i])
         {
            temp1 = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp1;

            temp2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp2;

            temp3 = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp3;
         }
      }
   }
      for(i = 0; i < y; i++)
      {
            temp[i] = arr3[i];
      }
      arr3[9] = 9999;  
      for (time = 0; count != y; time++) {
         smallest = 9;
         for (i = 0; i < y; i++)
         {
            if(arr2[i] <= time && arr3[i] < arr3[smallest] && arr3[i] > 0)
            {
               smallest = i;
            }
         }
         arr3[smallest]--;
         if(arr3[smallest] ==  0)
         {
            count++;
            end = time + 1;
            endTime[smallest] = end;
            waitTime[smallest] = end - arr2[smallest] - temp[smallest];
            turnaroundTime[smallest] = end - arr2[smallest];
         }
      }
      printf("\n\nSTCF Algorithm");
      printf("\nProcess \t Duration \t Arrival \t Waiting \t Turnaround \t Completion");
      for(i=1; i < y; i++)
      {
         printf("\nP[%d] \t   %d \t %d\t\t%d   \t\t%d\t\t%d",arr1[i],temp[i],arr2[i],waitTime[i],turnaroundTime[i],endTime[i]); 
      }
      return 0;
}

//    /*RR*/
int RR(int *arr1, int *arr2, int *arr3)
{
   int i, flag, temp, runningP, timeQuantum = 2, j = 0, current;
   int totalT = 0, totalTurnT = 0, avgWaitT, avgTurnT = 0, avgResponseT = 0;
   int startTime[101], endTime[100], remainTime[100], turnAroundT[100], waitTime[100], pQueue[100], pFlag[100], gantt[10000];
   int n = sizeof(arr2)/2;
   bool done = 1;

   //sort arrival time in ascending order
   for(i = 0; i < n; i++) {
      for(j = i+1; j < n; j++) {
         if(arr2[i] > arr2[j]) {
            temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
            
            temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;

            temp = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp;
         }
      }
         pQueue[i] = 0;
         pFlag[i] = 0;
         remainTime[i] = arr3[i];
   }

   //calculate the start time
   for(i = 0; i < n; i++) {
      if(startTime[i] + timeQuantum < arr2[i+1]) {
         startTime[i+1] = arr2[i+1];
         //remainTime[i] = 0;
      } else {
         startTime[i+1] = startTime[i] + timeQuantum;
         //remainTime[i] -= timeQuantum;
      }
   }
   
   for(i = 0; i < n; i++)
      remainTime[i] = arr3[i];

   current = 0;

   // calculate waitTime
   while(done == 1) {
      for(i = 0; i < n; i++) {
         if(remainTime[i] > 0) {
            done = 0;
            if(remainTime[i] > timeQuantum) {
               current += timeQuantum;
               remainTime[i] -= timeQuantum;
            }
         } else {
            current += remainTime[i];
            waitTime[i] = current - arr3[i];
            remainTime[i] = 0;
         }
      }
      if(done == 1)
         break;
   }

   //calculate turnaroundTime
   for(i = 0; i < n; i++)
      turnAroundT[i] = arr3[i] + waitTime[i];
   
   //calculate averageTime
   for(i = 0; i < n; i++) {
      totalT += waitTime[i];
      totalTurnT += turnAroundT[i];
   }
   printf("\n\nRR Algorithm");
   printf("\nProcess\t\tArrival Time\tRunning Time\tTurn Around Time\tWait Time\n");
   for(i=0;i<n;i++)
       printf("P[%d]   \t      %d      \t     %d     \t       %d       \t   %d   \n", arr1[i] , arr2[i], arr3[i], turnAroundT[i], waitTime[i]); 
   return 0;
}

int main(int argc, char **argv)
{
   static const char filename[] = "jobs.dat";
   FILE *fp = fopen(filename, "r");
   if (fp != NULL)
   {
      int integers[100];
      int i = 0;
      int num;
      int *jobIDs; //JOB_ID
      int *arrivalTime; //Arrival_Time
      int *duration; //Duration
      int len=100;

      jobIDs = (int*)calloc(len,sizeof(int));
      arrivalTime = (int*)calloc(len,sizeof(int));
      duration = (int*)calloc(len,sizeof(int));

      //Scan file for all ints excluding whitespaces and new lines
      while (fscanf(fp, "%d", &num) != EOF)
      {
         integers[i] = num;
         i++;

      }
      int x,y,z = 0;

      /*Take the first int of each line and put it in JOB_ID array*/
      for (int a = 0; a < i; a++)
      {
         *(jobIDs + x) = integers[a];
         a=a+2;
         x++;
      }
      /*Take the second int of each line and put it in Arrival_Time array*/
      for (int a = 1; a < i; a++)
      {
         arrivalTime[y] = integers[a];
         a=a+2;
         y++;
      }
      /*Take the third int of each line and put it in Duration array*/
      for (int a = 2; a < i; a++)
      {
         duration[z] = integers[a];
         a=a+2;
         z++;
      }
      fclose(fp);

      //Calling each scheduling algorithm
      FIFO(jobIDs, arrivalTime, duration);
      SJF(jobIDs, arrivalTime, duration);
      BJF(jobIDs, arrivalTime, duration);
      STCF(jobIDs, arrivalTime, duration);
      RR(jobIDs, arrivalTime, duration);

      
      free(jobIDs);
      free(arrivalTime);
      free(duration);
   }
   else
   {
      perror(filename);
   }
   return 0;
}