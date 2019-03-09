#include <iostream>
#include <iomanip>
#include <random>
#include "binary.h"
#include <ctime>
using namespace std;
void binary::Array(void)
{
    default_random_engine e;
    e.seed(time(NULL));
    uniform_int_distribution<int> u(1, 9999);
    for (int i = 0; i < len; ++i)
        arr[i] = u(e);
}
void binary::Sort(void)
{
    int tmp;
    for (int k = 0; k < len - 1; ++k)
        for (int m = 0; m < len - k - 1; ++m)
            if (arr[m] > arr[m + 1])
                exch(arr[m], arr[m + 1]);
}
void binary::BinarySearch(int num)
{
    int temp, be = 0, mid = len / 2, end = len - 1;
    while (1)
    {
        if (arr[mid] == num)
        {
            cout << "Its suffix is " << mid <<"." << endl;
            return;
        }
        else if (be + 1 == end && arr[be] != num)
        {
            cout << "The number is not in the array!" << endl;
            return;
        }
        else if (arr[mid] > num && num >= arr[0])
        {
            end = mid;
            mid = (be + end) / 2;
        }
        else if (arr[mid] < num && num <= arr[len - 1])
        {
            be = mid;
            mid = (be + end) / 2;
        }
        else
        {
            cout << "The number is not in the array!" << endl;
            return;
        }
    }
}
void binary::PrintArray(void)
{
    for (int k = 0; k < len; ++k)
    {
        cout << setw(4) << setfill(' ') << arr[k] << ' ';
        if ((k + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}
