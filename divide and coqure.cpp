#include<stdio.h>
int main()
{
	int m,n,s,a[20],temp,i,j;
	printf("enter the noof elements");
	scanf("%d",&s);
 	printf("enter the element::");
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Min = %d",a[0]);
	printf("Max = %d",a[s-1]);
}
