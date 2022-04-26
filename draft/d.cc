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


int n, t;
char str[10001];
char buf[101];
unordered_map<char*, int> m;

void go(int a, int n)
{
    if ( n == 0 )
        return;
    cout << a << endl;
    go(a, --n);
}
int main()
{

    go(1, 2);
    return 0;
}
