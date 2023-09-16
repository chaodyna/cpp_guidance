<font face="Microsoft YaHei">
<font face="times new roman">

- [Linear Search](#linear-search)
    - [Complexity Analysis of Linear Search:](#complexity-analysis-of-linear-search)
      - [Time Complexity:](#time-complexity)
      - [Advantages of Linear Search:](#advantages-of-linear-search)
      - [Drawbacks of Linear Search:](#drawbacks-of-linear-search)
- [Binary Search](#binary-search)
    - [Complexity Analysis of Binary Search:](#complexity-analysis-of-binary-search)
    - [Advantages of Binary Search:](#advantages-of-binary-search)
    - [Drawbacks of Binary Search:](#drawbacks-of-binary-search)
- [Jump Search](#jump-search)
    - [Advantages of Jump Search:](#advantages-of-jump-search)

## Linear Search

#### Complexity Analysis of Linear Search:

##### Time Complexity:

- Best Case: In the best case, the key might be present at the first index. So the best case complexity is O(1)
- Worst Case: In the worst case, the key might be present at the last index i.e., opposite to the end from which the search has started in the list. So the worst-case complexity is O(N) where N is the size of the list.
- Average Case: O(N)
- Auxiliary Space: O(1) as except for the variable to iterate through the list, no other variable is used.

##### Advantages of Linear Search:

- Linear search can be used irrespective of whether the array is sorted or not. It can be used on arrays of any data type.
- Does not require any additional memory.
- It is a well-suited algorithm for small datasets.

##### Drawbacks of Linear Search:

- Linear search has a time complexity of O(N), which in turn makes it slow for large datasets.
- Not suitable for large arrays.

## Binary Search

#### Complexity Analysis of Binary Search:
- Time Complexity:
  - Best Case: O(1)
  - Average Case: O(log N)
  - Worst Case: O(log N)
- Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).
#### Advantages of Binary Search:
- Binary search is faster than linear search, especially for large arrays.
- More efficient than other searching algorithms with a similar time complexity, such as interpolation search or exponential search.
- Binary search is well-suited for searching large datasets that are stored in external memory, such as on a hard drive or in the cloud.

#### Drawbacks of Binary Search:

- The array should be sorted.
- Binary search requires that the data structure being searched be stored in contiguous memory locations.
- Binary search requires that the elements of the array be comparable, meaning that they must be able to be ordered.

## Jump Search

- Time Complexity : O(√n)
- Auxiliary Space : O(1)

#### Advantages of Jump Search:

- Better than a linear search for arrays where the elements are uniformly distributed.
- Jump search has a lower time complexity compared to a linear search for large arrays.
- The number of steps taken in jump search is proportional to the square root of the size of the array, making it more efficient for large arrays.
- It is easier to implement compared to other search algorithms like binary search or ternary search.
- Jump search works well for arrays where the elements are in order and uniformly distributed, as it can jump to a closer position in the array with each iteration.
