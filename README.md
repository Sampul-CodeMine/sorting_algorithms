# 0x1B. C - Sorting algorithms & Big O

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on `Ubuntu 20.04 LTS` using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- You are not allowed to use global variables
- No more than 5 functions per file
- Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `sort.h`
- Don’t forget to push your header file
- All your header files should be include guarded
- A list/array does not need to be sorted if its size is less than 2.

**These Functions and Data Structures should be used**

```c
/* print_array.c */


#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

```c
/* print_list.c */


#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```

```c
/* part of the sort.h header file*/
/* the below data structure should be included*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

## Tasks To Perform

### **Bubble Sort**

- Write a function that sorts an array of integers in ascending order using the `Bubble Sort` algorithm using the prototpye `void bubble_sort(int *array, size_t size)`

> `BUBBLE SORT`, sometimes referred to as `Sinking Sort`, is a simple sorting algorithm that repeatedly steps through the input list element by element, comparing the current element with the one after it, swapping their values if needed. These passes through the list are repeated until no swaps had to be performed during a pass, meaning that the list has become fully sorted. The algorithm, which is a comparison sort, is named for the way the larger elements "bubble" up to the top of the list.
> This simple algorithm performs poorly in real world use and is used primarily as an educational tool. More efficient algorithms such as quicksort, timsort, or merge sort are used by the sorting libraries built into popular programming languages such as Python and Java

```python
# simple bubble sort using python
#!/usr/bin/python3

def bubblesort(arr):
    size = len(arr)
    for i in range(size):
        swapped = False
        for j in range(0, size - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
                print(arr)
        print("")
    if not swapped:
        exit()


nums = [100, 53, 4, 12, 90, 7, 18, -30]

print("Original Array: ", nums)
print("")
bubblesort(nums)
```

### **Insertion Sort**

- Write a function that sorts a doubly linked list of integers in ascending order using the `Insertion Sort` algorithm using the prototype `void insertion_sort_list(listint_t **list)`.

> `INSERTION SORT` is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons. It is much less efficient on large lists than more advanced algorithms such as `quicksort`, `heapsort`, or `merge sort`. However, insertion sort provides several advantages:
>
> - Simple implementation: Jon Bentley shows a three-line C/C++ version that is five lines when optimized.
> - Efficient for (quite) small data sets, much like other quadratic (i.e., O(n<sup>2</sup>)) sorting algorithms
> - More efficient in practice than most other simple quadratic algorithms such as selection sort or bubble sort
> - Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(kn) when each element in the input is no more than k places away from its sorted position
> - Stable; i.e., does not change the relative order of elements with equal keys
> - In-place; i.e., only requires a constant amount O(1) of additional memory space
> - Online; i.e., can sort a list as it receives it
> When people manually sort cards in a bridge hand, most use a method that is similar to insertion sort.

```python
# simple insertion sort using python
#!/usr/bin/python3

def insertion_sort(arr):
    size = len(arr)
    for i in range(1, size):
        key = arr[i]
        j = i - 1

        while key < arr[j] and j >= 0:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print(arr)


nums = [100, 53, 4, 12, 90, 7, 18, -30]
print("Original Array: ", nums)
print("")
insertion_sort(nums)
```

### **Selection Sort**

- Write a function that sorts an array of integers in ascending order using the `Selection Sort` algorithm using the prototpye `void selection_sort(int *array, size_t size)`.

> `SELECTION SORT` is an in-place comparison sorting algorithm. It has an O(n<sup>2</sup>) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar `Insertion Sort`. Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited.
> The algorithm divides the input list into two parts: a sorted sublist of items which is built up from left to right at the front (left) of the list and a sublist of the remaining unsorted items that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.


```python
# simple selection sort using python
#!/usr/bin/python3

def selection_sort(arr):
    


nums = [100, 53, 4, 12, 90, 7, 18, -30]
print("Original Array: ", nums)
print("")
selection_sort(nums)
```










---

> **Ehigboria Dukeson Oserefuamen**  - *[Sampul-CodeMine](https://github.com/Sampul-CodeMine)*