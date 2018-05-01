#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int i,a,j;
    long int t,n[10000],square=0,sum=0,result,sum1;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
        {scanf("%ld",&n[i]);}
    for(i=0;i<t;i++)
        {a=n[i];
         for(j=1;j<=a;j++){square=square+j*j;sum=sum+j;}
        sum1=sum*sum;
        result=-(square-sum1);
        printf("%ld\n",result);
    sum=0;square=0;}
    return 0;
}
