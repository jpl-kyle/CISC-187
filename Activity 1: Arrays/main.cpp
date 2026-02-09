#include <iostream>
#include <array>
using namespace std;

int main() 
{
    array<int, 100> numberArray = {}; // a std::array named numberArray with 100 int elements

    cout << numberArray.size() << endl; // the size of the array

    cout << &numberArray << endl; // the memory address of the array
    cout << &numberArray[0] << endl; // the first element of the array has the same address.

    for (int i = 0; i < 100; ++i) // print the array
    {
        cout << numberArray[i] << " ";
    }
    cout << endl;
  
    return 0;
}
