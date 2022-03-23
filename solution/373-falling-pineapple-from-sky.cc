//
// 373 - Falling Pineapple From Sky
//
#include <stdio.h>
#include <algorithm>
#include <vector>
//#include <unoredered_map>
#define INF = 0x3f3f3f3f
//using namespace std;

struct edge
{
    int u, v, w;
};

int n, m, p[1005]; // disjoint set
long long sum;
std::vector<edge> v, u;

bool cmp(edge a, edge b)
{
    return ( a.w < b.w );
}
int find (int x)
{
    return p[x] == -1 ? x : p[x] = find( p[x] );
}
void kruskal()
{
    sum = 0;
    for (int i=0; i<=n; ++i)
        p[i] = -1;

    for (auto i : v)
    {
        int a = find( i.u ), b = find( i.v );

        if ( a != b )
        {
            sum += i.w;
            p[a] = b;
        }
        else
            u.push_back(i);
    }
}
void output()
{
    if ( m-n+1 == u.size() )
    {
        printf("Min cost: %lld\n", sum);
        if ( !u.empty() ) 
        {
            auto itr = u.begin();
            printf("%d", itr->w);
            itr++;

            while ( itr != u.end() )
            {
                printf(" %d", itr->w);
                itr++;
            }
            printf("\n");
        }
        else
            printf("\n");
    }
    else
        printf("\\(^o^)/ pray to god\n");
}


int main()
{
    while( ~scanf("%d%d", &n, &m) && ( m || n ) )
    {
        edge e;
        for (int i=0; i<m; ++i)
        {
            scanf("%d%d%d", &e.u, &e.v, &e.w);
            v.push_back( e );
        }

        std::sort( v.begin(), v.end(), cmp );

        kruskal();
        output();

        v.clear(), u.clear();
    }
    return 0;
}
