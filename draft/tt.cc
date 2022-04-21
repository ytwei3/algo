//
/* 758 - Fibonacci Sequence */
//
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, cnt, bucket; 
long long q, u, v, w;

int main()
{
    bucket = 10;

    scanf("%d", &t);
    while ( t-- )
    {
        vector<long long> b[1001];
        scanf("%d%lld", &n, &q);

        u = 1, v = 1;
        b[1].push_back(1), b[1].push_back(1);

        int len = 1;
        while ( pow( bucket, len) < q )
            len++;

        for ( int i=2; i<n; i++ )
        {
            w = ( u + v ) % q;
            u = v, v = w;

            cnt = 1;
            while ( pow(bucket, cnt) < w )
                cnt++;
            b[cnt].push_back(w);
        }

       // for ( int i=1; i<=len; i++ )
       //     for ( auto j : b[i] )
       //         printf("%lld ", j);
       // puts("");

        for ( int i=1; i<=len; i++ )
            sort( b[i].begin(), b[i].end() );

        int s = 1;
        long long sum = 0;
        for ( int i=1; i<=len; i++ )
            for ( auto j : b[i] )
                sum += j%q * s%q, s++;

        printf("%lld\n", sum % q );
    }
    return 0;
}
