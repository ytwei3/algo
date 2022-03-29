//
// 863 - Stern-Brocot Tree
//
// #LCA( lowest common ancestor )
#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <unoredered_map>
#define INF = 0x3f3f3f3f
#define ll = long long
//using namespace std;
//std::ios::sync_with_stdio(false), std::cin.tie(0);

struct n
{
    int u, d; // up, down
} a, b, t[100000];

void build()
{
}


int main()
{
    a = { 1, 0 }, b = { 0, 1 };
    build();

    while ( ~scanf("%d%d%d%d", &a.u, &a.d, &b.u, &b.d)
                && (a.u || b.u || a.d || b.d) )
    {
        // printf("%d %d\n");
    }
    return 0;
}
