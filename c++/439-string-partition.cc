//
/* 439 - String Partition */
//
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[201];
int len;
long long dp[201], sum;
const int MAX = 0x7fffffff;

int main ()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%s", str);
        len = strlen(str);

        memset(dp, 0, sizeof(dp));

        for (int i=1; i<=len; i++)
            for (int j=1; j<=i && j<=10; j++)
            {
                sum = 0;
                for (int k=0; k<j; k++)
                    sum = sum*10 + (str[i-j+k] - '0');
                if ( sum <= MAX )
                    dp[i] = max(dp[i], dp[i-j] + sum);
            }
        printf("%lld\n", dp[len]);
    }
    return 0;
}

