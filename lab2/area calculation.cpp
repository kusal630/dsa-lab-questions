//To take the user input of type of shape and calculating its area
#include <cstdio>
#include <cstdlib>
int main()
{
    int *option;
    option=(int*)malloc(sizeof(int));
    printf("Select a option from below for which you want to calculate area\n");
    printf("1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n");
    scanf("%d",option);

    if(*option==1)                                              //Area of the square
    {
        int *area,*side;
        area=(int*)malloc(sizeof(int));
        side=(int*)malloc(sizeof(int));
        printf("Enter the side of the square\n");
        scanf("%d",side);
        *area=(*side)*(*side);
        printf("Area of the square is %d\n",*area);
    }
    else if(*option==2)                                         //Area of the cube
    {
        int *side,*area;
        area=(int*)malloc(sizeof(int));
        side=(int*)malloc(sizeof(int));
        printf("Enter the side of cube\n");
        scanf("%d",side);
        *area=6*(*side)*(*side);
        printf("Area of the cube is %d\n",*area);            
    }
    else if(*option==3)                                        //Area of the rectangle
    {
        int *length,*breadth,*area;
        length=(int*)malloc(sizeof(int));
        breadth=(int*)malloc(sizeof(int));
        area=(int*)malloc(sizeof(int));
        printf("Enter the length and breadth of the rectangle\n");
        scanf("%d %d",length,breadth);
        *area=(*length)*(*breadth);
        printf("Area of the rectangle is %d\n",*area);}
    else if(*option==4)                                        //Area of the cuboid
    {
        int *length,*width,*heigth,*area;
        area=(int*)malloc(sizeof(int));
        length=(int*)malloc(sizeof(int));
        width=(int*)malloc(sizeof(int));
        heigth=(int*)malloc(sizeof(int));
        printf("Enter the length,width and the heigth of the cuboid\n");
        scanf("%d %d %d",length,width,heigth);
        *area=2*((*length)*(*width)+(*width)*(*heigth)+(*heigth)*(*length));
        printf("Area of the cuboid is %d\n",*area);
    }
    else if(*option==5)                                       //To exit the code
    {
        printf("COde is exiting.....\n");
        printf("Code exited\n");
        exit(0);
    } 
    else                                                         
    {printf("Enter the valid option from above given menu\n");}
    return 0;}
