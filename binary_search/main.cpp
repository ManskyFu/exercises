#include <iostream>
#include "binary.h"
using namespace std;
int main()
{
    int num, len;
    cout << "Please enter the length of array:" << endl;
    cin >> len;
    class binary t(len);
    t.Array();
    cout << "The array:" << endl;
    t.PrintArray();
    cout << "After sort:" << endl;
    t.Sort();
    t.PrintArray();
    cout << "Please enter the number you want to search:" << endl;
    cin >> num;
    t.BinarySearch(num);
 
    return 0;
}
