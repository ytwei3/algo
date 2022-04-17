//
/* 758 - Fibonacci Sequence */
//
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t, n, cnt, bucket; 
long long q, u, v, w, len;
long long b[5000001], si[7];

/*
size of bucket 1 :9
size of bucket 2 :20
size of bucket 3 :645
size of bucket 4 :30645
size of bucket 5 :1531607
size of bucket 6 :3437074
*/

int main()
{
    bucket = 50;

    int b1[101]

    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d%lld", &n, &q);

        len = 6;
        u = v = 1;
        b[0] = 1 , b[1] = 1;

        for ( int i=2; i<n; i++ )
        {
            w = ( u + v ) % q;
            u = v, v = w;

            cnt = 1;
            while ( pow(bucket, cnt) < w )
                cnt++;

        }

        for ( int i=1; i<=len; i++ )
            if ( si[i] > 1 )
                sort( b[i], b[i] + si[i] );

        int seq = 1;
        long long sum = 0;
        for ( int i=1; i<=len; i++ )
            for (int j=0; j<si[i]; j++)
                sum += b[i][j%q * seq%q, seq++;

        printf("%lld\n", sum % q );
    }
    return 0;
}
