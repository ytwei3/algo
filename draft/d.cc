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

int t, n;
vector<int> v;
list<int> l;
unordered_map<int, list<int>::iterator > map;

void init()
{
    int num;
    scanf("%d", &num);
    if ( n > 0 )
    {
        n--;
        init();
    }
    else
        return ;

    l.push_front(num);
    map[num] = l.begin();
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0);

    scanf("%d", &n);

    init();

    for ( auto i : l )
        cout << i << " ";
    cout << endl;

    cout << *map[1] << endl;
    cout << *map[2] << endl;
    cout << *map[3] << endl;
    cout << *map[4] << endl;
    cout << *map[5] << endl;

    return 0;
}
