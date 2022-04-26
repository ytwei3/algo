//
// 215 - Jack Straws
//
// #disjoint set
#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
    int x, y;
};
struct straw
{
    point a, b;
} line[13];

int n, d[13][13];

int cross(point a, point b, point c)
{
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
int isIntersected(point a, point b, point c, point d)
{
    // step 1
    if ( max(c.x, d.x) < min(a.x, b.x) || max(c.y, d.y) < min(a.y, b.y) ||
         max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y) )
        return 0;

    // step 2
    if ( cross(a, b, c) * cross(a, b, d) > 0 ||
         cross(c, d, a) * cross(c, d, b) > 0)
        return 0;

    return 1;
}
void init()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d%d%d%d", &line[i].a.x, &line[i].a.y, &line[i].b.x, &line[i].b.y);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if ( i == j )
                d[i][j] = 1;
            else
                d[i][j] = 0;

}
void build()
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if ( isIntersected(line[i].a, line[i].b, line[j].a, line[j].b) )
                d[j][i] = d[i][j] = 1;
}
void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && d[i][k] && d[k][j] && !d[i][j])
                    d[i][j] = 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
    {
        init();

        build();

        floyd();

        int a, b;
        while ( ~scanf("%d%d", &a, &b) && ( a || b ) )
        {
            if ( d[a-1][b-1] )
                puts("CONNECTED");
            else
                puts("NOT CONNECTED");
        }
        if (t)
            putchar('\n');
    }
    return 0;
}
