#include <iostream> // cout and other std functions
#include <vector>
#include <string>
#include <fstream> // IO capabilities

using namespace std; // avoid typing std all times
int main() {
    cout << "Hello, World!" << endl;

    const double PI = 3.1415;
    bool isHappy = false;
    float favNum = 4.2562351;

    cout << "Favorite Number " << favNum << endl; // endl terminates line
    cout << "Size of float " << sizeof(favNum) << endl; // sizeOf returns size in bytes

    int largestInt = 2147483647;
    cout << "Largest int " << largestInt << endl;

    int largestInt1 = 2147483648;
    cout << "Largest int " << largestInt1 << endl;

    return 0;
}