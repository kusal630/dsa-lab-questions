#include <cstdio>
#include <stdlib.h>
void insertionsort(int arr[],int size);
void selectionsort(int arr[],int size);
void bubblesort(int arr[],int size);
int main()
{   
   int size,key;
   printf("Enter the size of array\n");
   scanf("%d",&size);
   int arr[size];
   printf("Enter the elements of array\n");
for(int i=0;i<size;++i)
{
   printf("Enter the value of arr[%d]\n",i+1);
   scanf("%d",&arr[i]);}
   printf("Select the one type of sorting from below or we can exit\n");
   printf("1.Insertion sort\n2.Selection sort\n3.Bubble sort\n4.Exit\n");
   scanf("%d",&key);
if(key==1)
{printf("Sorting by insertion sort\n");
    insertionsort(arr,size);}
else if(key==2)
{
    printf("Sorting by selection sort\n");
    selectionsort(arr,size);}
else if (key==3)
{
    printf("Sorting by bubblesort\n");
    bubblesort(arr,size);}
else{
    printf("Exiting the code....\nexited from code\n");
    exit(0);}
printf("Sorted array is\n");
for(int i=0;i<size;++i)
{
    printf("%d ",arr[i]);}
return 0;}
void insertionsort(int arr[],int size)//insertion sort
{
    for(int i=1;i<size;++i)
{
    int key=arr[i];
    int j=i-1;
while (j>=0&&arr[j]>key)
{
   arr[j+1]=arr[j];
   j--;}
   arr[j+1]=key;}}
void selectionsort(int arr[],int size)//selection sort
{
    for(int i=0;i<size-1;++i)
{
    int miniIndex=i;
    for(int j=i+1;j<size;++j)
{
    if(arr[j]<arr[miniIndex])
{
    miniIndex=j;}}
   int temp=arr[miniIndex];
   arr[miniIndex]=arr[i];
   arr[i]=temp;}}
void bubblesort(int arr[],int size)//bubble sort
{
    for(int i=0;i<size-1;++i)
{
    for(int j=0;j<size-1-i;++j)
{
    if(arr[j]>arr[j+1])
{
    int temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;}}}}
