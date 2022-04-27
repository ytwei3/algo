#include <iostream>

using namespace std;

struct fraction
{
    int a;
    int b;
    double val;
};
int main()
{
    int a1,a2,b1,b2;
    while(cin >> a1 >> b1 >> a2 >> b2)
    {
        if(a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0)
            break;

        if((a1/b1 <=0 && a2/b2 >0) || (a1/b1 >0 && a2/b2 <= 0) || (a1 == 1 && a2 == 1 && b1 == 1 && b2 == 1))
        {
            printf("1 1\n");
            continue;
        }

        struct fraction f1;
        f1.a = a1;
        f1.b = b1;
        f1.val = (double)a1/(double)b1;

        struct fraction f2;
        f2.a = a2;
        f2.b = b2;
        f2.val = (double)a2/(double)b2;

        struct fraction leftFor1;
        struct fraction rightFor1;
        leftFor1.a = 0;
        leftFor1.b = 1;

        rightFor1.a = 1;
        rightFor1.b = 0;

        struct fraction leftFor2 = leftFor1;
        struct fraction rightFor2 = rightFor1;

        struct fraction compare1;
        compare1.a = -1;
        compare1.b = -1;
        struct fraction compare2 = compare1;
        struct fraction prev;

        while(compare1.a == compare2.a && compare1.b == compare2.b)
        {
            prev = compare1;
            int a11 = leftFor1.a + rightFor1.a;
            int b11 = leftFor1.b + rightFor1.b;

            cout << "a11: " << a11 << " b11: " << b11 << endl;
            cout << "cmp1: " << compare1.a << " cmp2: " << compare2.b << endl;

                if(f1.a == compare1.a && f1.b == compare2.b)
                {

                }
                else
                {
                    compare1.a = a11; compare1.b = b11;
                    if(f1.a * b11 >= f1.b * a11){ //f1 is bigger, then go right child
                        leftFor1.a = a11; leftFor1.b = b11;
                    }
                    else{
                        rightFor1.a = a11; rightFor1.b = b11;
                    }
                }




            int a22 = leftFor2.a + rightFor2.a;
            int b22 = leftFor2.b + rightFor2.b;
            if(f2.a == compare2.a && f2.b == compare2.b){
                //compare2.a = a22; compare2.b = b22;
            }
            else{
                compare2.a = a22; compare2.b = b22;
                if(f2.a * b22 >= f2.b * a22){
                    leftFor2.a = a22; leftFor2.b = b22;
                }
                else{

                    rightFor2.a = a22; rightFor2.b = b22;
                }
            }



            //printf("why it doesn't work...\ta1:%d b1:%d\ta2:%d b2:%d\n",a11,b11,a22,b22);
        }
        printf("%d %d\n",prev.a, prev.b);

    }
    return 0;
}
