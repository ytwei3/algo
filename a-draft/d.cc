//
// My scratching file!!
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <array>
#include <cstring>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;

long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}


int main()
{
    cout << binpow( 4, 3 ) << endl;

    return 0;
}
    int cnt, j;
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&cnt);
            while(cnt--)
            {
                scanf("%d",&j);
                if(vis[j]==-1)
                {
                    vis[j]=i;
                    map[0][i]+=cap[j];

                }
                else
                     map[ vis[j] ][i]= INF;

            }
            scanf("%d",&map[i][n+1]);
        }
