#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: pointer to the previous element of the list
 * @next: Pointer to the element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*functions ptrototypes */

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_helper(int *array, int low, int high);
void shell_sort(int *array, size_t size);
void change_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int get_max(int *array, int size);
void merge_subarray(int *subarray, int *buffer, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarray, int *buffer, size_t front, size_t back);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int array[], size_t size);
void bitonic_sort(int *arr, size_t size);
void bitonic_merge(int *array, size_t low, size_t size, int position);
void bitonic_sort_recursive(int *arr, size_t low, size_t size, int direction);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void quick_sort2(int *array, int low, int high, size_t size);

#endif
