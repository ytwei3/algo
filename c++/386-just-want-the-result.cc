//
/* 386 - Just Want the Result */
//
#include <cstdio>
#include <cmath>

long long binpow(long long a, long long k, long long n)
{
    long long res = 1;
    while ( k > 0 )
    {
        if ( k & 1 )
            res = res * a % n;
        a = a%n * a%n;
        k >>= 1;
    }
    return res % n;
}
int main ()
{
    long long a, k, n;
    while ( ~scanf("%lld%lld%lld", &a, &k, &n) )
        printf("%lld\n", binpow(a, k, n) );

    return 0;
}

