

#ifndef SELECTION_H
#define SELECTION_H
#include <iostream>

template <typename T>
class Selection {
   public:
    Selection(T *arr, int len) {
        // Initialize an array that is will hold the sorted values
        T sorted[len];
        T minimum = 1000;
        int index = 0;
        int pos = 0;
        int oglen = len;
        // While we haven't moved all the values to the sorted array
        while (len > 0) {
            minimum = 1000;
            // Find the minimum value in the array
            for (int i = 0; i < len; i++) {
                if (arr[i] <= minimum) {
                    minimum = arr[i];
                    index = i;
                }
            }
            // set the next position in the sorted array to the lowest value
            sorted[pos] = minimum;
            pos += 1;
            // Remove the element from the unsorted array and shift elements
            for (int i = index; i < len - 1; i++) {
                arr[i] = arr[i + 1];
            }
            len -= 1;
        }
        // Once finished fill the old array with the sorted values
        for (int i = 0; i < oglen; i++) {
            arr[i] = sorted[i];
        }
    }

    // Function to print the values of the array
    void print(T *arr, int len) {
        for (int i = 0; i < len; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << std::endl;
    }
};

#endif