#include<stdio.h>
void main()
{
    int n, i;
    printf("Enter the number of bits do you want to enter :");
    scanf("%d",&n);
    char binary[n+1];
    char ones[n+1];
    char twos[n+1];
    int carry=1;
    printf("Enter the binary number: ");
    scanf("%s", binary);
    printf("The one's complement of the number is: ");
    for(i=0; i<n; i++)
    {
        if(binary[i]=='0')
            ones[i]='1';
        else if(binary[i]=='1')
            ones[i]='0';
    }
    ones[n]='\0';
    printf("%s", ones);
    printf("The twos's complement of the number is: ");
    for(i=n; i>=0; i--)
    {
        if(ones[i]=='1' && carry==1)
        {
            twos[i]='0';
        }
        else if(ones[i]=='0' && carry==1)
        {
            twos[i]='1';
            carry=0;
        }
        else
        {
            twos[i]=ones[i];
        }
    }
    twos[n]='\0';
    printf("%s", twos);
}
