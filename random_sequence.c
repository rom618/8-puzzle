#include "random_sequence.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffle(int *array, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to generate a random number sequence
void random_number_sequence(int *array, int length) {
    // Initialize the array with values from 0 to length-1
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }

    // Shuffle the array
    shuffle(array, length);
}
