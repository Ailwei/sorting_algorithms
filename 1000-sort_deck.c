#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

static int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;

    int value_cmp = strcmp(node_a->card->value, node_b->card->value);

    if (value_cmp == 0)
        return node_a->card->kind - node_b->card->kind;

    return value_cmp;
}

void sort_deck(deck_node_t **deck)
{
    size_t a;
    size_t z;
    deck_node_t *current = *deck;
    deck_node_t **deck_array = malloc(52 * sizeof(deck_node_t *));

    if (!deck_array)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (a = 0; a < 52 && current != NULL; a++)
    {
        deck_array[a] = current;
        current = current->next;
    }

    qsort(deck_array, a, sizeof(deck_node_t *), compare_cards);

    for (z = 0; z < a; z++)
    {
        deck_array[z]->prev = (z > 0) ? deck_array[z - 1] : NULL;
        deck_array[z]->next = (z < a - 1) ? deck_array[z + 1] : NULL;
    }

    *deck = deck_array[0];

    free(deck_array);
}

