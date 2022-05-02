//
/* 748 - Dynamic Quad Tree */
// 
#include <cstdio>
#include <vector>
#define maxn 1024

struct node
{
    int val;
    node *nw, *sw, *se, *ne;
} qa[maxn+1][maxn+1];

int n, k, base, offset;

void build()
{
    int it = 1;
    while ( 1 )
    {
        while ( it < n )
        {

        }
        if ( it * 2 > base )
            break;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d", &k);
        n = 1 << k;

        for ( int i=1; i<=n; i++ )
            for ( int j=1; j<=n; j++ )
                scanf("%1d", &qa[i][j].val);

        base = , offset = 1;
        build();

        int m, r, c;
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
