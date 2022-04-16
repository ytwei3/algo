//
// 215 - Jack Straws
//
// #disjoint set
#include <cstdio>
#define INF = 0x3f3f3f3f
//#include <algorithm>
#include <vector>
using namespace std;

struct straw
{
    int u, v, a, b;
};

int t, n;
bool isConnected()
{
    return true;
}
std::vector<straw> v;

int main()
{
    while( ~scanf("%d", &t) )
        while ( t-- )
        {
            straw st;
            scanf("%d", &n);

            while ( n-- )
            {
                scanf("%d%d%d%d", &st.u, &st.v, &st.a, &st.b);
                v.push_back( st );
            }

            int a, b;
            while ( ~scanf("%d%d", &a, &b) && ( a || b ) )
            {
                if ( isConnected() )
                    printf("CONNECTED\n");
                else
                    printf("NOT CONNECTED\n");
            }
        }
    return 0;
}
