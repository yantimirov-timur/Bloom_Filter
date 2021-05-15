//
// Created by TimurYantimirov on 03.05.2021.
//
#include "bloom_filter.h"
#include <math.h>


bloom_filter_t *bloom_filter_create(int number_elements, double prob_error) {
    size_t bloom_filter_size = number_elements * log(prob_error) / (log(2) * log(2)) * -1;
    bloom_filter_t *bloomFilter = malloc(sizeof(bloom_filter_t));
    bloomFilter->dictionary = calloc(bloom_filter_size, sizeof(int));
    bloomFilter->length = bloom_filter_size;
    bloomFilter->hash_number = (bloom_filter_size / number_elements) * log(2);;

    return bloomFilter;
}


int hash(char *word, int index, int size) {
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (i + 2) * index * 31 * (hash + 1) + word[i];
    }
    return abs(hash % size);
}

//Set the bit at the k-th position in A[i]
void set_bit(int A[], int k) {
    A[k / 32] |= 1 << (k % 32);
}

//Test of contains bit at the k-th position
int test_bit(int A[], int k) {
    return ((A[k / 32] & (1 << (k % 32))) != 0);
}

void insert(int hash_count, char *word, int dict[], int bloom_size) {
    for (int i = 0; i < hash_count; i++) {
        int index = hash(word, i, bloom_size);
        set_bit(dict, index);
    }
}

int contains(int hash_count, char *word, int dict[], int bloom_size) {
    int count_hash = 0;
    for (int i = 0; i < hash_count; i++) {
        int index = hash(word, i, bloom_size);
        if ( test_bit(dict, index) == 1) {
            count_hash += 1;
        }

    }
    if (count_hash == hash_count) {
        return 1;
    } else {
        return 0;
    }
}