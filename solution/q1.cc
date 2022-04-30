//
/* q1 */
//
#include <cstdio>
#include <vector>
using namespace std;


int t, res;


int main ()
{
    scanf("%d", &t);
    int a, b;
    while ( t-- )
    {
        scanf("%d%d", &a, &b);

        if ( a == 0 )
            puts("1");
        else if ( a > b )
            printf("%d\n", a+2*b+1);
        else
            printf("%d\n", 2*b+a+1);
    }

    return 0;
}

