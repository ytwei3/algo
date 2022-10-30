// 548 - Magic Binary Dot Card
//
//
#include <stdio.h>

long long a, b, res, up, down;
int itr;

long long ar[65];

void recursive(long long a, long long b)
{
    itr = 0;
    while ( b >= ar[itr] )
        itr++;

    up = ar[itr], down = ar[itr - 1];

    if ( a < down )
    {
        res += up - 1;
        printf("%lld\n", res );

        return ;
    }
    else
    {
        a -= down, b -= down;
        res += down;
        recursive(a, b);
    }
}

int main()
{
    ar[0] = 1;
    for (int i=1; i<=64; ++i)
        ar[i] = ar[i-1] << 1;

    while ( scanf("%lld%lld", &a, &b) != EOF )
    {
        res = 0;
        if (a == b)
            printf("%lld\n", a);
        else
            recursive(a, b);
    }

    return 0;
}
