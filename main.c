#include <stdio.h>
#include "bloom_filter.h"
#include "test.h"


/**
 * Insert n elements in array[m]. array[hash(element)] = 1, k times
 * k = ln2*m/n
 * m = -(n*lnp/ln2^2)
 */

static int count_lines(char *filename) {
    // count the number of lines in the file
    FILE *fp = fopen(filename, "r");
    int ch;
    int lines = 0;
    if (fp == NULL)
        return 0;
    lines++;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n')
            lines++;
    }
    fclose(fp);
    return lines;
}

int main(int argc, char *argv[]) {
    //run tests or print help
    if (argc == 2) {
        if (strcmp(argv[1], "-t") == 0) {
            run_tests();
        } else if (strcmp(argv[1], "-h") == 0) {
            printf("filename.txt p word: Add all strings from file to bloom_filter and check, "
                   "contains element with probability 'p'\n"
                   "-t: Run tests");
        }
    }
        //run app
    else if (argc == 4) {
        //prob error
        double probability = 0.0;
        sscanf(argv[2], "%lf", &probability);
        //check correct type of prob
        if (probability == 0.0) {
            printf("Error. Incorrect type of probability");
            exit(1);
        }
        //check correct value of prob
        if (probability < 0 || probability > 1) {
            printf("Error. Probability must be positive number and less then one");
            exit(1);
        }
        //open file
        FILE *fp;
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("%s", "Error, file doesnt exist");
            exit(1);
        }
        int words = count_lines(argv[1]);
        int index = 0;
        char line[128];
        char **names = (char **) malloc(words * sizeof(char));
        //read file
        while (!feof(fp)) {
            fscanf(fp, "%127s", line);
            names[index] = strdup(line);
            index++;
        }
        fclose(fp);
        //init bloom filter
        bloom_filter_t *bf = bloom_filter_create(words, probability);
        //fill dictionary
        for (int i = 0; i < words; i++) {
            insert(bf->hash_number, names[i], bf->dictionary, bf->length);
        }
        //check contains
        int exist = contains(bf->hash_number, argv[3], bf->dictionary, bf->length);
        printf("%s", exist ? "Probably contains" : "false");
        free(names);
        free(bf->dictionary);
        free(bf);
    } else {
        printf("Incorrect number of argument");
        exit(1);
    }
    return 0;
}
