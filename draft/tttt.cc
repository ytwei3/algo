#include <stdio.h>
const int s = 3005;

int n;
long long sum;
int m[s][s], in[s][s];


int main()
{
    while ( scanf("%d", &n) != EOF )
    {
        // init
        sum = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                scanf("%1d", &in[i][j]);

        for (int i=0; i<n; ++i)
            m[i][n] = 0;

        // convert 
        for (int i=0; i<n; ++i)
            for (int j=n-1; j>=0; --j)
                if ( !in[i][j] )
                    m[i][j] = 1 + m[i][j+1];

        // counting
        for (int j=0; j<n; j++)
        {
            int mst[s]; // monotonic stack
            long long t = 0;
     
            int i = n-1;
            mst[0] = 0;

            while ( i>=0 )
            {
                if ( !mst[0] || mst[ mst[0] ] <= m[i][j])
                {
                    t += m[i][j];
                    mst[ ++mst[0] ] = m[i--][j];
                    sum += t;
                    continue;
                }

                while ( mst[0] && mst[ mst[0] ] > m[i][j] )
                    t -= mst[ mst[0]-- ];

                mst[ ++mst[0] ] = m[i][j]; //push
                t += m[i][j];

                sum += t + ( n-i - mst[0] ) * mst[ mst[0] ];
                i--;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}

