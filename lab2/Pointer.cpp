//To check the number is a armstrong number,palindrome,perfect number or to exit program
#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
    int *num,*option;
 num=(int*)malloc(sizeof(int));
 option=(int*)malloc(sizeof(int));
 printf("Enter the number\n");
 scanf("%d",num);
 printf("Select a option from below\n");
 printf("1.Palindrome\n2.Armstrong number\n3.Perfect number\n4.Exit\n");//Menu
 scanf("%d",option);
 if(*option==1)                                                   //To check number is a palindrome
  {
    int *remainder,*revnum,*temp;
    remainder=(int*)malloc(sizeof(int));
    revnum=(int*)malloc(sizeof(int));
    temp=(int*)malloc(sizeof(int));
    *revnum=0;
    *temp=*num;
     while(*temp!=0)
      {
        *remainder=(*temp)%10;
        *revnum=(*revnum)*10+*remainder;
         (*temp)/=10;
         }
          printf("Reversed number is %d\n",*revnum);
    if (*revnum==*num)
     {
        printf("Number is a palindrome\n");
        }
    else 
     {
        printf("Number is not a palindrome\n");
        }}
 else if (*option==2)                                           //To check number is armstrong number
 {
    int *remainder,*sum,*temp,*digits;
    remainder=(int*)malloc(sizeof(int));
    sum=(int*)malloc(sizeof(int));
    temp=(int*)malloc(sizeof(int));
    digits=(int*)malloc(sizeof(int));
    *sum=0;
    *digits=0;
    *temp=*num;
    while((*temp)!=0)
     {
        ++(*digits);
       (*temp)/=10;
       }
        printf("Number of digits is %d\n",*digits);
        *temp=*num;
       while((*temp)!=0)
     {
        *remainder=(*temp)%10;
       *sum+=pow(*remainder,*digits);
        (*temp)/=10;
        }
        printf("Sum is %d\n",*sum);
    if(*sum==*num)
     {
        printf("Number is a armstrong number\n");
        }
    else
     {
        printf("Number is not a arm strong number\n");
        }}
 else if(*option==3)                                           //To check the number is perfect number
 {
    int *remainder,*sum,*temp,*i;
    remainder=(int*)malloc(sizeof(int));
    sum=(int*)malloc(sizeof(int));
    temp=(int*)malloc(sizeof(int));
    *sum=0;
    *temp=*num;
    for ((*i)=1;(*i)<=*num/2;++(*i))
     {
        if((*num)%(*i)==0)
       {
        (*sum)+=(*i);
        }}
    if((*sum)==(*num))
     {
        printf("Number is a perfect number\n");
        }
    else
     {
        printf("Number is not a perfect number\n");
        }}
 else if(*option==4)                                         //To exit the code
 {
    printf("Code is exiting.....\n");
    printf("Code is exited\n");
    exit(0);
  }
 else
 {
    printf("Enter the valid option from above given menu\n");
    }
 return 0;
 }