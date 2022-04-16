//
// My scratching file!!
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <array>
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

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    a = ~b;
    cout << a << endl;
    a = b | c;
    cout << a << endl;
    a = b & c;
    cout << a << endl;

    return 0;
}
