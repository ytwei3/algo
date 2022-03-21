// 267 - Avoid The Lakes
//
//
#include <stdio.h>
#include <vector>

int n, m, k, cnt;
int farm[105][105];
int vist[105][105];
std::vector<int> q;

void find(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || farm[x][y] == 0)
        return ;
    else 
    {
        cnt++;
        farm[x][y] = 0;

        find(x-1, y);
        find(x+1, y);
        find(x, y-1);
        find(x, y+1);
    }
}

int main ()
{
    while ( scanf("%d%d%d", &n, &m, &k) != EOF )
    {
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
                farm[i][j] = 0;

        int r, c;
        for (int i=0; i<k; ++i)
        {
            scanf("%d%d", &r, &c);
            farm[r][c] = 1;
            q.push_back(r), q.push_back(c);
        }

        int ans = -1;
        while ( !q.empty() )
        {
            c = q.back(), q.pop_back();
            r = q.back(), q.pop_back();

            cnt = 0;
            find(r, c);
            
            if (cnt > ans)
                ans = cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
