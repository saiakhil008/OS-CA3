#include<stdio.h>
main()
{
   int p[]={1,2,3,4};
   int b[]={6,8,7,3};
   int ct[4];
   int t1,t2;
   printf("Given processes\n\n");
   printf("process    Bursttime");
   for(int i=0;i<4;i++)
   printf("\n%d          %d",p[i],b[i]);
   printf("\n\ncalculation of completion time and order of processes according to SJF:\n");
   for(int j=0;j<3;j++)
   {
       for(int i=0;i<3;i++)
       {
       if(b[i]>b[i+1])
       {
           t1=p[i];
           p[i]=p[i+1];
           p[i+1]=t1;
           t2=b[i];
           b[i]=b[i+1];
           b[i+1]=t2;
       }
       }
   }
   ct[0]=b[0];
   for(int i=1;i<4;i++)
   {
       ct[i]=ct[i-1]+b[i];
   }
   printf("\nprocess    Bursttime     completiontime");
   for(int i=0;i<4;i++)
   printf("\n%d          %d             %d",p[i],b[i],ct[i]);
   printf("\nGann chart....\n\n");
   printf("t\n");
   for(int i=0;i<4;i++)
   {
       printf("|%d",p[i]);
       for(int j=0;j<b[i];j++)
       printf(" ");


   }
    printf("|\n");
   for(int j=0;j<ct[3]+8;j++)
    printf("-");
    printf("\n0");
    for(int i=0;i<4;i++){

    for(int j=0;j<b[i]+1;j++)
    {
        printf(" ");
    }
    printf("%d",ct[i]);}

   //scanf("%d%d",&p[i],&b[i]);

   //printf("%d",p[i]);
   return 0;
}
