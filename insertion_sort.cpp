//
// Created by Claudia Steiner on 14.06.24.
//
// insertion_sort.cpp

#include "insertion_sort.h"
#include <vector>

// Function for recursive insertion sort
void recursiveInsertionSort(std::vector<int>& arr, int n) {
    if (n <= 1) {
        return;
    }

    recursiveInsertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// Function for non-recursive insertion sort
void nonRecursiveInsertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
