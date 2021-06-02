//
// Created by TimurYantimirov on 03.05.2021.
//

#ifndef BLOOM_FILTER_EXEC_BLOOM_FILTER_H
#define BLOOM_FILTER_EXEC_BLOOM_FILTER_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct bloom_filter {
    int hash_number;
    int *dictionary;
    long length;
} bloom_filter_t;

bloom_filter_t *bloom_filter_create(int number_elements, double prob_error);

int hash(char *word, int index, int size);

void set_bit(int A[], int k);

int test_bit(int A[], int k);

void insert(int hash_count, char *word, int dict[], int bloom_size);

int contains(int hash_count, char *word, int dict[], int bloom_size);


#endif //BLOOM_FILTER_EXEC_BLOOM_FILTER_H
