#ifndef _BINARY_H
#define _BINARY_H
class binary
{
public:
    binary(int l) : arr(new int[l]), len(l) {  }
    void Array(void);
    void Sort(void);
    void BinarySearch(int num);
    void PrintArray(void);
    ~binary() {delete[] arr; }
private:
    int *arr;
    int len;
    void exch(int &a, int &b) {int t = a; a = b; b = t; }
};
#endif
