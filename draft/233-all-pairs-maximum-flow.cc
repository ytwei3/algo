//
// 233 - ALL Pairs Maximum Flow
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

int n, t;
int g[205][205];

int main()
{
    int ca = 1;
    while ( ~scanf("%d", &t) )
        while ( t-- )
        {
            scanf("%d", &n);
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    scanf("%d", &g[i][j]);

            printf("Case #%d:\n", ca++);
        }

    return 0;
}
