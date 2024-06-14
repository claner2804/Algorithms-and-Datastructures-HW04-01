// main.cpp

#include "insertion_sort.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int arraySize = 1000;
    const int testRuns = 10;
    std::srand(std::time(nullptr));

    // Generate a large array with more than 1000 elements
    std::vector<int> arr(arraySize);
    for (int& val : arr) {
        val = std::rand();
    }

    std::vector<int> arrCopy = arr;

    // Measure time for recursive insertion sort
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < testRuns; ++i) {
        arr = arrCopy;
        recursiveInsertionSort(arr, arr.size());
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double avgTimeRecursive = duration.count() / testRuns;

    // Measure time for non-recursive insertion sort
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < testRuns; ++i) {
        arr = arrCopy;
        nonRecursiveInsertionSort(arr);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    double avgTimeNonRecursive = duration.count() / testRuns;

    std::cout << "Average time for recursive insertion sort: " << avgTimeRecursive << " seconds." << std::endl;
    std::cout << "Average time for non-recursive insertion sort: " << avgTimeNonRecursive << " seconds." << std::endl;

    // Test with an array of 50 elements
    const int smallArraySize = 50;
    std::vector<int> smallArr(smallArraySize);
    for (int& val : smallArr) {
        val = std::rand() % 100; // smaller range for clarity in the example
    }

    std::cout << "Input array of 50 elements:" << std::endl;
    printArray(smallArr);

    // Sort the small array and print results
    nonRecursiveInsertionSort(smallArr);
    std::cout << "Sorted array of 50 elements:" << std::endl;
    printArray(smallArr);

    return 0;
}
