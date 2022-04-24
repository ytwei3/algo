//
// 233 - ALL Pairs Maximum Flow
//
#include <cstdio>
#include <vector>

struct edge
{
    int u, v;
    long long c, w;
};

int n, t;
int g[201][201];
const int INF = 0x3f3f3f3f;

int main()
{
    int ca = 1, num;
    while ( ~scanf("%d", &t) )
        while ( t-- )
        {
            scanf("%d", &n);
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                {
                    scanf("%d", &num);
                    if ( i > j )
                        
                }

            printf("Case #%d:\n", ca++);
        }

    return 0;
}
