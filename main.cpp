#include <iostream>
#include <time.h>
#include "projekt_22.h"
#include "projekt_22_tests.h"

using namespace project22;

const int ARRAY_SIZE = 1000;

int main() {
    srand(time(nullptr));

    printTestHeader("Przegladanie kolejnych elementow iteracyjnie");
    int sizeA = ARRAY_SIZE;
    int* arrayA = generateArray<int>(sizeA);
    SingleSearch<int> singleSearch = SingleSearch<int>(arrayA, sizeA);
    comparePositionAndValue<int>(arrayA, &singleSearch);

    printTestHeader("Przegladanie kolejnych elementow rekurencyjnie");
    int sizeB = ARRAY_SIZE;
    int* arrayB = generateArray<int>(sizeB);
    RecursiveSingleSearch<int> recursiveSingleSearch = RecursiveSingleSearch<int>(arrayB, sizeB);

    comparePositionAndValue<int>(arrayB, &recursiveSingleSearch);
    testBorderValues<int>(arrayB, &recursiveSingleSearch);

    printTestHeader("Przegladanie kolejnych elementow parami iteracyjnie");

    printTestHeader("Przegladanie kolejnych elementow parami rekurencyjnie");

    delete[] arrayA;
    delete[] arrayB;
    return 0;
}