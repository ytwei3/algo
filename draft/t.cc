#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
public:
    vector< int > Adj;
    vector< int > ppa;
};

bool visted[500];
Node citys[500];
bool lnk[500];

int main(int argc, const char *argv[])
{
    int m,n;
    while (cin >> m >> n && m && n) {
        for (int i=0; i!=500; ++i) {
            citys[i].Adj.clear();
            citys[i].ppa.clear();
            visted[i] = false;
            lnk[i] = false;
        }
        signed int max_ppa = -2147483648;
        //cout << max_ppa << endl;
        for (int i=0; i!=n; ++i) {
            int c1,c2;
            int ppa;
            cin >> c1 >> c2 >> ppa;
            --c1;
            --c2;
            citys[c1].Adj.push_back(c2);
            citys[c1].ppa.push_back(ppa);
            citys[c2].Adj.push_back(c1);
            citys[c2].ppa.push_back(ppa);
            if (ppa>max_ppa)
              max_ppa = ppa;
            lnk[c1] = true;
            lnk[c2] = true;
        }
        int max_c = 0;
        int c_no = 0;
        for (int i=0; i!=m; ++i) {
            if (lnk[i] && !visted[i]) {
                stack< int > s;
                s.push(i);
                visted[i] = true;
                c_no=1;
                while (!s.empty())
                {
                    int k = s.top();
                    s.pop();
                    for (int j=0; j!= citys[k].Adj.size(); ++j)
                    {
                        if (!visted[ citys[k].Adj[j] ] &&
                            citys[k].ppa[j] == max_ppa)
                        {
                            s.push(citys[k].Adj[j]);
                            visted[ citys[k].Adj[j] ] = true;
                            ++c_no;
                        }
                    }
                }
            }
            if (c_no>max_c)
              max_c = c_no;
        }
        cout << max_c << endl;
    }
    return 0;
}
