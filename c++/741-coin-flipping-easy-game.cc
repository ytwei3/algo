//
/* 741 - Coin Flipping Easy Game */
// 
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, m, mx, cnt;
int a[101][11], b[11], row[101];

int count(int u)
{
    int num = 0;
    while ( u > 0 )
    {
        if ( u%2 )
            num++;
        u /= 2;
    }
    return 2*num < m ? m - num : num; 
}

int main ()
{
    for (int i=0; i<=10; i++)
        b[i] = 1 << i;

    while ( ~scanf("%d%d", &n, &m) )
    {
        mx = -1;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                scanf("%1d", &a[i][j]);

        for (int i=0; i<n; i++)
        {
            row[i] = 0;
            for (int j=m; j>=0; j--)
                if ( a[i][j] )
                    row[i] += pow(2, m-j-1);
        }

        for (int k=0; k<b[m]; k++)
        {
            cnt = 0;
            for (int i=0; i<n; i++)
                cnt += count( row[i]^k );

            if ( cnt > mx )
                mx = cnt;
        }
        printf("%d\n", mx);
    }
    return 0;
}
