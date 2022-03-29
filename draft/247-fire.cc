//
// 247 - Fire! (UVA 11624)
// 
#include <stdio.h>
#include <queue>

struct Coord
{
    int x, y;
};
struct joe
{
    int x, y, t;
};

int n, r, c;
int vist[1005][1005];
std::queue<Coord> qf;
std::queue<joe> q;

const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

bool isValid(int x, int y)
{
    return ( x > 0 && x <= r && y > 0 && y <= r ) ? true : false;
}

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
            if ( isValid(nx, ny) && !vist[nx][ny] )
            {
                qf.push( { nx, ny } );
                vist[nx][ny] = vist[f.x][f.y] + 1;
            }
        } 
    }
    return;
}
int jPath()
{
    while ( !q.empty() )
    {
        joe j = q.front();
        q.pop();

        if (j.x == 1 || j.x == r || j.y == 1 || j.y == c)
            return j.t;

        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = j.x + dir[i][0];
            ny = j.y + dir[i][1];

            if ( isValid(nx, ny) && j.t + 1 < vist[nx][ny] )
                q.push( { nx, ny, j.t + 1 } );
        } 
    }
    return 0;
}
void init()
{
    char m;
    scanf("%d%d", &r, &c);
    for (int i=1; i<=r; ++i)
        for (int j=1; j<=c; ++j)
        {
            scanf(" %c", &m );
            if (m == 'J')
            {
                q.push( { i, j, 1} );
                vist[i][j] = 0;
            }
            else if (m == 'F')
            {
                qf.push( { i, j } );
                vist[i][j] = 1;
            }
            else if ( m == '#' )
                vist[i][j] = -1;
            else
                vist[i][j] = 0;
        }
}

int main ()
{
    while ( ~scanf("%d", &n) )
        while (n--)
        {
            init();
            firePath();

            int time = jPath();
            while ( !q.empty() )
                q.pop();

            if ( !time )
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n", time);
        }
    return 0;
}
