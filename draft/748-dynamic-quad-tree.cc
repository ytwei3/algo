//
/* 748 - Dynamic Quad Tree */
// 
#include <stdio.h>
#include <vector>

int t, n, k, m, r, c;
int qa[1025][1025];

int main()
{
    scanf("%d", &t);
    while ( t-- )
    {
        n = 1;
        scanf("%d", &k);
        n <<= k;

        for ( int i=1; i<=n; i++ )
            for ( int j=1; j<=n; j++ )
                scanf("%1d", &qa[i][j]);

        scanf("%d", &m);
        while ( m-- )
        {
            scanf("%d%d", &r, &c);
            qa[r][c] =! qa[r][c];
            printf("%d", );
        }
    }
    return 0;
}
