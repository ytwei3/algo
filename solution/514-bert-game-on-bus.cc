//
/* 514 */
//
#include <cstdio>

int main ()
{
    int a, b, c, d;

    int ar[3];
    ar[0] = 22, ar[1] = 12, ar[2] = 2;

    while ( ~scanf("%d%d", &a, &b) )
    {
        c = a/2;
        d = b/24;

        if ( c != 0 && b != 0 )
        {
            if ( c == d )
                a %= 2, b %= 24;
            else if ( c > d )
                a -= d*2, b -= d*24;
            else
                a -= c*2, b -= c*24;
        }

        // bert
        int win = 0;
        while ( a*100 + b*10 >= 220 )
        {
            if ( b < 2 )
                break;

            win = 0;
            for (int i=2; i>=0; i--)
                if ( a >= i && b >= ar[i] )
                {
                    a -= i, b -= ar[i];
                    win = 1;
                    break;
                }

            for (int i=0; i<3; i++)
                if ( a >= i && b >= ar[i] )
                {
                    a -= i, b -= ar[i];
                    win = 0;
                    break;
                }
        }

        puts( win ? "Bert" : "Kengood");

    }
    return 0;
}

