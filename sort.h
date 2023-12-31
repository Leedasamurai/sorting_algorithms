#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi);
size_t lomuto_partition(int *array, size_t size, size_t lo, size_t hi);
void swap(int *array, size_t size, int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void counting_sort(int *array, size_t size);
int integer_count(int *array, size_t size, int range);
void merge_sort(int *array, size_t size);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void siftdown(int *array, size_t start, size_t end, size_t size);
void swap(int *array, size_t size, int *a, int *b);
void radix_sort(int *array, size_t size);
int get_digit(long number, int digit);
int radix_pass(int *array, ssize_t size, int digit, int *new_array);
void bitonic_sort(int *array, size_t size);
void _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end);
void bitonic_merge(int up, int *array, size_t start, size_t end);
void bitonic_compare(int up, int *array, size_t start, size_t end);
void swapy(int *a, int *b);

#endif /* SORT_H */

