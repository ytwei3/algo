// file used for scratching!
//#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <deque>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;


int main ()
{
    deque<int> q = { 1, 2, 3 };

    q.push_back( q.front() );
    q.pop_front();

    printf("%d %d\n", q[0], q[2]);
    return 0;
}
