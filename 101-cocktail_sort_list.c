#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail Shaker Sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swap;
    listint_t *temp;

    if (list == NULL || *list == NULL)
        return;

    do {
        swap = 0;

        /* Traverse the list from left to right */
        for (temp = *list; temp->next != NULL; temp = temp->next)
        {
            if (temp->n > temp->next->n)
            {
                /* Swap nodes */
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    *list = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = temp->next;
                temp->next = temp->next->next;
                temp->prev->next = temp;

                /* Update previous node's next pointer */
                if (temp->next != NULL)
                    temp->next->prev = temp;

                swap = 1;
                print_list(*list);
            }
        }

        /* If no swapping occurred, the list is sorted */
        if (swap == 0)
            break;

        swap = 0;

        /* Traverse the list from right to left */
        for (; temp->prev != NULL; temp = temp->prev)
        {
            if (temp->n < temp->prev->n)
            {
                /* Swap nodes */
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                temp->next = temp->prev;
                temp->prev = temp->prev->prev;
                temp->next->prev = temp;

                /* Update previous node's next pointer */
                if (temp->prev != NULL)
                    temp->prev->next = temp;

                swap = 1;
                print_list(*list);
            }
        }
    } while (swap);
}

