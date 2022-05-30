//
/* 508 - DNA Search */
//
// # Tire
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#define maxn 100000
using namespace std;

char buf[maxn+1], str[maxn+1];
char trie[maxn+1][26];

int len, cnt;
int ex[maxn+1]; // exist

unordered_map<int, int> m;
vector<int> v;

void insert()
{
    int p = 0;
    for (int i=0; buf[i] != '\0'; i++)
    {
        int c = buf[i] - 'A';
        if ( !trie[p][c] )
            trie[p][c] = cnt++;
        p = trie[p][c];
    }
    ex[p] = 1;
    v.push_back(p);
}
void find()
{
    int p = 0;
    for (int i=0; str[i] != '\0'; i++)
    {
        int c = str[i] - 'A';
        if ( trie[p][c] )
        {
            p = trie[p][c];
            if ( ex[p] )
                m[p]++;
        }
        else
            p = 0;
    }
}
int main()
{
    int time = 1, t, n;
    while ( ~scanf("%d", &t) )
    {
        getchar();
        while ( t-- )
        {
            cnt = 1;
            v.clear();
            m.clear();
            memset( trie, 0, sizeof(trie) );
            memset( ex, 0, sizeof(ex) );

            getchar();
            scanf("%s", str);
            getchar();

            scanf("%d", &n);
            printf("Case #%d\n", time++);
            for (int i = 0; i<n; i++)
            {
                scanf("%s", buf);
                getchar();
                insert();
            }

            find();

            for ( auto i : v )
                printf("%d ", i);
            puts("");

            for ( auto i : v )
                printf("%d\n", m[ v[i] ]);
        }
    }
    return 0;
}
