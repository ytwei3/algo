//
// 247 - Fire! (UVA 11624)
// 
#include <stdio.h>
#include <queue>
#define INF 0x3f3f3f3f

struct Coord
{
    int x, y;
};

int n, r, c, t;
char maze[1005][1005];
int vist[1005][1005];
std::queue<Coord> qj, qf;

const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void firePath()
{
    while ( !qf.empty() )
    {
        Coord p = qf.front();
        qf.pop();
        
        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = p.x + dir[i][0];
            ny = p.y + dir[i][1];

            if (nx >= 0 && nx <= r-1 && ny >= 0 && ny <= c-1 &&
                    maze[nx][ny] == '.' && vist[nx][ny] == 0 )
            {
                vist[nx][ny] = vist[p.x][p.y] + 1;
                qf.push( { nx, ny } );
            }
        }
    }
    return;
}
bool isEscaped()
{
    int s = qj.size();
    while ( !qj.empty() && s-- )
    {
        Coord j = qj.front();
        qj.pop();

        if (j.x == 0 || j.x == r-1 || j.y == 0 || j.y == c-1)
            return true;

        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = j.x + dir[i][0];
            ny = j.y + dir[i][1];

            if ( maze[nx][ny] == '.' && vist[nx][ny] < t )
                qj.push( { nx, ny } );
        }
        t++;
    }
    return false; 
}

int main ()
{
    while ( scanf("%d", &n) != -1 )
        while (n--)
        {
            scanf("%d%d", &r, &c);

            Coord joe;
            for (int i=0; i<r; ++i)
                for (int j=0; j<c; ++j)
                {
                    scanf(" %c", &maze[i][j]);
                    if (maze[i][j] == 'J')
                        joe = {i, j};
                    else if (maze[i][j] == 'F')
                        qj.push( { i, j } );
                }

            for (int i=0; i<r; ++i)
                for (int j=0; j<c; ++j)
                    if ( maze[i][j] == '.' )
                        vist[i][j] = 0;
                    else
                        vist[i][j] = INF;

            t = 0;
            firePath();

            if ( isEscaped() )
                printf("%d\n", ++t);
            else
                printf("IMPOSSIBLE\n");
        }
    return 0;
}
