// 98 - Credit Check
//
//
#include <stdio.h>

int t, al;

void isVaild(int s)
{
    if (s % 10 == 0)
        printf("Valid\n");
    else
        printf("Invalid\n");
}
void convert(int a)
{
    if (a/10 == 0 && a%10 == 0)
        return ;

    al += a%10;
    a /= 10;
    convert(a);
}


int main ()
{
    while ( scanf("%d", &t) != EOF )
    {
        while ( t-- )
        {
            int number = 8, sum = 0;
            int a, b;
            while ( number-- )
            {
                al = 0;
                scanf("%1d", &a);
                scanf("%1d", &b);

                convert( 2*a );
                sum += al + b;
            }
            isVaild(sum);
        }
    }

    return 0;
}
