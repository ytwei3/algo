//
// 247 - Fire! (UVA 11624)
// 
#include <stdio.h>
#include <queue>

struct Coord
{
    int x, y, t, j;
} joe;

int n, r, c;
int vist[1005][1005];
std::queue<Coord> q;

const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void init()
{
    while ( !q.empty() )
        q.pop();

    char m;
    scanf("%d%d", &r, &c);
    for (int i=0; i<r; ++i)
        for (int j=0; j<c; ++j)
        {
            scanf(" %c", &m);
            if ( m == '#')
                vist[i][j] = 1;
            else if ( m == 'F' )
            {
                vist[i][j] = 1;
                q.push( { i, j, 1, 0 } );
            }
            else if ( m == 'J' )
            {
                vist[i][j] = 1;
                joe = { i, j, 1, 1 };
            }
            else
                vist[i][j] = 0;
        }
}
bool isValid( int border, Coord now )
{
    if ( border )
        return ( !now.x || !now.y || now.x == r-1 || now.y == c-1 ) ? 1 : 0;
    else
        return ( now.x >= 0 && now.y >= 0 && now.x < r && now.y < c ) ? 1 : 0;
}
int bfs()
{
    q.push(joe);
    while ( !q.empty() )
    {
        Coord p = q.front();
        q.pop();

        if ( isValid(1, p) && p.j )
            return p.t;

        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = p.x + dir[i][0];
            ny = p.y + dir[i][1];
            Coord next = { nx, ny, p.t + 1,  p.j };

            if ( isValid(0, next) && !vist[nx][ny] )
            {
                vist[nx][ny] = 1;
                q.push( next );
            }
        } 
    }
    return -1;
}

int main ()
{
    while ( ~scanf("%d", &n) )
        while (n--)
        {
            init();
            int time = -1;
            time = bfs();

            if ( time == -1 )
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n", time);
        }
    return 0;
}
