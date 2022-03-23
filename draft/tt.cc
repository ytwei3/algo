#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
 
const int maxn = 55;
const int maxm = 2510;
int F[maxn];
int m,n;
 
struct Edge
{
    int f,t,w;
} edge[maxm];
 
bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}
 
int find(int x)
{
    if(F[x] == -1) return x;
    else return F[x] = find(F[x]);
}
 
int Kruskal()
{
    memset(F,-1,sizeof(F));
    sort(edge,edge+m,cmp);
    int cnt = 0;         //计算加入的边数
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        int f = edge[i].f;
        int t = edge[i].t;
        int w = edge[i].w;
        int t1 = find(f);
        int t2 = find(t);
        if(t1 != t2)
        {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    if(cnt < n-1) return -1;//
    else return ans;
}
 
int main()
{
    while(~scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for(int i = 0; i < m; i++)
            scanf("%d%d%d",&edge[i].f,&edge[i].t,&edge[i].w);
        printf("%d\n",Kruskal());
    }
    return 0;
}
