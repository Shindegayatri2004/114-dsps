#include<stdio.h>
int main()
{
	int i,n,j,temp,a[10];
	int comp=0,pass=0;
	printf("enter array size:");
	scanf("%d",&n);
	printf("enter array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		}
	}
	printf("sorted array:");
	for(i=0;i<n;i++)
	{
	printf("%d\n",a[i]);
	}
	comp=n*(n-1)/2;
	printf("No of comparison in selection sort are %d\n",comp);
	printf("No of pass  in selection sort are %d\n",n-1);
	return 0;
}



