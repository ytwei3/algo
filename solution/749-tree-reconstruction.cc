// 749 - Tree Reconstruction
//
// Given result of the Preorder && inorder
// Output the result of postorder
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

std::unordered_map <int, int> m;

void pp (std::vector<int> pre, std::vector<int> in, int begin, int end, int *p)
{
    if (begin > end)
        return ;

    int index = m[pre[*p]];
    *p = *p + 1;
    // left
    pp(pre, in, begin, index-1, p);
    // right
    pp(pre, in, index+1, end, p);

    printf("%d ", in[index]);
}


int main()
{
    int t; // test case
    scanf("%d", &t);

    while (t--)
    {
        int n; // The integer N
        scanf("%d", &n );

        // initial vectors
        int tmp;
        std::vector<int> pre, in;
        for (int i=0; i<n; ++i)
        {
            scanf("%d", &tmp);
            pre.push_back(tmp);
        }
        for (int i=0; i<n; ++i)
        {
            scanf("%d", &tmp);
            in.push_back(tmp);
        }

        for (int i=0; i<n; ++i)
            m[ in[i] ] = i;

        int preIndex = 0;
        int begin = 0;
        int end = n - 1;
        int index = m[pre[preIndex]];
        preIndex++;
        // left
        pp(pre, in, begin, index-1, &preIndex);
        // right
        pp(pre, in, index+1, end, &preIndex);

        printf("%d\n", in[index]);
        // pp(pre, in, 0, n-1, &preIndex);
    }
    return 0;
}
