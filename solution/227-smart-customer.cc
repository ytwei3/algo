
//
/* 272 - Smart Customer */
//
#include <cstdio>
#include <algorithm>
using namespace std;

double dp[105];
char buf[501];

int main ()
{
    double p;
    int m, n, c = 1;
    while ( ~scanf("%lf%d", &p, &m) )
    {
        for (int i=0; i<=100; i++)
            dp[i] = i * p;

        while ( m-- )
        {
            scanf("%d%lf", &n, &p );
            dp[n] = min(dp[n], p);
        }

        if ( m != 0 )
            for (int i=2; i<=100; i++)
                for (int j=1; j <= i/2; j++)
                    dp[i] = min(dp[i], dp[j] + dp[i-j]);

        getchar();
        gets(buf);

        int offset;
        char *data = buf;
        printf("Case %d:\n", c++);
        while ( sscanf(data, " %d%n", &n, &offset) == 1 )
        {
            data += offset;
            printf("Buy %d for $%.2f\n",n ,dp[n]);
            if (*data == '\0' || *(data+1) == '\0' )
                break;
        }
    }
    return 0;
}

