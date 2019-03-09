#include <iostream>
int main(int argc, char *argv[])
{
    for (int m = 0; m < argc; ++m)
    {
        std::cout << "Parameter " << m+1
            << " :  " << argv[m]
            << std::endl;
    }
    return 0;
}
