//
/* 741 - Coin Flipping Easy Game */
// 
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> r, c;
int grid1[101][11], grid2[101][11];

int flip1()
{
    int cond1, cond2, ans = 0;
    while ( 1 )
    {
        cond1 = cond2 = 1;
        c.clear();
        int cnt;
        for ( int i=0; i<n; i++ )
        {
            cnt = 0;
            for ( int j=0; j<m; j++ )
                !grid1[i][j] ? cnt++ : cnt--;
            r.push_back(cnt);
        }

        for (int i=0; i<r.size(); i++)
            // only difference here
            if ( r[i] > 0 || ( r[i] == 0 && grid1[i][0] == 1) )
            {
                cond1 = 0;
                for (int j=0; j<m; j++ )
                    grid1[i][j] =! grid1[i][j];
            }

        r.clear();
        for ( int j=0; j<m; j++ )
        {
            cnt = 0;
            for ( int i=0; i<n; i++ )
                !grid1[i][j] ? cnt++ : cnt--;
            c.push_back(cnt);
        }

        for (int j=0; j<c.size(); j++)
            // only difference here
            if ( c[j] > 0 || ( c[j] == 0 && grid1[j][0] == 1) )
            {
                cond2 = 0;
                for (int i=0; i<n; i++ )
                    grid1[i][j] =! grid1[i][j];
            }

        if ( cond1 + cond2 == 2 )
            break;
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++ )
            if ( grid1[i][j] )
                ans++;

    return ans;
}
int flip2()
{
    int cond1, cond2, ans = 0;
    while ( 1 )
    {
        cond1 = cond2 = 1;
        c.clear();
        int cnt;
        for ( int i=0; i<n; i++ )
        {
            cnt = 0;
            for ( int j=0; j<m; j++ )
                !grid2[i][j] ? cnt++ : cnt--;
            r.push_back(cnt);
        }

        for (int i=0; i<r.size(); i++)
            // only difference here
            if ( r[i] > 0 || ( r[i] == 0 && grid2[i][0] == 0) )
            {
                cond1 = 0;
                for (int j=0; j<m; j++ )
                    grid2[i][j] =! grid2[i][j];
            }

        r.clear();
        for ( int j=0; j<m; j++ )
        {
            cnt = 0;
            for ( int i=0; i<n; i++ )
                !grid2[i][j] ? cnt++ : cnt--;
            c.push_back(cnt);
        }

        for (int j=0; j<c.size(); j++)
            // only difference here
            if ( c[j] > 0 || ( r[j] == 0 && grid2[j][0] == 0) )
            {
                cond2 = 0;
                for (int i=0; i<n; i++ )
                    grid2[i][j] =! grid2[i][j];
            }

        if ( cond1 + cond2 == 2 )
            break;
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++ )
            if ( grid2[i][j] )
                ans++;

    return ans;
}

int main()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++ )
                scanf("%1d", &grid1[i][j]);

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++ )
                grid2[i][j] = grid1[i][j];

        printf("%d\n", max(flip1(), flip2()) );
    }
    return 0;
}

