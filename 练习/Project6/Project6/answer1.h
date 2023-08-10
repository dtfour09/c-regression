#pragma once
#include<iostream>


template <typename T>
void swapMinAndFirstMaxAndLast(T arr[], int length) {
    T minVal = arr[0];
    T maxVal = arr[0];
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < length; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    std::cout << maxIndex << " L and R  " << minIndex << std::endl;

    std::swap(arr[0], arr[minIndex]);

    std::swap(arr[length - 1], arr[maxIndex]);
}

