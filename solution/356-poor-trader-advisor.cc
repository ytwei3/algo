//
// 356 - Poor Trade Advisor
//
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int a, b;
    long long d;
};

int n, m, a, b, ans, vist[501];
long long maxEgde, d;
vector<edge> v;
vector< pair<int, long long> > ar[501];


void bfs(int city)
{
    int cnt = 0;
    queue<int> q;
    q.push(city);

    while ( !q.empty() )
    {
        int curr = q.front();
        q.pop();

        for (auto i : ar[curr])
        {
            if ( !vist[i.first] && i.second == maxEgde )
            {
                vist[i.first] = 1;
                q.push(i.first);
                cnt++;
            }
        }
    }
    if ( cnt > ans )
        ans = cnt;
}

int main()
{
    while ( ~scanf("%d%d", &n, &m) && (m && n) )
    {
        for (int i=0; i<=n; i++)
            vist[i] = 0;

        for ( auto i : ar )
            i.clear();
        v.clear();

        maxEgde = -1, ans = 1;
        while ( m-- )
        {
            scanf("%d%d%d", &a, &b, &d );
            v.push_back({a, b, d});
            maxEgde = max(maxEgde, d);
        }
        for ( auto i : v )
            if ( i.d == maxEgde )
            {
                ar[i.a].push_back( {i.b, i.d} );
                ar[i.b].push_back( {i.a, i.d} );
            }

        for (int i=0; i<n; i++)
            bfs(i);

        printf("%d\n", ans);
    }
    return 0;
}
