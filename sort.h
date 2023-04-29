#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

/* Custom functions that will be called when the header file is included*/
void print_array(const int *, size_t);
void print_list(const listint_t *);

/* Bubble Sort */
void swapper(int *, int *);
void bubble_sort(int *, size_t);

/* Insertion Sort */
void insertion_sort_list(listint_t **);
void swap(listint_t **, listint_t **);

/* Selection Sort */
void selection_sort(int *, size_t);

/* Quick Sort */
void quick_sort(int *, size_t);
void q_swap(int *, int*);
int partitioner(int *, size_t, int, int);
void sorter(int *, size_t, int, int);

/* Shell Sort */
void shell_sort(int *, size_t);

/* Counting Sort */
int get_maximum(int *, int);
void counting_sort(int *, size_t );

#endif /* SORT_H */
