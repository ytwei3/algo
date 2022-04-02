//
// My sample file
//
//#include <stdio.h>
#include <iostream>
#include <array>
//#include <string>
//#include <vector>
//#include <unoredered_map>
//#include <algorithm>
//#include <cmath>
#define endl "\n"
#define INF = 0x3f3f3f3f
using namespace std;

array<int ,5> ar;
int n, t;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    while (  cin >> t >> n && ( t || n ) )
        cout << t + n <<  endl;
    
    return 0;
}
