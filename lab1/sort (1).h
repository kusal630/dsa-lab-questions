void insertionsort(int arr[],int k)//insertion sort
{
    for(int i=1;i<k;++i)
{
    int key=arr[i];
    int j=i-1;
while (j>=0&&arr[j]>key)
{
   arr[j+1]=arr[j];
   j--;}
   arr[j+1]=key;}}
void selectionsort(int arr[],int k)//selection sort
{
    for(int i=0;i<k-1;++i)
{
    int miniIndex=i;
    for(int j=i+1;j<k;++j)
{
    if(arr[j]<arr[miniIndex])
{
    miniIndex=j;}}
   int temp=arr[miniIndex];
   arr[miniIndex]=arr[i];
   arr[i]=temp;}}
void bubblesort(int arr[],int k)//bubble sort
{
    for(int i=0;i<k-1;++i)
{
    for(int j=0;j<k-1-i;++j)
{
    if(arr[j]>arr[j+1])
{
    int temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;}}}}