//
/* 748 - Dynamic Quad Tree */
// 
#include <cstdio>
#include <cmath>
#define maxn 1024

int n, k, base, res;
int q[11][maxn+1][maxn+1];

void go()
{
    res = 1;
    base = n;
    int seq = 0;

    while ( seq < k )
    {
        base /= 2;
        for (int i=0; i<base; i++)
            for (int j=0; j<base; j++)
            {
                int sum = q[seq][i*2][j*2] + q[seq][i*2+1][j*2] + q[seq][i*2][j*2+1] + q[seq][i*2+1][j*2+1];

                q[seq+1][i][j] = sum;

                if ( sum != 0 && sum != pow( 4, seq+1 ) )
                    res += 4;
            }

        seq++;
    }
}
void flip(int r, int c)
{
    int seq = 0;
    q[0][r][c] = !q[0][r][c];

    if ( r % 2 )
        r--;
    if ( c % 2 )
        c--;

    while ( seq < k )
    {
        int sum = q[seq][r][c] + q[seq][r+1][c] + q[seq][r][c+1] + q[seq][r+1][c+1];
        int *nx = &q[seq+1][r/2][c/2], ce = pow( 4, seq+1 );

        if ( sum == 0 || ( sum == ce ) )
            *nx = sum, res -= 4;
        else if ( ( sum == 1 && *nx == 0 ) 
                || ( sum == ce - 1 && *nx == ce ) )
            *nx = sum, res += 4;
        else
            break;

        r /= 2, c /= 2, seq++;
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

        for ( int i=0; i<n; i++ )
            for ( int j=0; j<n; j++ )
                scanf("%1d", &q[0][i][j]);

        go();

        int m, r, c;
        scanf("%d", &m);
        while ( m-- )
        {
            scanf("%d%d", &r, &c);

            flip(r-1, c-1);

            printf("%d\n", res);
        }
    }
    return 0;
}
