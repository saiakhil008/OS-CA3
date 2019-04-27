#include<stdio.h>
int main()
{
      int i, n, time = 0, x, counter = 0, tq,j;
	  int wt = 0, tat = 0,pos,z,p[10],pr[10], at[10], bt[10], t[10],b,avg_wt=0;
	  printf("\nEnter Number of Processes:");
	  scanf("%d", &n);
	  x = n;
      for(i = 0; i < n; i++)
      {
	    p[i]=i+1;
	    pr[i]=0;
            printf("\nProcess[%d]\n", i + 1);
            printf("Enter Arrival Time and Burst Time:\t");
            scanf("%d%d", &at[i],&bt[i]);
            t[i] = bt[i];
      }
      printf("\nEnter Time Quantum:");
      scanf("%d", &tq);
      printf("\nProcess          Burst Time         Turnaround Time          Waiting Time         Priority\n");
      for(time = 0, i = 0; x != 0;)
      {
		    for(z=0;z<n;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<n;j++)
			{
			    if(pr[j]<pr[pos])
				pos=j;
			}
		temp1=pr[z];
		pr[z]=pr[pos];
		pr[pos]=temp1;
			temp1=bt[z];
			bt[z]=bt[pos];
			bt[pos]=temp1;
            temp1=at[z];
            at[z]=at[pos];
			at[pos]=temp1;
			temp1=p[z];
            p[z]=p[pos];
			p[pos]=temp1;
			temp1=t[z];
            t[z]=t[pos];
			t[pos]=temp1;
		    }
		{
		}
			if(t[i] <= tq && t[i] > 0)
            {
                  time = time + t[i];
                  t[i] = 0;
                  counter = 1;
            }
			else if(t[i] > 0)
            {
                  t[i] = t[i] - tq;
                  time = time + tq;
            }
	for(b=0;b<n;b++)
    {
			if(b==i)
			pr[b]+=1;
			else
			pr[b]+=2;
    }
    if(t[i] == 0 && counter == 1)
    {
                  x--;
                  printf("\n%d                          %d                     %d                  %d                      %d", p[i], bt[i], time - at[i], time - at[i] - bt[i],pr[i]);
                  wt = wt + time - at[i] - bt[i];
                  tat = tat + time - at[i];
                  counter = 0;
    }
    if(i == n - 1)
                  i = 0;
    else if(at[i + 1] <= time)
                  i++;
    else
                  i = 0;
    }
    for(i=0;i<n;i++)
        avg_wt=avg_wt+time - at[i] - bt[i];
    printf("\n Average Waiting Time:%d",avg_wt);
    return 0;
}
