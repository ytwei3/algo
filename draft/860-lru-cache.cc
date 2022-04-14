//
/* 860 - LRU Cache */
//
#include <stdio.h>
#include <list>
#include <unordered_map>
using namespace std;

int n, m, x;
list<int> l;
unordered_map<int, list<int>::iterator > map;


int main ()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        while ( n-- )
        {
            scanf("%d", &x);
            l.push_back(x);
        }

        for (auto it = l.begin(); it != l.end(); it++)
            map[ *it ] = it;

        for (auto i : l)
            printf("%d ", i);
        printf("\n");

        while ( m-- )
        {
            scanf("%d", &x);
            if ( !map.count(x) )
            {
                printf("0");

                l.push_front(x);
                map[ x ] = l.begin();

                int t = l.back();
                l.pop_back();
                map.erase( t );
            }
            else
            {
                printf("1");

                l.push_front(x);
                map[ x ] = l.begin();

                l.erase(map[x]);
            }
        }

        printf("\n%d", l.front());
        l.pop_front();

        for ( auto i : l )
            printf(" %d", i);
        l.clear(), map.clear();
        printf("\n");
    }
    return 0;
}
