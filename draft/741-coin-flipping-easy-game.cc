//
/* 741 - Coin Flipping Easy Game */
// 
// May need Dynamic Programming 
#include <stdio.h>
#include <vector>
using namespace std;

int n, m, ans;
int grid[101][11];

vector<int> r, c;

void getR()
{
    int cnt;
    for ( int i=0; i<n; i++ )
    {
        cnt = 0;
        for ( int j=0; j<m; j++ )
            !grid[i][j] ? cnt++ : cnt--;
        r.push_back(cnt);
    }
}
void getC()
{
    int cnt;
    for ( int j=0; j<m; j++ )
    {
        cnt = 0;
        for ( int i=0; i<n; i++ )
            !grid[i][j] ? cnt++ : cnt--;
        c.push_back(cnt);
    }
}

int main()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        ans = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++ )
                scanf("%1d", &grid[i][j]);

        int cond1, cond2;
        while ( 1 )
        {
            cond1 = cond2 = 1;
            c.clear(), getR();

            for( auto i: r )
                printf("%d ", i);
            printf("\n");

            for (int i=0; i<r.size(); i++)
                if ( r[i] > 0 || ( r[i] == 0 && grid[i][0] == 0) )
                {
                    cond1 = 0;
                    for (int j=0; j<m; j++ )
                        grid[i][j] =! grid[i][j];
                }
            printf("\n");
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<m; j++ )
                    printf("%d", grid[i][j]);
                printf("\n");
            }



            r.clear(), getC();

            for( auto i: c )
                printf("%d ", i);
            printf("\n");

            for (int j=0; j<c.size(); j++)
                if ( c[j] > 0 || ( c[j] == 0 && grid[0][j] == 0) )
                {
                    cond2 = 0;
                    for (int i=0; i<n; i++ )
                        grid[i][j] =! grid[i][j];
                }

            printf("\n");
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<m; j++ )
                    printf("%d", grid[i][j]);
                printf("\n");
            }

            if ( cond1 + cond2 == 2 )
                break;
        }

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++ )
                if ( grid[i][j] )
                    ans++;

        printf("%d\n", ans);
    }
    return 0;
}
