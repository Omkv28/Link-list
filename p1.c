#include<stdio.h>
int main()
{
    int arr[10];
    int i,b,c=0;
    printf("enter the array elements");
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched");
    scanf("%d",b);
    for(i=0;i<10;i++)
    {
        if(arr[i]==b)
        {
            c=1;
        }
    }
     if(c==1)
     {
         printf("elements india");

     }
     else
     {
         printf("PKMKB");
     }
     return 0;
}
