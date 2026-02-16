#include <iostream>
#include <array>

using namespace std;

int linearSteps = 0;
int binarySteps = 0;

static int linearSearch(array<int, 100000> array, int input) 
{
    for (int i = 0; i < 100000; ++i) 
    {
        ++linearSteps;
        if (array[i] == input) 
        {
            return i;
        }
    }
    return -1;
}

static int binarySearch(array<int, 100000> array, int input)
{
    int low = 0;
    int high = array.size() - 1;

    while (low <= high) 
    {
        
        int mid = low + (high - low) / 2;
        int temp = array[mid];

        if (temp < input) 
        { 
            low = mid + 1;
            ++binarySteps;
        }
        else if (temp > input)
        {
            high = mid - 1;
            ++binarySteps;
        }
        else if (temp == input)
        {
            return mid;
        }
    }

    return -1;
}

int main() 
{
    array<int, 100000> linearArray = {};
    array<int, 100000> binaryArray = {};
    int input = 0;
    
    for (int i=0; i < 100000; ++i) 
    {
        linearArray[i] = i+1;
        binaryArray[i] = i+1;
    }

    cout << "Insert a number to find: " << endl;
    cin >> input;

    linearSearch(linearArray, input);
    binarySearch(binaryArray, input);

    cout << "Linear steps: " << linearSteps << endl;
    cout << "Binary steps: " << binarySteps << endl;

    return 0;
}

