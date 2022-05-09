#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 100005;

int trie[MAXN][133];
int fail[MAXN],num[MAXN],cnt[MAXN];
int F[MAXN];
string S;
string P;
int idx, cases = 1;
int T_T;
int N_N;

void init(){
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
    memset(num,0,sizeof(num));
    memset(fail,0,sizeof(fail));
    fail[0] = 0;
    idx = 0;
}

void insert(int P_idx){
    int n = P.length();
    int u = 0;
    for(int i = 0; i < n;i++){
        int v = P[i];
        if(!trie[u][v])
            trie[u][v] = ++idx;
        u = trie[u][v];
    }
    if(num[u] == 0){
        num[u] = P_idx;
        F[P_idx] = P_idx;
    }
    else{
        F[P_idx] = num[u];
    }
    
}

void getfail(){
    //fail[0] = -1;
    queue<int> que;
    que.push(0);

    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int i = 0; i < 133;i++){
            if(trie[now][i]){
                fail[trie[now][i]] = now ==0 ? 0: trie[fail[now]][i];
                que.push(trie[now][i]);
            }
            else{
                trie[now][i] = now ==0 ? 0: trie[fail[now]][i];
            }
        }
    }
}

void match(){
    int u = 0;
    int n = S.size();
    for(int i = 0; i< n;i++){
        u = trie[u][S[i]];
        for(int j = u; j ; j = fail[j]){
            if(num[j])
                cnt[num[j]]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T_T;
    while(T_T--)
    {
        init();
        cin>> S >> N_N;

        for(int i = 1; i <= N_N; i++)
        {
            cin >> P;
            insert(i);
        }

        getfail();
        match();

        cout << "Case #" << cases++ << '\n';
        for(int i = 1; i<= N_N;i++)
        {
            cout << cnt[F[i]] << '\n';
        }
    }
    return 0;
}
