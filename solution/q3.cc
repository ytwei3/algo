//
/* q3 */
//
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 200000
using namespace std;


struct trail
{
    int n, len, e;
};

int n;
int vis[maxn+1], height[maxn+1], path[maxn+1];

vector<int> foot;
vector<int> ar[maxn];

void getHeight(int st)
{
    queue<int> q;
    q.push(st);
    height[st] = 0;

    while ( !q.empty() )
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;

        for ( auto i : ar[cur] )
            if ( !vis[i] || height[i] > height[cur] + 1 )
            {
                q.push(i);
                height[i] = height[cur] + 1;
            }
    }
}
int bfs(int st)
{
    int mx = -1;

    queue<trail> q;
    q.push( {st, 0, 0} );

    while ( !q.empty() )
    {
        trail cur = q.front();
        q.pop();

        mx = max( mx, cur.len );

        for (auto i : ar[cur.n])
            if ( height[i] < height[cur.n] )
                q.push( { i, cur.len + 1, cur.e+1 } );
            else if ( height[i] == height[cur.n] && cur.e > 0 )
                q.push( { i, cur.len + 1, cur.e-1 } );
            else
                continue;
    }
    return mx;
}

int main ()
{
    scanf("%d", &n);
    {
        int f;
        for (int i=1; i<=n; i++)
        {
            scanf("%d", &f);
            if ( f )
                foot.push_back( i );
        }

        // init height
        for (int i=1; i<=n; i++)
            height[i] = 0;

        int a, b;
        for (int i=0; i<n-1; i++)
        {
            scanf("%d%d", &a, &b);
            ar[a].push_back( b );
            ar[b].push_back( a );
        }

        for (int i=0; i<=n; i++)
            vis[i] = 0;

        for ( auto i : foot )
            getHeight(i);

        for (int i=1; i<=n; i++)
            path[i] = 0;

        // output
        for (int i=1; i<=n; i++)
            printf("%d ", bfs(i));
        puts("");
    }
    return 0;
}
