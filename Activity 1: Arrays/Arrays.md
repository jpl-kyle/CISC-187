# Assignment 1: Arrays 
## by John Pierre Lucas, CISC-187

1. I created my array of 100 elements using `std::array`, rather than a C-style array so i can make every element get filled with `0`,
```cpp
array<int, 100> numberArray = {}; // a std::array named numberArray with 100 int elements
```
- - -
2. The size of the array can be accessed with the .size() expression. Since it is a static array, the initialized size will always remain constant.
```cpp
cout << numberArray.size() << endl; // 100 in this case.
```
- - -
3.
### Reading
  1, because it reads the memory address of the given index of an array.
Searching for a value not contained within the array`: 
### Insertion at the beginning
  N+1, because it will have to shift every element in the array to the right to insert it at the beginning.
### Insertion at the end
  1, because it does not need to move any elements to add it to the array.
### Deletion at the beginning
  N+1, because it will have to shift every element to the left to make up the empty space.
### Deletion at the end
  1, because it will free up the last element without affecting the other elements.
- - -
4. with this example, it will probably have O(n) time complexity. Since we are searching every single element for "apple", it will increment the counter each time it finds the word, and worst case would be if the entire array contained the word.
- - -
5. to find the memory address of an array, in c++, use the `&` symbol to find the address.
```cpp
cout << &numberArray << endl; // the memory address of the array
cout << &numberArray[0] << endl; // the first element of the array has the same address.
```
