1. It would take 4 steps to reach the 8. Because it's the 4th item in the array, the index equals the amount of steps it needs to reach it.

2. Since the number 8 is in the middle of the array, and binary search starts at the middle, it will only take one step to perform the search.

3. It would take 16 steps to reach. Since the number is being split in half, it will only take a few steps before eventually descending to 1.
```100,000 -> 50,000 -> 25,000 -> 12,500 -> 6,250 -> 3125 -> 1,562 -> 781 -> 390 -> 195 -> 97 -> 48 -> 24 -> 12 -> 6 -> 3 -> 1```

4. Linear search is O(n) complexity because the inputted value will be equal to the outputted value, while binary search will be O(log(n)) because it will keep splitting the array in half until it finds the inputted value, and with the observation above, it should not take more than 16 steps to find. inputting 50,000 is the best case for binary, while the best case is 1 for linear.

`check main.cpp`

5. The given random search algorithm sounds similar to linear search, and those two can benefit from small amounts of data, maybe 100 or less elements. When the data gets very big, O(log(n)) will be better because of its divide and conquer method. 
