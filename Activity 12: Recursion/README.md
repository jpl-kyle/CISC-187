1. The base case would be "return if low > high"
2. When you run factorial 10, instead of calling itself 9 seperate times for each case, it will split the calls in half, and another thing is that the base case checks if `n == 1`, and since it is an odd number, `(n - 2)` will never reach 1, and the function will call itself again, multiplying the number with negative numbers infinitely, until a stack overflow happens..
3.
```py
def sum(low, high)
    return high + sum(low, high - 1)
end
```

Solution:
```py
def sum(low, high)
    if (high == 0) {
        return;
    }
    return high + sum(low, high - 1)
end
```

4. I am not sure how to implement multiple nested arrays in c++, so I made pseudo code that will follow the logic.
```md
def printArray(array)
    for each element in array:
        if element = list:
            printArray(element)
        else:
            print(element)
```
Every time the algorithm runs into an array, it will input that array into the recursive function, and it will run the else statement until the array ends, or until it runs into another array. The else statement will simply print the value if it is not a list, which means that it is just an integer.

