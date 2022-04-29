//
/* 115 the 3n+1 problem (uva 100) */
//
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

char buf[25];
unordered_map<int, int> map;

int go(int n)
{
    int len = 0;
    int ar[1000001];

    if ( map.count(n) )
        return map[n];

    for (; n != 1; len++ )
        if ( !map.count(n) )
        {
            ar[len] = n;
            n & 1 ? n = n * 3 + 1 : n /= 2;
        }
        else
            break;

    for (int i=0; i < len; i++ )
        map[ ar[i] ] = len-i+map[n];

    return map[ ar[0] ];
}

int main ()
{
    map[1] = 1;

    int a, b, res;
    while ( fgets(buf, sizeof(buf), stdin) )
    {
        fputs(buf, stdout);
        sscanf(buf, "%d%d", &a, &b);

        res = -1;
        for (int i= min(a, b); i<=max(a, b); i++)
            res = max( go(i), res );

        printf(" %d\n", res);
    }

    return 0;
}

