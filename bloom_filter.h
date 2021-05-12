//
// Created by TimurYantimirov on 03.05.2021.
//

#ifndef BLOOM_FILTER_EXEC_BLOOM_FILTER_H
#define BLOOM_FILTER_EXEC_BLOOM_FILTER_H
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

typedef struct bloom_filter {
    int hash_number;
    int *dictionary;
    int length;
} bloom_filter_t;

bloom_filter_t *bloom_filter_create(int n, double prob_error);

int hash(char *word, int index, int size);

void insert(int hash_count, char *word, int dict[], int bloom_size);

bool contains(int hash_count, char *word, int dict[], int bloom_size);


#endif //BLOOM_FILTER_EXEC_BLOOM_FILTER_H
