//
// 651 - Best Sum
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
    double x, y;
};

int t, n, num;
vector<int> a, b;
array<int, 1000> ar;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> t;
    while ( t-- )
    {
        cin >> n;
        for (int i=0; i<n; ++i)
        {
            cin >> num;
            a.push_back(num);
        }
        for (int i=0; i<n; ++i)
        {
            cin >> num;
            b.push_back(num);
        }
        a.clear(), b.clear();
    }
    return 0;
}
