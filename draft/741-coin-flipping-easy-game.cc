//
/* 741 - Coin Flipping Easy Game */
//
#include <stdio.h>

int n, m;
long long ans;
char grid[101][11];

int main()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        ans = 0;
        for (int i=0; i<n; i++)
            scanf("%s", grid[i]);

        printf("%lld", ans);
    }
    return 0;
}
