// 830 - Reunion
//
//
#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> ar[1023], v;
std::queue<int> q;
int vist[1023];

int k, n, m, a, b, l, cnt;

bool isValid()
{
    for (auto i : v)
        if ( !vist[i] )
            return false;

    return true;
}
void bfs()
{
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
            vist[j] = 0;

        vist[i] = 1;
        q.push(i);
        while ( !q.empty() )
        {
            int top = q.front();
            q.pop();
            for (auto itr : ar[ top ])
                if ( !vist[itr] )
                {
                    q.push(itr);
                    vist[itr] = 1;
                }
        }
        if ( isValid() )
            cnt++;
    }
    return ;
}
int main()
{
    while ( scanf("%d%d%d", &k, &n, &m) != -1 )
    {
        while (k--)
        {
            scanf("%d", &l);
            v.push_back(l);
        }

        while (m--)
        {
            scanf("%d%d", &a, &b);
            ar[b].push_back(a);
        }

        cnt = 0;
        bfs();
        printf("%d\n", cnt);
    }
    return 0;
}
