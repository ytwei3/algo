//
// 247 - Fire! (UVA 11624)
// 
#include <stdio.h>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f

struct Coord
{
    int x, y;
};

int n, r, c, t;
char maze[1005][1005];
int vist[1005][1005];
int jv[1005][1005];
std::queue<Coord> qj, qf;

const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void firePath()
{
    while ( !qf.empty() )
    {
        Coord f = qf.front();
        qf.pop();
        
        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = f.x + dir[i][0];
            ny = f.y + dir[i][1];

            if (nx > 0 && nx <= r && ny > 0 && ny <= c && vist[nx][ny] == 0 )
            {
                vist[nx][ny] = vist[f.x][f.y] + 1;
                qf.push( { nx, ny } );
            }
        } 
    }
    return;
}
void jPath()
{
    while ( !qj.empty() )
    {
        Coord j = qj.front();
        qj.pop();

        if (j.x == 1 || j.x == r || j.y == 1 || j.y == c)
            t = std::min(t, jv[j.x][j.y]);

        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = j.x + dir[i][0];
            ny = j.y + dir[i][1];

            if ( nx > 0 && nx <= r && ny > 0 && ny <= c &&
                    jv[j.x][j.y] < vist[nx][ny] )
            {
                qj.push( { nx, ny } );
                jv[nx][ny] = jv[j.x][j.y] + 1;
            }
        } 
    }
}

int main ()
{
    while ( ~scanf("%d", &n) )
        while (n--)
        {
            scanf("%d%d", &r, &c);

            Coord joe;
            for (int i=1; i<=r; ++i)
                for (int j=1; j<=c; ++j)
                {
                    scanf(" %c", &maze[i][j]);
                    if (maze[i][j] == 'J')
                    {
                        joe = {i, j};
                        jv[joe.x][joe.y] = 1;
                    }
                    else if (maze[i][j] == 'F')
                        qf.push( { i, j } );
                }

            for (int i=1; i<=r; ++i)
                for (int j=1; j<=c; ++j)
                    if ( maze[i][j] == '.' || maze[i][j] == 'J')
                        vist[i][j] = 0;
                    else if ( maze[i][j] == 'F')
                        vist[i][j] = 1;
                    else
                        vist[i][j] = INF;

            t = INF;
            firePath();
            jPath();
            for (int i=1; i<=r; ++i)
            {
                for (int j=1; j<=c; ++j)
                    if (jv[i][j] < 100)
                        printf("%d", jv[i][j]);
                    else
                        printf("#");
                printf("\n");
            }

            if ( ++t )
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n", t);
        }
    return 0;
}
