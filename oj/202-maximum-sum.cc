// 
/* 202 - Maximum Sum */
//
// #dynamic programming
#include <cstdio>

int ma[103][103];
int dp[103];
int const INF = 0x3f3f3f3f;

int main() 
{
    int n;
    while ( scanf("%d", &n) != EOF )
    {
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
                scanf("%d", &ma[i][j]);

        }

        int max = -INF, sum = -INF;
        for (int i=0; i<n; ++i)
        {
            for (int s=0; s<n; ++s)
                dp[s] = 0;

            for (int j=i; j<n; ++j)
            {
                sum = 0;
                for (int k=0; k<n; ++k)
                    dp[k] += ma[j][k]; 

                int tmp = 0;
                for (int h=0; h<n; ++h)
                {
                    if (tmp > 0)
                        tmp += dp[h];
                    else
                        tmp = dp[h];

                    if ( tmp > sum )
                        sum = tmp;
                    printf("This time i is :%d, j is %d, h is %d, sum is: %d\n", i, j, h, sum);
                }
                puts("");

                if( sum > max )
                    max = sum;
            }
        }
        printf("%d\n", max);
    }

    return 0;
}
