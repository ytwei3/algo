// 165 - Frogger
//
//
#include <stdio.h>
#include <math.h>

int n;
float a, b, d, dd, s, tmp;
float x[203], y[203];
float INF = 9999999;


int vist[203];

int main ()
{
    int test = 1;
    while ( 1 )
    {
        scanf("%d", &n);
        if ( n == 0 )
            break;

        s = 0;
        for (int i=0; i<n; ++i)
        {
            vist[i] = 0;
            scanf("%f%f", &x[i], &y[i]);
        }

        int itr = 0;
        vist[0] = 1;
        while ( !vist[1] )
        {
            d = INF, dd = -1;
            for (int i=1; i<n; ++i)
                if ( !vist[i] )
                {
                    tmp = sqrt( (x[itr]-x[i])*(x[itr]-x[i]) +
                            (y[itr]-y[i])*(y[itr]-y[i]) );
                    if ( d > tmp )
                        itr = i;
                    if ( dd < tmp )
                        dd = tmp;
                }
            vist[itr] = 1;
        }

        printf("Scenario #%d\nFrog Distance = %0.3f\n\n", test, dd);
        test++;
    }
    return 0;
}
