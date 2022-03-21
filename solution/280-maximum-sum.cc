// 280 - Maximum Sum (poj)
//
//
#include <stdio.h>
#include <algorithm>

int n, t;
int a[50003];
int f[50003][3], g[50003][3];
const int INF = 0x3f3f3f3f;

void init()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) // dp start from 1
        scanf("%d", &a[i]);

    for (int i=0; i<n; ++i)
        for (int j=1; j<3; ++j)
        {
            f[i][j] = -INF;
            g[i][j] = -INF;
        }

    f[1][1] = g[1][1] = a[1];
}
void dp ()
{
    for (int i=2; i<=n; ++i)
        for (int j=1; j<3; ++j)
        {
            f[i][j] = std::max( f[i-1][j] + a[i], g[i-1][j-1] + a[i]);
            g[i][j] = std::max( f[i][j], g[i-1][j]);
        }
}

int main ()
{
    scanf("%d", &t);
    while ( t-- )
    {
        init();
        dp();

        printf("%d\n", g[n][2]);
    }
    return 0;
}

