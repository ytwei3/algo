//
// 685 - Convex Quadrangles
//
//#include <stdio.h>
#include <iostream>
#include <array>
//#include <string>
#include <vector>
//#include <unoredered_map>
//#include <algorithm>
//#include <cmath>
#define endl "\n"
using namespace std;

struct point
{
    int x, y;
}p;

int t, n, cnt;
vector<point> v;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
        while ( t-- )
        {
            cin >> n;
            while ( n-- )
            {
                cin >> p.x >> p.y;
                v.push_back( p );

                cnt = 0;

                v.clear();
            }
        }
    return 0;
}
