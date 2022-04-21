#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

void radixSort(int* arrayL, int digit, int len) {
    int digitValue;
    for (int i = 1; i <= digit; i++) {
        vector<int> digitValueList[10];

        for (int j = 0; j != len; j++) {
            //得到位值，相同位值得就加在后面，这样还是有序的。
            digitValue = (arrayL[j] % (int)(pow(10.0, i)) - arrayL[j] %
                                       (int)(pow(10.0, i - 1))) / pow(10.0, i - 1);
            digitValueList[digitValue].push_back(arrayL[j]);
        }
        //把所有的元素读进数组
        int count = 0;
        for (int j = 0; j != 10; j++) {
            for (int k = 0; k != digitValueList[j].size(); k++) {
                arrayL[count] = digitValueList[j][k];
                count++;
            }
        }
    }
}

void output(int* arrayL, int len) {
    for (int i = 0; i != len; i++)
        printf("%d ", arrayL[i]);
}
int main(int argc, char const *argv[])
{
    int lenOfArray;
    int *arrayL;
    printf("Enter the len of the array: ");
    scanf("%d", &lenOfArray);
    arrayL = new int[lenOfArray];
    printf("Enter the elemrnt of array to sort: ");
    for (int i = 0; i != lenOfArray; i++)
        scanf("%d", &arrayL[i]);
    int digit;
    printf("Enter the len of biggest's digit: ");
    scanf("%d", &digit);
    radixSort(arrayL, digit, lenOfArray);
    output(arrayL, lenOfArray);

    delete []arrayL;
    return 0;
}
