//
// 211 - Points
//
//#include <stdio.h>
#include <iostream>
//#include <array>
//#include <string>
#include <vector>
//#include <unoredered_map>
#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;

struct point
{
    int x, y;
}p, p0;

int t, pos;
const int INF =0x3f3f3f3f;
vector<point> v, s;

int cross(point a, point b, point c)
{
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
int dot(point a, point b, point c)
{
    return (b.y-a.y)*(c.y-a.y) + (c.x-a.x)*(b.x-a.x);
}
double dis(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0 + (a.y-b.y)*(a.y-b.y)*1.0);
}
int cmp(point a, point b)
{
    return (cross(p0, a, b) > 0 || ( cross(p0, a, b) == 0 && dis(p0, a) <= dis(p0, b) )) ? 1 : 0;
}
void graham()
{
    int m = 1;

    point tmp;
    tmp = v[pos];
    v[pos] = v[0];
    v[0] = tmp;

    sort(v.begin()+1, v.end(), cmp);
    s.push_back(p0), s.push_back(v[1]);

    for (int i=2; i<v.size(); ++i)
    {
        while ( cross(s[m-1], s[m], v[i] ) < 0 )
        {
            s.pop_back();
            m--;
        }
        s.push_back( v[i] );
        m++;
    }
}
int between(point a, point b, point c)
{
    return ( ((a.y <= c.y) && (c.y < b.y)) || ((b.y <= c.y) && (c.y < a.y)));
}
int onSegment(point a, point b, point c)
{
    if ( (c.x==a.x && c.y == a.y) || (c.x==b.x && c.y == b.y) )
        return 1;
    // cross = 0 means a, b, c are aligned - 1.
    // 0 <= dot <= dist(ab) on the segment - 2.
    return ( cross(a, b, c) == 0 && dot(a, b, c) >= 0 && dot(a, b, c) <= dot(a, b, b)) ? 1 : 0;
}
void rayCasting(point c)
{
    int odd = 0;
    for (int i=0, j = s.size()-1; i < s.size(); j = i++)
    {
        if (onSegment(s[i], s[j], c))
        {
            cout << "inside" << endl;
            return ;
        }
        if ( between(s[i], s[j], c) &&
            (s[j].x - s[i].x) * ( c.y-s[i].y )/(s[j].y - s[i].y) + s[i].x > c.x )
                odd =! odd;     // flip 0 & 1 
    }

    cout << (odd ? "inside" : "outside") << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
    {
        // first set
        p0 = { INF, INF };
        pos = 0;
        for (int i=0; i<t; ++i)
        {
            cin >> p.x >> p.y;
            v.push_back(p);
            if ( p.y < p0.y || ( p.y == p0.y && p.x < p0.x) )
            {
                p0 = p;
                pos = i;
            }
        }
        graham();

        // second set
        cin >> t;
        while ( t-- )
        {
            cin >> p.x >> p.y;
            rayCasting(p);
        }
        v.clear(), s.clear();
    }
    return 0;
}
