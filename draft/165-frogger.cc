//
/* 165 - Frogger */
//
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct point
{
    int x, y;
} p[205];

int n, vist[201];
double w[201][201], dist[201];

double dis(point a, point b)
{
    return sqrt( 1.0*(a.x-b.x)*(a.x-b.x) + 1.0*(a.y-b.y)*(a.y-b.y) );
}

int main ()
{
    int time = 1;
    while ( ~scanf("%d", &n) && n )
    {
        for (int i=0; i<n; i++)
            scanf("%d%d", &p[i].x, &p[i].y );

        for (int i=1; i<n; i++)
            for (int j=0; j<n; j++)
                w[i][j] = dis(p[i], p[j]);

        for (int j=0; j<n; j++)
            dist[j] = dis(p[0], p[j]);

        for (int i=0; i<=201; ++i)
            vist[i] = 0;
        vist[0] = 1;

        while ( !vist[1] )
        {
            int pos;
            double shortest = 0x3f3f3f3f;
            for (int i=1; i<n; i++)
                if ( !vist[i] && dist[i] < shortest )
                    shortest = dist[i], pos = i;

            vist[pos] = 1;
            for (int i=1; i<n; i++)
                if ( !vist[i] )
                    dist[i] = min( dist[i] , max( dist[pos], w[pos][i]) );
        }
        printf("Scenario #%d\n", time++);
        printf("Frog Distance = %.3lf\n\n", dist[1]);
    }
    return 0;
}

