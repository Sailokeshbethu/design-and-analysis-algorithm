#include<stdio.h>
void floyd(int a[4][4],int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
		printf("all pairs shortest path is:\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
	}
		int main()
		{
			int cost[4][4]={{0,9,4,3},{8,0,2,6},{5,2,0,2},{1,3,4,0}};
			int n=4;
			floyd(cost,n);
		}

