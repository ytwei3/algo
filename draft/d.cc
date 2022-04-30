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


unordered_map<string, int> m;

int main()
{
    int n = 2;
    while ( n-- )
    {
        string str;
        fgets(str, sizeof(str), stdin);
        m[str] = n;
    }
    char q[100];
    while ( ~scanf("%s", q) )
        printf("%d\n", m[q]);

    return 0;
}
