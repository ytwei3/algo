// 22 - Prime Path
//
//
#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> ar[10000];
std::vector<int> primes;

int dist[10001];
int vis[10001];

bool isPrime(int n)
{
    for (int i=2; i*i<=n; i++)
        if (n % i == 0)
            return false;

    return true;
}
bool isValid(int a, int b)
{
    int cnt = 0;
    while (a > 0)
    {
        if (a % 10 != b % 10)
            cnt++;

        a /= 10;
        b /= 10;
    }

    if (cnt == 1)
        return true;
    else 
        return false;
}
void buildGraph()
{
    for (int i=1000; i<=9999; ++i)
        if (isPrime(i))
            primes.push_back(i);

    for (int i=0; i<primes.size(); ++i)
    {
        for (int j=i+1; j<primes.size(); ++j)
        {
            int a = primes[i];
            int b = primes[j];

            if (isValid(a, b))
            {
                ar[a].push_back(b);
                ar[b].push_back(a);
            }
        }
    }
}
void bfs(int src)
{
    std::queue<int> q;
    q.push(src);

    dist[src] = 0;
    vis[src] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i : ar[curr])
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dist[i] = dist[curr] + 1;
                q.push(i);
            }
    }
}

int main()
{
    int test, src, des;
    scanf("%d", &test);
    buildGraph();

    while (test--)
    {
        scanf("%d %d", &src, &des);

        for (int i=1000; i<=9999; i++)
            dist[i] = -1, vis[i] = 0;

        bfs(src);

        if (dist[des] == -1)
            printf("Impossible!\n");
        else
            printf("%d\n", dist[des]);
    }
    return 0;
}
