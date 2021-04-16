

#ifndef INSERTION_H
#define INSERTION_H
#include <iostream>

template <typename T>
class Insertion {
   public:
    Insertion(T *arr, int len) {
        int temp;
        // Loop through all values
        for (int i = 1; i < len; i++) {
            if (arr[i] < arr[i - 1]) {
                // loop through all values till i
                for (int j = 0; j < i; j++) {
                    // If the value at j is less that at i
                    if (arr[i] < arr[j]) {
                        // swap the values
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
    }

    // A function to print the values of an array
    void print(T *arr, int len) {
        for (int i = 0; i < len; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << std::endl;
    }
};

#endif