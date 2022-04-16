//
/* 758 - Fibonacci Sequence */
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, cnt, bucket; 
long long q, u, v, w, len;
long long b[101][10000001], s[11];

void init()
{
    scanf("%d%lld", &n, &q);
    for ( int i=2; i<=11; i++ )
        s[i] = 0;

    u = v = len = 1;
    s[1] = 2;
    b[1][0] = 1 , b[1][1] = 1;
    while ( pow( bucket, len) < q )
        len++;
}

int main()
{
    bucket = 10;

    scanf("%d", &t);
    while ( t-- )
    {
        init();

        for ( int i=2; i<n; i++ )
        {
            w = ( u + v ) % q;
            u = v, v = w;

            cnt = 1;
            while ( pow(bucket, cnt) < w )
                cnt++;

            b[cnt][ s[cnt] ] = w, s[cnt]++;
        }

        for ( int i=1; i<=len; i++ )
            if ( s[i] > 1 )
                sort( b[i], b[i] + s[i] );

        int seq = 1;
        long long sum = 0;
        for ( int i=1; i<=len; i++ )
            for (int j=0; j<s[i]; j++)
                sum += b[i][j]%q * seq%q, seq++;

        printf("%lld\n", sum % q );
    }
    return 0;
}
