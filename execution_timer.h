//
// Created by Seweryn on 29.12.2019.
//

#ifndef PROJEKT_22_EXECUTION_TIMER_H
#include "search_algorithm_base.h"
#include <chrono>
#define PROJEKT_22_EXECUTION_TIMER_H

template<class TSearchNumber>
class ExecutionTimer {
public:
    ExecutionTimer() = delete;
    ExecutionTimer(SearchAlgorithmBase<TSearchNumber>* searchAlgorithmBase);
    ~ExecutionTimer() = default;

    ExecutionTimer(const ExecutionTimer<TSearchNumber>& executionTimer) = default;
    ExecutionTimer<TSearchNumber>& operator=(const ExecutionTimer<TSearchNumber>& executionTimer) = default;

    double getExecutionTime() const;

private:
    SearchAlgorithmBase<TSearchNumber>* _searchAlgorithm;
};


#endif //PROJEKT_22_EXECUTION_TIMER_H
