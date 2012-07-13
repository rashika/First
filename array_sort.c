#include <stdio.h>
#include<string.h>

void sort(int *a , int n,int size)
{
	int i , j , min , temp;
	int *pTemp;
	for(i = 0 ; i < n ; i++)
	{
		min = i;
		for(j = i+1 ; j < n ; j++)
		{
			if(*(a + min) > *(a +j))
			{
				temp = j;
				j = min; 
				min = temp;
			}
		}
		memcpy(pTemp,a+i,size);
		memcpy(a+i,a+min,size);
		memcpy(a+min,pTemp,size);
	}

}

int main()
{
	int a[] = {3,4,1,2,5};
	sort(a,5,4);
	int i;
	for(i = 0;i<5 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}



