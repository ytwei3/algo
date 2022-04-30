//
/* q2 */
//
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int n;
long long a, p, res;

int main ()
{
    while ( ~scanf("%d", &n) )
    {
        res = -1;
        scanf("%lld", &a);
        for (int i = 2; i<n; i++)
        {
            scanf("%lld", &p);
            if ( p < a )
                a = p;
            else 
                res = max( res, p - a );
        }

        scanf("%lld", &p);
        long long tmp;
        tmp = p - a;
        res = max(res, tmp);

        if ( res == 0 )
            puts("0");
        else if ( res < 0 )
            puts("QUIT");
        else
            printf("%lld\n", res);
    }
    return 0;
}

