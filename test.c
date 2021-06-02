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
    double prob = 0.1;
    char *test_words[5] = {"abc", "bcd", "cde", "def", "fgi"};
    int num_elements = sizeof(test_words) / sizeof(test_words[0]);
    bloom_filter_t *bf = bloom_filter_create(num_elements, prob);
    for (int i = 0; i < num_elements; i++) {
        insert(bf->hash_number, test_words[i], bf->dictionary, bf->length);
    }
    bool exist = contains(bf->hash_number, "w", bf->dictionary, bf->length);
    bool exist1 = contains(bf->hash_number, "abc", bf->dictionary, bf->length);
    assert_true(!exist);
    printf("\n");
    assert_true(exist1);
    free(bf);
}

void test2() {
    double prob = 0.1;
    char *test_numbers[5] = {"1", "2", "3", "4", "5"};
    int num_elements = sizeof(test_numbers) / sizeof(test_numbers[0]);
    bloom_filter_t *bf = bloom_filter_create(num_elements, prob);
    for (int i = 0; i < num_elements; i++) {
        insert(bf->hash_number, test_numbers[i], bf->dictionary, bf->length);
    }
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
