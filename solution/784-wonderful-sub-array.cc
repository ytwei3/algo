//
/* 784 - Wanderful Sub-array */
//
#include <stdio.h>
#include <vector>
using namespace std;

int t, n, m, num;
int ar[100005];
const int INF = 0x3f3f3f3f;
vector<long long> v;

int main ()
{
    scanf("%d", &t);
    while ( t-- )
    {
        v.clear();
        long long sub = 0;
        int p = 0;
        scanf("%d%d", &n, &m);
        for ( int i=0; i<n; ++i )
        {
            scanf("%d", &ar[i]);
            if ( ar[i] <= m )
            {
                if (ar[i] == m || ar[p] == m) 
                {
                    v.push_back(sub);
                    if ( ar[i] < m )
                        v.push_back(-INF);
                }
                sub = 0, p = i;
            }
            else
                sub += ar[i];
        }
        v.push_back(sub);

        long long ans = -1, subsum;
        for (int i=0; i<v.size()-1; ++i)
        {
            subsum = v[i] + v[i+1];
            if ( subsum > ans )
                ans = subsum;
        }
        printf("%lld\n", ans + m);
    }
    return 0;
}
