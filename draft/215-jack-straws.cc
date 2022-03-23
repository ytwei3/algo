//
// 215 - Jack Straws
//
#include <stdio.h>
#define INF = 0x3f3f3f3f
//#include <algorithm>
//#include <vector>
//#include <unoredered_map>
//using namespace std;

int t, n, a, b;
bool isConnected()
{
    return true;
}

int main()
{
    while( ~scanf("%d", &t) )
        while ( t-- )
        {
            scanf("%d", &n);
            while ( n-- )
            {
                scanf("%d%d%d%d", );
            }

            while ( 1 )
            {
                scanf("%d%d", &a, &b);
                if ( a == 0 && b == 0 )
                    break;

                if ( isConnected() )
                    printf("CONNECTED\n");
                else
                    printf("NOT CONNECTED\n");
            }
        }
    return 0;
}
