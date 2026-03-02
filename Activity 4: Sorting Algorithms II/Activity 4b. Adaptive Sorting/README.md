## Part A:
Last assignment, I got a 5/10 because I did not implement the random array of elements. This time, I wanted to prove to myself that I could do it with this assignment in the testing area. I liked how it turned out. 
## Part B:
No sorting has been done for this part.
## Part C:
The thresholds I put for the decider is best case, worst case, nearly sorted <= 400, nearly reverse >=800. The reason I used these numbers is because the worst case based on the equation n(n-1)/2 gives 1225 steps. 800 is close to 2/3 of the array being closer to reverse sorted (That means I want to use Selection), and 400 is close to 1/3 of the array being completely sorted (That means I want to use Insertion). I made it clear that average case can use either selection or insertion. 
Insertion sort is especially affected by input order because it starts at the second element, compares itself to the first element, and then goes in a linear trend through the array (O(n)). Selection selects the first element and scans through the entire array, and since every number will be lower than itself, it will keep going through the array N-1 times, which would be 49 times for the size 50 array, just for the first element. (O(n^2))

# The Code

```cpp
#include <iostream>
#include <array>
// #include <algorithm> // for the shuffle function in testing area
// #include <random> // for the random number generator in testing area & iota
using namespace std;

class Sorting 
{
    public:
        void selectionSort(array<int, 50> &inputArray)
        {
            for (int i = 0; i < 50 - 1; i++) 
            {
                int minimum = i;
                for (int j = i+1; j < 50; j++) 
                {
                    if (inputArray.at(j) < inputArray.at(minimum)) {
                        minimum = j;
                    }
                }
                swap(inputArray.at(i), inputArray.at(minimum));
            }
        }

        void insertionSort(array<int, 50> &inputArray)
        {
            for (int i = 1; i < 50; i++)
            {
                int element = inputArray.at(i);
                int j = i-1;

                while (j >= 0 && inputArray.at(j) > element) {
                    inputArray.at(j+1) = inputArray.at(j);
                    j -= 1;
                }
                inputArray.at(j+1) = element;
            }
        }
        
        void decideSorter(array<int, 50> inputArray) 
        {
            int disorderValue = 0;
            int choice = 0;
            
            for (int i=0; i<50; i++) 
            {
                for (int j = i+1; j<50; j++) 
                {
                    if (inputArray.at(j) < inputArray.at(i)) 
                    {
                        disorderValue++; // n(n-1)/2
                    }
                }
            }
    
            cout << "Disorder Value: " << disorderValue << endl;

            if (disorderValue == 0)
            {
                cout << "Best Case!!! Insertion Sort will be used!" << endl;
            }
            else if (disorderValue == 1225)
            {
                cout << "Worst case... Selection Sort will be used." << endl;
            }
            else if (disorderValue <= 400) //already sorted / nearly sorted
            { 
                cout << "Insertion Sort will be used!" << endl;
            }
            else if (disorderValue >= 800) //higher end of average / reverse order
            { 
                cout << "Selection Sort will be used!" << endl;
            }
            else //average case
            {
                cout << "Insertion Sort or Selection Sort can be used!" << endl;
            }
        }

    private:
        int disorderValue = 0;
        int choice = 0;
};

int main ()
{
    Sorting sorter;
    array<int, 50> userArray = {};
    
    cout << "Please enter 50 digits: " << endl;
    for (int i = 0; i<50; i++) 
    {
        if (!(cin >> userArray.at(i))) {
            cin.clear();
            cin.ignore(10000, '\n');
            i--; //try again
        }
    }

    cout << endl;
    sorter.decideSorter(userArray);
    
    /* TESTING SECTION *** comment out everything above in main.
    Sorting sorter;
    array<int, 50> sampleArray = {}; //testing
    iota(sampleArray.begin(), sampleArray.end(), 1); // input ascending 1 - 50 
    random_device rd;
    mt19937 g(rd()); // create a random device with mersenne twister engine //
    shuffle(sampleArray.begin(), sampleArray.end(), g); //shuffle the array //
    sorter.decideSorter(sampleArray); //decide the array: testing */
    
    return 0;
}
```
