#include <iostream>
#include <time.h>
#include "projekt_22.h"
#include "projekt_22_tests.h"

using namespace project22;

int main() {
    srand(time(nullptr));
    int size = 1000;
    int* arrayA = generateArray<int>(size);
    SingleSearch<int> singleSearch = SingleSearch<int>(arrayA, size);
    printTestHeader("Przegladanie kolejnych elementow iteracyjnie");
    comparePositionAndValue<int>(arrayA, &singleSearch);

    printTestHeader("Przegladanie kolejnych elementow rekurencyjnie");

    delete arrayA;
    return 0;
}