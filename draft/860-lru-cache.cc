//
/* 860 - LRU Cache */
//
#include <stdio.h>
#include <list>
#include <unordered_map>
using namespace std;

int n, m, num;
list<int> l;
unordered_map<int, list<int>::iterator > map;

void init()
{
    int num;
    scanf("%d", &num);

    if ( n > 0 )
        n--, init();
    else
        return ;

    l.push_front(num);
    map[num] = l.begin();
}

int main ()
{
    while ( ~scanf("%d%d", &n, &m) )
    {
        init();
        while ( m-- )
        {
            scanf("%d", &num);
            if ( !map.count(num) || map[num] == l.end() )
            {
                printf("0");

                l.push_front(num);
                map[ num ] = l.begin();

                map[ l.back() ] = l.end();
                l.pop_back();
            }
            else
            {
                printf("1");

                l.push_front(num);
                map[ num ] = l.begin();

                l.erase(map[num]);
            }
           // printf("This time the cache is: \n");
           // for ( auto i : l )
           //     printf("%d ", i);
           // printf("\n");
        }

        printf("\n%d", l.front());
        map[ l.front() ] = l.end();
        l.pop_front();
        while ( !l.empty() )
        {
            printf(" %d", l.front());
            map[ l.front() ] = l.end();
            l.pop_front();
        }
        printf("\n");
    }
    return 0;
}
