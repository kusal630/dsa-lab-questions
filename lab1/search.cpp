#include <cstdio>
#include <stdlib.h>
#include "sort.h"// contains sorting functions
int main()
{int size,key=0,target,num;
    printf("Enter the size of array\n");
scanf("%d",&size);
int arr[size];
for(int i=0;i<size;++i)
{
    printf("Enter the value of arr[%d]\n",i+1);
    scanf("%d",&arr[i]);}
    printf("Enter the element to search\n");
    scanf("%d",&target);
    printf("Select the type of search you want or we can exit\n");
    printf("1.Linear search\n2.Binary search\n3.Exit\n");
    scanf("%d",&num);
    if(num==1)
{for(int i=0;i<size;++i)//linear search
{
    if(arr[i]==target)
    {key=1;
    break;}
}}
else if(num==2)
{bubblesort(arr,size);//sorting
int low=0,high=size-1;//binary search
while (low <= high)
{int mid=low+(high-low)/2;
if(arr[mid]==target)
{key=1;
break;}
else if(arr[mid]<target)
{low=mid+1;}
else if(arr[mid]>target)
{high=mid-1;}}}
else
{printf("Code is exiting.....\n");
printf("Code exited\n");
exit(0);}
if(key==1)
{printf("Element is found\n");}
else
{printf("Element is not found\n");}
return 0;}
