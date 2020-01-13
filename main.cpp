#include <iostream>
#include <time.h>
#include "projekt_22.h"
#include "projekt_22_tests.h"

using namespace project22;

const int ARRAY_SIZE = 8000;
const int TIMER_SIZE = 8000;

int main() {
    srand(time(nullptr));

    printTestHeader("Przegladanie kolejnych elementow iteracyjnie");
    int sizeA = ARRAY_SIZE;
    int* arrayA = generateArray<int>(sizeA);
    SingleSearch<int> singleSearch = SingleSearch<int>(arrayA, sizeA);
    comparePositionAndValue<int>(arrayA, &singleSearch);
    testGetResult<int>(&singleSearch);

    printTestHeader("Przegladanie kolejnych elementow rekurencyjnie");
    int sizeB = ARRAY_SIZE;
    int* arrayB = generateArray<int>(sizeB);
    RecursiveSingleSearch<int> recursiveSingleSearch = RecursiveSingleSearch<int>(arrayB, sizeB);

    comparePositionAndValue<int>(arrayB, &recursiveSingleSearch);
    testBorderValues<int>(arrayB, &recursiveSingleSearch);
    testGetResult<int>(&recursiveSingleSearch);

    printTestHeader("Przegladanie kolejnych elementow parami iteracyjnie");
    int sizeC = ARRAY_SIZE;
    int* arrayC = generateArray<int>(sizeC);
    PairSearch<int> pairSearch = PairSearch<int>(arrayC, sizeC);

    comparePositionAndValue<int>(arrayC, &pairSearch);
    testGetResult<int>(&pairSearch);

    printTestHeader("Przegladanie kolejnych elementow parami rekurencyjnie");
    int sizeD = ARRAY_SIZE;
    int* arrayD = generateArray<int>(sizeD);
    RecursivePairSearch<int> recursivePairSearch = RecursivePairSearch<int>(arrayD, sizeD);

    comparePositionAndValue<int>(arrayD, &recursivePairSearch);
    testBorderValues<int>(arrayD, &recursivePairSearch);
    testGetResult<int>(&recursivePairSearch);

    printTestHeader("Mierzenie czasów wykonania");
    double* timerArray = generateArray<double>(TIMER_SIZE);

    SingleSearch<double> singleSearchTimer = SingleSearch<double>(timerArray, TIMER_SIZE);
    PairSearch<double> pairSearchTimer = PairSearch<double>(timerArray, TIMER_SIZE);
    RecursiveSingleSearch<double> recursiveSingleSearchTimer = RecursiveSingleSearch<double>(timerArray, TIMER_SIZE);
    RecursivePairSearch<double> recursivePairSearchTimer = RecursivePairSearch<double>(timerArray, TIMER_SIZE);

    ExecutionTimer<double> sst = ExecutionTimer<double>(&singleSearchTimer);
    ExecutionTimer<double> rsst = ExecutionTimer<double>(&recursiveSingleSearchTimer);
    ExecutionTimer<double> pst = ExecutionTimer<double>(&pairSearchTimer);
    ExecutionTimer<double> rpst = ExecutionTimer<double>(&recursivePairSearchTimer);

    std::cout << "Pojedynczo iteracyjnie: " << sst.getExecutionTime() << std::endl;
    std::cout << "Wynik: " << singleSearchTimer.getResult() << std::endl;

    std::cout << "Pojedynczo rekurencyjnie: " << rsst.getExecutionTime() << std::endl;
    std::cout << "Wynik: " << recursiveSingleSearchTimer.getResult() << std::endl;

    std::cout << "Parami iteracyjnie: " << pst.getExecutionTime() << std::endl;
    std::cout << "Wynik: " << pairSearchTimer.getResult() << std::endl;

    std::cout << "Parami rekurencyjnie: " << rpst.getExecutionTime() << std::endl;
    std::cout << "Wynik: " << recursivePairSearchTimer.getResult() << std::endl;

    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
    delete[] arrayD;
    delete[] timerArray;

    return 0;
}