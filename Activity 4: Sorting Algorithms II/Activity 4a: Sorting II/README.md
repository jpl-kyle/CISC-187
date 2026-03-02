1. I will observe the pseudocode for the task. Insert sort has an average complexity of O(n^2) because of the steps taken. If an array needs to be sorted, it will activate the second while-loop to sort the numbers from the position of the index until the number is in its proper place. that means at its best, the complexity will be constant at N - 1, and any sorting will further extend the number of operations depending on how far the index of the number is from the beginning.

```
i ← 1
while i < length(A) // where A is the array
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while
```


2a. Comparisons: 10, Swaps: 10

2b. (i=2; Comparisons: 9, Swaps: 9) (i=3; Comparisons: 7, Swaps: 7)

2c. At the worst case, the array will not be sorted because the index will become out of scope, and since j is index - 1, the last number will not be sorted.


3a. Worst case, this function's time complexity would be O(n) since it goes through the array only once to check if there is an X in the string.

3b. For a better average and best case, once X is first found in the if-statement, immediately `return true;` so the function ends and returns true once it is found.
