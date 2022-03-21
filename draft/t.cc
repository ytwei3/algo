// 165 - Frogger
//
//
#include <stdio.h>
#include <queue>
#include <math.h>

int n;
float a, b, d, s, tmp;
float x[203], y[203];

std::priority_queue<int> q;

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
            scanf("%f%f", &x[i], &y[i]);

        d = 9999999;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
            {
                tmp = sqrt( (x[j]-x[i])*(x[j]-x[i]) +
                        (y[j]-y[i])*(y[j]-y[i]) );
                if (tmp < d)
                    d = tmp;
            }

        printf("Scenario #%d\nFrog Distance = %0.3f\n\n", test, d);
        test++;
    }
    return 0;
}
