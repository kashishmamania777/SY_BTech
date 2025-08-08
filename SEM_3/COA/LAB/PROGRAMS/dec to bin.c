//decimal to binary
#include<stdio.h>
void main()
{
    int n, i=1, rem;
    long bin=0;
    printf("Enter a number in decimal number system: ");
    scanf("%d", &n);
    while(n!=0)
    {
        rem=n%2;
        n=n/2;
        bin=bin+rem*i;
        i=i*10;
    }
    printf("The binary number is: %ld", bin);
}
