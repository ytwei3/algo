// 861 - Counting
//
// scan in matrices first
// scanf(" %c", char) -> add space to skip space
// Young Tablaeu
#include <stdio.h>
#include <algorithm>

const int s = 3005;
const int INF = 0x3f3f3f3f;

int n;
long long sum;
int m[s][s];
int h[s], u[s];


int main()
{
    while ( scanf("%d", &n) != EOF )
    {
        // init
        sum = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                scanf("%1d", &m[i][j]);

        for (int i=0; i<n; ++i)
            h[i] = 0, u[i] = INF;

        int b, a1, a2, a3;
        for (int i=0; i<n; ++i)
        {
            b = 0;
            for(int j=0; j<n; ++j)
            {
                if(!m[i][j]) 
                {
                    ++b, ++h[j], u[j] = std::min(u[j], b);

                    if (i)
                        a1 = m[i-1][j];
                    else
                        a1 = 0;

                    if (j)
                        a2= m[i][j-1];
                    else
                        a2 = 0;

                    if (i && j)
                        a3 = m[i-1][j-1];
                    else
                        a3 = 0;

                    if( u[j] < b )
                       m[i][j] = a1 + a2 - a3 + 1;
                    else
                       m[i][j] = u[j] * h[j];
                }
                else
                    b=0, h[j]=0, u[j]=INF, m[i][j] = 0;

                sum += m[i][j];
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
