//
// 508 - DNA Search
//
#include <stdio.h>
#include <string.h>
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

char s[100005], sub[100005];

int main()
{
    int t, n;
    while ( ~scanf("%d", &t) )
        for (int i=1; i<=t; i++)
        {
            scanf("%s", s);
            scanf("%d", &n);

            printf("Case #%d\n", i);
            for (int k=0; k<n; k++)
            {
                int cnt = 0;
                scanf("%s", sub);

                char *p = s;
                while ( 1 )
                {
                    p = strstr(p, sub);
                    if ( p == NULL || p+1 == NULL )
                        break;
                    else
                    {
                        p = p + 1;
                        cnt++;
                    }
                }
                printf("%d\n", cnt);
            }
        }

    return 0;
}
