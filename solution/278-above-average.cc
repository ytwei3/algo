// 278 - Above Average
//
//
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int c, n, s[1000]; // s - score
    cin >> c;

    while (c--)
    {
        cin >> n;
        int sum = 0;
        int ave = 0;
        for (int i=0; i<n; i++)
        {
            cin >> s[i];
            sum += s[i];
        }
        ave = sum/n;

        int cnt = 0;
        for (int i=0; i<n; i++)
            if (s[i]>ave)
                cnt++;

        cout << fixed << setprecision(3)
             << cnt/(double)n*100 << "\%" << endl;
    }

    // output
    return 0;
}
