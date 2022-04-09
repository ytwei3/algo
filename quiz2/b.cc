//
// B 
//
#include <stdio.h>
//#include <iostream>
//#include <array>
//#include <string>
#include <queue>
#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <cmath>
#define endl "\n"
#define ll long long
//ios::sync_with_stdio(false);
//cin.tie(nullptr);
using namespace std;

struct point
{
    int x, y;
};

int t, r, c, ar[26], vist[33][33];
char g[33][33], ch = 'a';
const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
queue<point> q;

void bfs()
{
    while ( !q.empty() )
    {
        point p = q.front();
        q.pop();

        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = p.x + dir[i][0];
            ny = p.y + dir[i][1];

            if ( nx >= 0 && nx < r && ny >= 0 && ny < c
                    && !vist[nx][ny]
                    && g[nx][ny] == g[p.x][p.y])
            {
                vist[nx][ny] = 1;
                q.push( {nx, ny} );
            }
        } 
    }
}

int main()
{
    scanf("%d", &t);
    for (int time = 1; time<=t; t++)
    {
        // init
        scanf("%d%d", &r, &c);
        for (int i=0; i<r; ++i)
            scanf("%s", g[i]);

        for (int i=0; i<33; ++i)
            for (int j=0; j<33; ++j)
                vist[i][i] = 0;

        for (int i=0; i<26; ++i)
            ar[i] = 0;

        // bfs
        for (int i=0; i<r; ++i)
            for (int j=0; j<c; ++j)
                if ( !vist[i][j] )
                {
                    ar[ g[i][j] - ch ]++;
                    q.push({i, j});
                    vist[i][j] = 1;
                    bfs();
                }

        // put
        printf("Plate #%d\n", time);
        for (int i=0; i<26; ++i)
            if ( ar[i] )
                printf("%c: %d\n", ch + i, ar[i]);
    }
    return 0;
}
