#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <ctime>
using namespace std;
int main()
{
    int num, maxnum, minnum, guess;
    cout << "Please enter the number you want the computer to guess:" 
        << endl;
    cin >> num;
    cout << "Please enter its range (max, min):" << endl;
    cin >> maxnum >> minnum;
    srand((unsigned int)time(NULL));
    do{
        sleep(1);
        guess = rand() % (maxnum - minnum + 1) + minnum;
        if (guess > num){
            cout << setw(-10) << setfill(' ') << guess
                << "     It is larger!" << endl;
            maxnum = guess;
        } else if (guess < num){
            cout << setw(-10) << setfill(' ') << guess
                << "     It is smaller!" << endl;
            minnum = guess;
        } else{
            cout << setw(-10) << setfill(' ') << guess
                << "     Congratulations! You are right!!!" << endl;
        }
    } while (guess != num);
    return 0;
}
