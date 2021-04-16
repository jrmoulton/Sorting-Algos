
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>

template <typename T>
class Quick {
   public:
    // The constructor just calles the recursive quicksort function
    Quick(T *arr, int len) { quicksort(arr, 0, len - 1); }

    // This is a function that will be called recursively
    void quicksort(T *arr, int low, int high) {
        int mid = 0;
        // Once the low index > high index that section is sorted
        if (low < high) {
            // Get new mid point
            mid = partition(arr, low, high);
            // Recursively sort the two unsorted sections
            quicksort(arr, low, mid);
            quicksort(arr, mid + 1, high);
        }
    }

    int partition(T *arr, int low, int high) {
        int temp = 0;
        // This does always floor the division but that is exaclty what we want
        int pivot = arr[(high + low) / 2];
        int i = low - 1;
        int j = high + 1;
        // run until the indecies cross (i>= j)
        while (true) {
            i += 1;
            j -= 1;
            // Find the first element that is >= the pivot
            while (arr[i] < pivot) {
                i += 1;
            }
            // Find the element first from the back that is > pivot
            while (arr[j] > pivot) {
                j -= 1;
            }
            // If the indicies cross, return j as the mid point
            if (i >= j) {
                return j;
            }
            // if the indicies don't cross swap the values on either side of the
            // middle
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
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
