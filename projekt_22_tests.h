//
// Created by Seweryn on 23.12.2019.
//

#ifndef PROJEKT_22_PROJEKT_22_TESTS_H
#define PROJEKT_22_PROJEKT_22_TESTS_H

#include "projekt_22.h"
#include <iostream>

// ONLY FOR TESTS!

template<class T>
T* generateArray(const uli& size) {
    T* array = new T[size];
    for (uli i = 0; i < size; i++) {
        array[i] = rand() % 1005 - 5;
    }
    return array;
}

template<class T>
void printResult(const T& result) {
    std::cout << "Result: " << result << std::endl;
}

template<class TArray>
void comparePositionAndValue(TArray* array, SearchAlgorithmBase<TArray>* searchAlgorithm) {

    TArray* min = searchAlgorithm->getMin();
    TArray* max = searchAlgorithm->getMax();

    int minPosition = searchAlgorithm->getMinPosition();
    int maxPosition = searchAlgorithm->getMaxPosition();

    bool minAssertResult = array[minPosition] == *min;
    bool maxAssertResult = array[maxPosition] == *max;

    std::cout << "min value: " << *min << " at index: " << minPosition;
    std::cout << " assert: " << minAssertResult;
    std::cout << std::endl;

    std::cout << "max value: " << *max << " at index: " << maxPosition;
    std::cout << " assert: " << maxAssertResult;
    std::cout << std::endl;

    delete min;
    delete max;
}

template<class T>
void printArray(const T* array, const int& size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ", ";
    }
}

void printTestHeader(const std::string& header) {
    std::cout << std::endl << "****** " << header << " ******" << std::endl;
}

template<class TArray>
void testBorderValues(TArray* array, SearchAlgorithmBase<TArray>* searchAlgorithm) {
    array[0] = -100;
    lli resultPosition = searchAlgorithm->getMinPosition();
    TArray* resultValue = searchAlgorithm->getMin();
    bool assertPositionResult = resultPosition == 0;
    bool assertValueResult = *resultValue == -100;
    std::cout << "At 0 index should be min value: " << assertPositionResult << std::endl;
    std::cout << "Min value should be -100: " << assertValueResult << std::endl;

    delete resultValue;

    array[0] = 1001;
    resultPosition = searchAlgorithm->getMaxPosition();
    resultValue = searchAlgorithm->getMax();
    assertPositionResult = resultPosition == 0;
    assertValueResult = *resultValue == 1001;
    std::cout << "At 0 index should be max value: " << assertPositionResult << std::endl;
    std::cout << "Max value should be 1001: " << assertValueResult << std::endl;

    delete resultValue;
}


#endif //PROJEKT_22_PROJEKT_22_TESTS_H
