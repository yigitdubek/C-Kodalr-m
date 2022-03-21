#include<stdio.h>
#include<math.h>
int exponential( int x,int y);
int sumofexponential(int base,int exp);



int main()
{
int base,exponent,sum,value;

printf("Enter base:");  scanf("%d",&base);
printf("enter exponent:");  scanf("%d",&exponent);

value=exponential(base,exponent);
printf("Tre result of Power(%d,%d) is %d\n",base,exponent,value);
sum=sumofexponential(base,exponent);
printf("The result of sum( %d,%d) is %d\n",base,exponent,sum);
}

int exponential( int x,int y)
{
    
    if(y == 0)
    {
        return 1;
    }

return x * exponential(x, y-1);
}

int sumofexponential(int base,int exp)
{

    if(exp == 1)
    {
        return 1;
    }

    int sum = pow(base, exp);

return sum + sumofexponential(base, exp-1);
}


