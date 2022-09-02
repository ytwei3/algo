#include <cstdio>
#include <cmath>
using namespace std;

// Extended Euclid algo
long long gcd(long long p, long long q, long long *x, long long *y)
{
    long long m, n, g;

    if ( q > p )
        return gcd(q, p , y, x);

    if ( q == 0 ) {
        *x = 1;
        *y = 0;
        return p;
    }

    g = gcd(q, p % q, &m, &n);

    *x = n;
    *y = ( m - floor(p/q)*n );

    return g;
}

int main()
{
    long long a, b, x, y, d;
    while ( ~scanf("%lld%lld", &a, &b) ) {
        d = gcd(a, b, &x, &y);
        printf("%lld %lld %lld\n", x, y, d);
    }
    return 0;
}
