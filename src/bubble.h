
#ifndef BUBBLE_H
#define BUBBLE_H
#include <iostream>

template <typename T>
class Bubble {
   public:
    Bubble(T *arr, int len) {
        // Variable to track when we have made a full pass without swaps
        bool finished = false;
        // loop over array
        for (int i = 0; i < len; i++) {
            // set early finish to true (it might get changed in the next for
            // loop)
            finished = true;
            for (int j = i; j < len - 1; j++) {
                // If the elements are not in order swap them and set early
                // finish to false
                if (arr[j] > arr[j + 1]) {
                    finished = false;
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            // If finished full pass without swaps return early
            if (finished) {
                return;
            }
        }
    }

    // Function to print the elemts of an array
    void print(T *arr, int len) {
        for (int i = 0; i < len; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << std::endl;
    }
};

#endif