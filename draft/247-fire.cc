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

    scanf("%d%d", &r, &c);

    char m;
    // init vist
    for (int i=0; i<r; ++i)
        for (int j=0; j<c; ++j)
        {
            scanf(" %c", &m);
            if ( m == '#')
                vist[i][j] = 1;
            else if ( m == 'F' )
            {
                vist[i][j] = 1;
                q.push( { i, j, 0, 0 } );
            }
            else if ( m == 'J' )
            {
                vist[i][j] = 1;
                joe = { i, j, 0, 1 };
            }
            else
                vist[i][j] = 0;
        }
}
bool isBorder( Coord now )
{
    return ( now.x == 0 || now.y == 0 || now.x == r-1 || now.y == c-1 ) ? 1 : 0;
}
bool isValid( Coord now )
{
    return ( now.x >= 0 || now.y >= 0 || now.x <= r-1 || now.y <= c-1 ) ? 1 : 0;
}
int bfs()
{
    q.push(joe);
    while ( !q.empty() )
    {
        Coord p = q.front();
        vist[p.x][p.y] = 1;
        q.pop();

        if ( isBorder(p) && p.j )
            return p.t;

        // next step
        int nx, ny;
        for (int i=0; i<4; ++i)
        {
            nx = p.x + dir[i][0];
            ny = p.y + dir[i][1];
            Coord next = { nx, ny, p.t + 1, p.j };

            if ( isValid(next) && !vist[nx][ny] )
                q.push( next );
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
            for (int i=0; i<r; ++i)
            {
                for (int j=0; j<c; ++j)
                    printf("%d", vist[i][j]);

                printf("\n");
            }
            int time = bfs();

            if ( time == -1 )
                printf("IMPOSSIBLE\n");
            else
                printf("%d\n", time+1);
        }
    return 0;
}
