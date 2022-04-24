#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v;
    long long c,w;
};
struct dinic{
    const static int N=100005;
    int n,m,s,t;
    vector<Edge>E;
    vector<int>to[N];
    int d[N],C[N];//去掉了当前弧优化 | 又加上了（
    bool vis[N];
    void clear(int n){
        for(int i=1;i<=n;i++)
            to[i].clear();
        E.clear();
    }
    void AddEdge(int u,int v,long long w){
        E.push_back({u,v,w,0});
        E.push_back({v,u,0,0});
        m=E.size();
        to[u].push_back(m-2);
        to[v].push_back(m-1);
    }
    bool bfs(){
        memset(vis,0,sizeof(vis));
        queue<int>que;
        que.push(s);
        d[s]=0;
        vis[s]=1;
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            for(int i=0;i<to[cur].size();i++){
                Edge& x=E[to[cur][i]];
                if(!vis[x.v]&&x.c>x.w){
                    vis[x.v]=1;
                    d[x.v]=d[cur]+1;
                    que.push(x.v);
                }
            }
        }
        return vis[t];
    }
    long long dfs(int u,long long v){
        if(u==t||v==0)
            return v;
        long long w=0,f;
        for(int i=C[u];i<to[u].size();i++){
            C[u]=i;
            Edge& e=E[to[u][i]];
            if(d[u]+1==d[e.v]&&(f=dfs(e.v,min(v,e.c-e.w)))>0){
                e.w+=f;
                E[to[u][i]^1].w-=f;
                w+=f;
                v-=f;
                if(v==0)
                    break;
            }
        }
        return w;
    }
    long long Maxflow(int s,int t){
        this->s=s;
        this->t=t;
        for(int i=0;i<E.size();i++)
            E[i].w=0;
        long long res=0;
        while(bfs()){
            memset(C,0,sizeof(C));
            res+=dfs(s,1e18);
        }
        return res;
    }
};
struct GomoryHu{
    const static int N=1005;
    dinic R;
    vector<pair<int,long long> >to[N];
    int Ref[N];
    void AddEdge(int u,int v,long long w){
        R.AddEdge(u,v,w);
        R.E[R.m-1].c=w;
    }
    void clear(int n){
        for(int i=1;i<=n;i++)
            to[i].clear();
        R.clear(n);
    }
    void build(int l,int r){
        if(l>=r)
            return;
        int u=Ref[l],v=Ref[l+1];
        long long w=R.Maxflow(u,v);
        //此处有树边。
        to[u].push_back(make_pair(v,w));
        to[v].push_back(make_pair(u,w));
        vector<int>U,V;
        for(int i=l;i<=r;i++){
            if(R.vis[Ref[i]])
                U.push_back(Ref[i]);
            else V.push_back(Ref[i]);
        }
        for(int i=0;i<U.size();i++)
            Ref[l+i]=U[i];
        for(int i=0;i<V.size();i++)
            Ref[l+U.size()+i]=V[i];
        build(l,l+U.size()-1);
        build(l+U.size(),r);
    }
    void Execute(int n){
        for(int i=1;i<=n;i++)
            Ref[i]=i;
        build(1,n);
    }
}R;
int T,n,Src,res[205][205];
void dfs(int p,int f,long long mn){
    res[Src][p]=mn;
    for(int i=0;i<R.to[p].size();i++)
        if(R.to[p][i].first!=f)
            dfs(R.to[p][i].first,p,min(mn,R.to[p][i].second));
}
int main(){
    // freopen("stdout","w",stdout);
    scanf("%d",&T);
    for(int Case=1;Case<=T;Case++){
        R.clear(n);
        scanf("%d",&n);
        for(int i=1,u;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&u);
                if(i>j)
                    R.AddEdge(i,j,u);
            }
        R.Execute(n);
        for(int i=1;i<=n;i++){
            Src=i;
            dfs(i,0,1e18);
        }
        printf("Case #%d:\n",Case);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf(j!=1?" ":"");
                if(i==j)
                    printf("0");
                else printf("%d",res[i][j]);
            }
            printf("\n");
        }
    }
}/*

*/

