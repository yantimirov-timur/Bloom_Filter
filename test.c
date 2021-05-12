//
// Created by TimurYantimirov on 11.05.2021.
//
#include "bloom_filter.h"
#include <stdio.h>

void assert_true(bool result) {
    if (result == 1) {
        printf("Test passed");
    } else {
        printf("Test failed");
    }
}

void test1() {
    int num_elements = 6;
    double prob = 0.1;
    bloom_filter_t *bf = bloom_filter_create(num_elements, prob);

    insert(bf->hash_number, "abc", bf->dictionary, bf->length);
    insert(bf->hash_number, "bcd", bf->dictionary, bf->length);
    insert(bf->hash_number, "cde", bf->dictionary, bf->length);
    insert(bf->hash_number, "def", bf->dictionary, bf->length);
    insert(bf->hash_number, "fgi", bf->dictionary, bf->length);

    bool exist = contains(bf->hash_number, "w", bf->dictionary, bf->length);
    bool exist1 = contains(bf->hash_number, "abc", bf->dictionary, bf->length);
    assert_true(!exist);
    printf("\n");
    assert_true(exist1);
    free(bf);
}

void test2() {
    int num_elements = 6;
    double prob = 0.1;
    bloom_filter_t *bf = bloom_filter_create(num_elements, prob);

    insert(bf->hash_number, "1", bf->dictionary, bf->length);
    insert(bf->hash_number, "2", bf->dictionary, bf->length);
    insert(bf->hash_number, "3", bf->dictionary, bf->length);
    insert(bf->hash_number, "4", bf->dictionary, bf->length);
    insert(bf->hash_number, "5", bf->dictionary, bf->length);

    bool exist = contains(bf->hash_number, "9", bf->dictionary, bf->length);
    bool exist1 = contains(bf->hash_number, "2", bf->dictionary, bf->length);
    printf("\n");
    assert_true(!exist);
    printf("\n");
    assert_true(exist1);
    free(bf);
}

void run_tests() {
    test1();
    test2();
}
