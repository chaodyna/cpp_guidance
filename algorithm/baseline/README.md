<font face="Microsoft YaHei">
<font face="times new roman">

Sort Algorithm
===

- [SelectionSort](#complexity-analysis-of-selection-sort)
- [BubbleSort](#complexity-analysis-of-bubble-sort)
- [InsertSort](#complexity-analysis-of-insertion-sort)
- [MergeSort](#complexity-analysis-of-merge-sort)
- [QuickSort](#complexity-analysis-of-quick-sort)
- [HeapSort](#complexity-analysis-of-heap-sort)
- [BucketSort](#complexity-analysis-of-bucket-sort-algorithm)
- [MergeSort3Way](#how-the-above-code-works)
- [QuickSort3Way](#quicksort3way)
- [radixSort](#radixsort)
- [topogicalSort](#topogicalsort)

## SelectionSort

#### Complexity Analysis of Selection Sort

- Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

- One loop to select an element of Array one by one = O(N)
- Another loop to compare that element with every other Array element = O(N)
- Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)
- Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(N) swaps and can be useful when memory writing is costly.

##### Advantages of Selection Sort Algorithm

- Simple and easy to understand.
- Works well with small datasets.
- Disadvantages of the Selection Sort Algorithm
- Selection sort has a time complexity of O(n^2) in the worst and average case.
- Does not work well on large datasets.
- Does not preserve the relative order of items with equal keys which means it is not stable.

## BubbleSort

## Complexity Analysis of Bubble Sort:

- Time Complexity: O(N2)
- Auxiliary Space: O(1)

#### Advantages of Bubble Sort:

- Bubble sort is easy to understand and implement.

- It does not require any additional memory space.

- It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.

#### Disadvantages of Bubble Sort:

- Bubble sort has a time complexity of O(N2) which makes it very slow for large data sets.
- Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison operator to determine the relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.

## MergeSort

## Complexity Analysis of Insertion Sort:

#### Time Complexity of Insertion Sort

- The worst-case time complexity of the Insertion sort is O(N^2)
- The average case time complexity of the Insertion sort is O(N^2)
- The time complexity of the best case is O(N).

#### Space Complexity of Insertion Sort

- The auxiliary space complexity of Insertion Sort is O(1)

#### Characteristics of Insertion Sort

- This algorithm is one of the simplest algorithms with a simple implementation
- Basically, Insertion sort is efficient for small data values
- Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that are already partially sorted.



## Complexity Analysis of Merge Sort:
- Time Complexity: O(N log(N)),  Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.

$$T(n) = 2T(n/2) + θ(n)$$

- The above recurrence can be solved either using the Recurrence Tree method or the Master method. It falls in case II of the Master Method and the solution of the recurrence is θ(Nlog(N)). The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

- Auxiliary Space: O(N), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for merge sort.

#### Applications of Merge Sort:

- Sorting large datasets: Merge sort is particularly well-suited for sorting large datasets due to its guaranteed worst-case time complexity of O(n log n).
- External sorting: Merge sort is commonly used in external sorting, where the data to be sorted is too large to fit into memory.
- Custom sorting: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data.
- Inversion Count Problem

#### Advantages of Merge Sort:

- Stability: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
- Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN), which means it performs well even on large datasets.
- Parallelizable: Merge sort is a naturally parallelizable algorithm, which means it can be easily parallelized to take advantage of multiple processors or threads.

#### Drawbacks of Merge Sort:\

- Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process.
- Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
- Not always optimal for small datasets: For small datasets, Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort. This can result in slower performance for very small datasets.
## QuickSort
## Complexity Analysis of Quick Sort:

- Time Complexity:

  - Best Case: Ω (N log (N))
  - The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves.
  - In this case, the algorithm will make balanced partitions, leading to efficient Sorting.
  - Average Case: θ ( N log (N))
  - Quicksort’s average-case performance is usually very good in practice, making it one of the fastest sorting Algorithm.
  - Worst Case: O(N2)
  - The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or largest element. To mitigate the worst-case Scenario, various techniques are used such as choosing a good pivot (e.g., median of three) and using Randomized algorithm (Randomized Quicksort ) to shuffle the element before sorting.
- Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack space then, in the worst case quicksort could make O(N).
  - Advantages of Quick Sort:
  - It is a divide-and-conquer algorithm that makes it easier to solve problems.
  -  It is efficient on large data sets.
  - It has a low overhead, as it only requires a small amount of memory to function.
- Disadvantages of Quick Sort:
  - It has a worst-case time complexity of O(N2), which occurs when the pivot is chosen poorly.
  - It is not a good choice for small data sets.
  - It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).

## HeapSort

## Complexity Analysis of Heap Sort

- Time Complexity: O(N log N)
- Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.

#### Important points about Heap Sort:

- Heap sort is an in-place algorithm.
- Its typical implementation is not stable but can be made stable (See this)
- Typically 2-3 times slower than well-implemented QuickSort.  The reason for slowness is a lack of locality of reference.

#### Advantages of Heap Sort:

- Efficient Time Complexity: Heap Sort has a time complexity of O(n log n) in all cases. This makes it efficient for sorting large datasets. The log n factor comes from the height of the binary heap, and it ensures that the algorithm maintains good performance even with a large number of elements.
- Memory Usage – Memory usage can be minimal because apart from what is necessary to hold the initial list of items to be sorted, it needs no additional memory space to work
- Simplicity –  It is simpler to understand than other equally efficient sorting algorithms because it does not use advanced computer science concepts such as recursion.
- Disadvantages of Heap Sort:
- Costly: Heap sort is costly.
- Unstable: Heap sort is unstable. It might rearrange the relative order.
- Efficient: Heap Sort is not very efficient when working with highly complex data.

## BucketSort

## Complexity Analysis of Bucket Sort Algorithm

- Time Complexity: O(n2),
  - If we assume that insertion in a bucket takes O(1) time then steps 1 and 2 of the above algorithm clearly take O(n) time.
  - The O(1) is easily possible if we use a linked list to represent a bucket.
  - Step 4 also takes O(n) time as there will be n items in all buckets.
  - The main step to analyze is step 3. This step also takes O(n) time on average if all numbers are uniformly distributed.
- Auxiliary Space: O(n+k)

## MergeSort3Way

## How the above code works?

  - Here, we first copy the contents of data array to another array called fArray. Then, sort the array by finding midpoints that divide the array into 3 parts and called sort function on each array respectively. The base case of recursion is when size of array is 1 and it returns from the function. Then merging of arrays starts and finally the sorted array will be in fArray which is copied back to gArray.

- Time Complexity: In case of 2-way Merge sort we get the equation: T(n) = 2T(n/2) + O(n)
Similarly, in case of 3-way Merge sort we get the equation: T(n) = 3T(n/3) + O(n)
By solving it using Master method, we get its complexity as O(n log 3n).

  - Although time complexity looks less compared to 2 way merge sort, the time taken actually may become higher because number of comparisons in merge function go higher. Please refer Why is Binary Search preferred over Ternary Search? for details.

- Auxiliary Space Complexity: The space complexity of 3-way merge sort is same as 2-way merge sort: O(n)

## QuickSort3Way

#### Time Complexity: O(N * log(N))

- Where ‘N’ is the number of elements in the given array/list

- The average number of recursive calls made to the quicksort function is log N, and every time the function is called we are traversing the given array/list which requires O(N) time. Thus, the total time complexity is O(N * log (N)).

#### Space Complexity: O(log N)

- where ‘N’ is the number of elements in the given array/list.


## radixSort

- Complexity Analysis of Radix Sort:
  - Time Complexity:

  - Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by the individual digits which share the same significant position and value. It has a time complexity of O(d * (n + b)), where d is the number of digits, n is the number of elements, and b is the base of the number system being used.
  - In practical implementations, radix sort is often faster than other comparison-based sorting algorithms, such as quicksort or merge sort, for large datasets, especially when the keys have many digits. However, its time complexity grows linearly with the number of digits, and so it is not as efficient for small datasets.
- Auxiliary Space:

  - Radix sort also has a space complexity of O(n + b), where n is the number of elements and b is the base of the number system. This space complexity comes from the need to create buckets for each digit value and to copy the elements back to the original array after each digit has been sorted.


## TopogicalSort

- 对一个有向无环图(Directed Acyclic Graph简称DAG)G进行拓扑排序，是将G中所有顶点排成一个线性序列，使得图中任意一对顶点u和v，若边(u,v)∈E(G)，则u在线性序列中出现在v之前。通常，这样的线性序列称为满足拓扑次序(Topological Order)的序列，简称拓扑序列。简单的说，由某个集合上的一个偏序得到该集合上的一个全序，这个操作称之为拓扑排序。

- 无向图和有环的有向图没有拓扑排序拓扑排序其实就是离散上的偏序关系的一个应用

1. 按照一定的顺序进行构造有向图，记录后个节点的入度；
2. 从图中选择一个入度为0的顶点,输出该顶点;
3. 从图中删除该顶点及所有与该顶点相连的边
4. 重复上述两步，直至所有顶点输出。
5. 或者当前图中不存在入度为0的顶点为止。此时可说明图中有环。
6. 因此，也可以通过拓扑排序来判断一个图是否有环。