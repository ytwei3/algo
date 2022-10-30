//
// 495 I Love String! - Obviously No :(( 
//
#include <stdio.h>
#include <string.h>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <unoredered_map>
#define INF = 0x3f3f3f3f
#define ll = long long
//using namespace std;

char s[100005], f[1005];

int main()
{
    // std::ios::sync_with_stdio(false), std::cin.tie(0);
    int t;
    while ( ~scanf("%d", &t) )
    {
        while ( t-- )
        {
            int q;
            scanf("%s", s);
            scanf("%d", &q);
            while ( q-- )
            {
                char *pos;
                scanf("%s", f);
                pos = strstr(s, f);
                if ( pos != NULL )
                    printf("y\n");
                else
                    printf("n\n");
            }
        }
    }
    return 0;
}
