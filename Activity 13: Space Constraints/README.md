## 1.
````
function wordBuilder(array) { 
		let collection = []; 
		for(let i = 0; i < array.length; i++) { 
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection; 
````
The function's space complexity is O(n^2). The two indices in the nested for loops start and grow at the same rate, which means for example, if the array size was 5, index i would go through 5 times, while j would go off 5 times for every i, except for the last term, which ignores the case where i == j.

## 2.
````
function reverse(array) { 
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) { 
				newArray.push(array[i]);
		}
		return newArray;
}
````
The function's space complexity is O(n) because it will create a new array that is the same size as the array input into the function.

## 3.
````
function reverse(array) { 
		let newArray = [];
        let left = 0;
        let right = array.length - 1;

        while (left < right) {
            let temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            ++left;
            --right;
        }
		return array;
}
````

This version is O(1) because all of the operations are done in one array with no recursion.

## 4. 

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | O(n)               | O(n)                |
| Version #2 | O(n)               | O(1)                |
| Version #3 | O(n)               | O(n)                |

Version 1 is very similar to #2 in this assignment. Version 2 doubles every element without creating new memory for new elements, so it has a constant space complexity. Version 3 doubles every element without creating a new array, but it will take n amount of spots in the call stack to finish the recursive function.
