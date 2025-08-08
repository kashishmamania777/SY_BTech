//binary to decimal
#include<stdio.h>
#include<math.h>
void main()
{
    int i, rem, n=0;
    long bin;
    printf("Enter a number in binary number system: ");
    scanf("%ld", &bin);
    for(i=0; bin!=0; ++i)
    {
        rem=bin%10;
        bin=bin/10;
        n=n+(rem)*(pow(2,i));
    }
    printf("The decimal number is: %d", n);
}
