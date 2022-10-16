# Heap

Structure where every next node is smaller or equal than previous one (It as actually a "max heap"). Therefore, the 
largest element is always at index 0. Adding new elements and removing the largest one has low cost.


## Heap STL methods:

<details>
  <summary>is_heap</summary>

```c++
    bool is_heap( RandomIt first, RandomIt last );
    bool is_heap( RandomIt first, RandomIt last, Compare comp );
```
- Check if collection can be a heap
- Complexity: O(N)
-   <details>
     
    <summary> **[comp]** - compare function </summary>

    Compare function should have such form
    
    ```c++
        bool cmp(const Type1 &a, const Type2 &b)
        {
            return ...;
        }
    ```
  
    </details>

</details>

<details>
  <summary>is_heap_until</summary>

```c++
    RandomIt is_heap_until( RandomIt first, RandomIt last );
    RandomIt is_heap_until( RandomIt first, RandomIt last, Compare comp );
```

- Rinds longest subrange that meets the criterium of heap
- Returns iterator to item one ahead of subrange upper bound 
- Complexity: O(N)
-   <details>

    <summary> **[comp]** - compare function </summary>

    Compare function should have such form

    ```c++
        bool cmp(const Type1 &a, const Type2 &b)
        {
            return ...;
        }
    ```

    </details>

</details>


<details>
  <summary>make_heap</summary>

```c++
    void make_heap( RandomIt first, RandomIt last );
    void make_heap( RandomIt first, RandomIt last, Compare comp );
```

- Constructs a heap in the range [first, last).
- Complexity: O(N)
- Does not return any value
-   <details>

    <summary> **[comp]** - compare function </summary>

    Compare function should have such form

    ```c++
        bool cmp(const Type1 &a, const Type2 &b)
        {
            return ...;
        }
    ```

    </details>

</details>


<details>
  <summary>pop_heap</summary>

```c++
    void pop_heap( RandomIt first, RandomIt last );
    void pop_heap( RandomIt first, RandomIt last, Compare comp );
```

- Swaps the value in the position first and the value in the position last-1 and makes the subrange [first, last-1) into a heap.
- Does not delete an element, just put it as the last in container
- Does not return any value
- Complexity: O(log(N))
-   <details>

    <summary> **[comp]** - compare function </summary>

    Compare function should have such form

    ```c++
        bool cmp(const Type1 &a, const Type2 &b)
        {
            return ...;
        }
    ```

    </details>

</details>


<details>
  <summary>push_heap</summary>

```c++
    void push_heap( RandomIt first, RandomIt last );
    void push_heap( RandomIt first, RandomIt last, Compare comp );
```

- Align item at last container index to the heap
- items at previous indexes except the last one have to create a heap
- Does not return any value
- Complexity: O(log(N))
-   <details>

    <summary> **[comp]** - compare function </summary>

    Compare function should have such form

    ```c++
        bool cmp(const Type1 &a, const Type2 &b)
        {
            return ...;
        }
    ```

    </details>

</details>


<details>
  <summary>sort_heap </summary>

```c++
    void sort_heap( RandomIt first, RandomIt last );
    void sort_heap( RandomIt first, RandomIt last, Compare comp );
```

- Converts a heap into collection of sorted elements
- After sort collection most likely would not be a heap anymore
- Does not return any value
- Complexity: O(N*log(N))
-   <details>

    <summary> **[comp]** - compare function </summary>

    Compare function should have such form

    ```c++
        bool cmp(const Type1 &a, const Type2 &b)
        {
            return ...;
        }
    ```

    </details>

</details>

