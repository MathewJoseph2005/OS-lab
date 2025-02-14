#include<stdio.h>
int main() 
{
   int n;
   printf("enter number of processes: ");
   scanf("%d",&n);
   
   int bt[n],wt[n],tat[n];
   int total_wt=0,total_tat=0;
   
   for(int i=0;i<n;i++)
   {
      printf("enter burst time for process %d: ",i+1);
      scanf("%d",&bt[i]);
   }
   wt[0]=0;
   for(int i=1;i<n;i++)
   {
     wt[i]=bt[i-1]+wt[i-1];
   }
   for(int i=0;i<n;i++)
   {
     tat[i]=bt[i]+wt[i];
   }
   for(int i=0;i<n;i++)
   {
     total_wt+=wt[i];
     total_tat+=tat[i];
   }
   printf("\nGannt Chart: \n");
   printf(" ");
   for(int i=0;i<n;i++)
   {
     printf("  P%d\t",i+1);
   }
   printf("|\n");
   
   printf(" ");
   int time=0;
   for(int i=0;i<n+1;i++)
   {

   printf("%d\t",time);
    time+=bt[i];
   }
   printf("\n\n");
   printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
   for (int i=0;i<n;i++)
   {
     printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
   }
   printf("\nAverage Waiting Time:%.2f",(float)total_wt/n);
    printf("\nAverage Turn Around Time:%.2f",(float)total_tat/n);
   
   return 0;
  }
