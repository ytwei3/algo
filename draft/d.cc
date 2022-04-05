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
#include <math.h>
#define endl "\n"
using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    
    while( cin >> t && t-- )
    {
        for (i=0; i<polyCorners; i++)
        {
            if (polyY[i]<y && polyY[j]>=y
                ||  polyY[j]<y && polyY[i]>=y)
            {
                if ( polyX[i] + (y-polyY[i])/(polyY[j]-polyY[i])*(polyX[j]-polyX[i]) < x ) 
                {
                    oddNodes =! oddNodes; 
                }
            }
            j=i;
        }

        cin >> n;
        cout << n << endl;
    }

    return 0;
}
