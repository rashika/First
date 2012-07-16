#include <stdio.h>
#include<string.h>

int compare(const void *p1 , const void *p2)
{
	if(*(int* const*)p1 > *(int * const*)p2)
		return 1;
	return -1;
}

void sort(void *a , int n , int size , int(*compar)(const void *,const void *))
{
	int i , j , min , temp;
	void *pTemp = (void*)malloc(size);
	for(i = 0 ; i < n ; i++)
	{
		min = i;
		for(j = i+1 ; j < n ; j++)
		{
			if(compar(a+min*size,a+j*size) == 1)
			{
				temp = j;
				j = min; 
				min = temp;
			}
		}
		memcpy(pTemp,a+i*size,size);
		memcpy(a+i*size,a+min*size,size);
		memcpy(a+min*size,pTemp,size);
	}

}

int main()
{
	int a[] = {3,4,1,2,5};
	sort(a,5,4,compare);
	int i;
	for(i = 0;i<5 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}



