//
// 141 - Ubiquitous Religions
//
#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <unoredered_map>
#define INF = 0x3f3f3f3f
#define ll = long long
//using namespace std;
//std::ios::sync_with_stdio(false), std::cin.tie(0);

int cnt, p[50005];

int find(int x)
{
    return p[x] == -1 ? x : p[x] = find(p[x]);
}
int main()
{
    int n, m, a, b, c, d, t = 1;
    while ( ~scanf("%d%d", &n, &m) && ( m || n ) )
    {
        for (int i=0; i<=n; i++)
            p[i] = -1;

        while ( m-- )
        {
            scanf("%d%d", &a, &b);
            c = find(a), d = find(b);
            if ( c != d )
                p[b] = c;
        }

        cnt = 0;
        for (int i=1; i<=n; i++)
            if ( p[i] == -1 )
                cnt++;

        printf("Case %d: %d\n", t++, cnt);
    }
    return 0;
}
