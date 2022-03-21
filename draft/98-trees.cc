// 98 - Trees
//
//
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

int n, m, a, b, tree;
int aa, bb;
int ar[505];
std::vector<int> v[505];
std::unordered_map<int, int> map;

void res()
{
    if ( tree > 1 )
        printf("A forest of %d trees.\n", tree);
    else if ( tree == 1 )
        printf("There is one tree.\n");
    else
        printf("No trees.\n");
}

int main()
{
    int time = 1;
    while ( 1 )
    {
        scanf("%d%d", &n, &m);
        if ( n == 0 && m == 0 )
            break;

        tree = 0;
        for (int i=1; i<=n; ++i)
            ar[i] = i;

        while ( m-- )
        {
            scanf("%d%d", &a, &b);
            aa = std::min(a, b);
            bb = std::max(a, b);

            if ( ar[a] == ar[b] )
            {
                map[ ar[aa] ] = 0;
                continue;
            }

            ar[bb] = ar[aa];

            if ( !map.count( ar[aa] ) )
                map[ ar[aa] ] = 1;

            v[ ar[aa] ].push_back( bb );
            v[ bb ].push_back( 0 );
        }

        for (int i=1; i<=n; ++i)
            if ( v[i].empty() || ( v[i].front() != 0 && map[i] ) )
                tree++;

        printf("Case %d: ", time++);
        res();
    }
    return 0;
}
