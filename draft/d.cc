//
// My sample file
//
#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;

int t, n;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    v = { 1, 2, 3 };
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;


    return 0;
}
