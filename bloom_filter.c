//
// Created by TimurYantimirov on 03.05.2021.
//
#include "bloom_filter.h"
#include <math.h>

#define int_t sizeof(int) * 8 // for bits of type int in different systems

bloom_filter_t *bloom_filter_create(int number_elements, double prob_error) {
    long bloom_filter_size = (long) ((double) (number_elements) * log(prob_error) / (log(2) * log(2)) * -1);
    bloom_filter_t *bloomFilter = malloc(sizeof(bloom_filter_t));
    bloomFilter->dictionary = calloc((size_t) bloom_filter_size, sizeof(int));
    bloomFilter->length = bloom_filter_size;
    bloomFilter->hash_number = (int) ((bloom_filter_size / number_elements) * log(2));;

    return bloomFilter;
}

int hash(char *word, int index, int size) {
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (i + 2) * index * 31 * (hash + 1) + word[i];
    }
    return abs(hash % size);
}

void insert(int hash_count, char *word, int dict[], int bloom_size) {
    for (int i = 0; i < hash_count; i++) {
        set_bit(dict, hash(word, i, bloom_size));
    }
}

// Set the bit at the k-th position in A[i]
void set_bit(int A[], int k) {
    A[k / int_t] |= 1 << (k % int_t);
}

// Test the bit at the k-th position in A[i]
int test_bit(int A[], int k) {
    return ((A[k / int_t] & (1 << (k % int_t))) != 0);
}

int contains(int hash_count, char *word, int dict[], int bloom_size) {
    for (int i = 0; i < hash_count; i++) {
        if (test_bit(dict, hash(word, i, bloom_size)) != 1) {
            return false;
        }
    }
    return true;
}