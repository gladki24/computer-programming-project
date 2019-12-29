//
// Created by Seweryn on 29.12.2019.
//

#include "execution_timer.h"

template<class TSearchNumber>
ExecutionTimer<TSearchNumber>::ExecutionTimer(SearchAlgorithmBase<TSearchNumber> *searchAlgorithmBase)
: _searchAlgorithm(searchAlgorithmBase) { }

template<class TSearchNumber>
double ExecutionTimer<TSearchNumber>::getExecutionTime() const {
    auto start = std::chrono::steady_clock::now();
    _searchAlgorithm->getResult();
    auto end = std::chrono::steady_clock::now();
    auto result = end - start;

    return std::chrono::duration<double>(result).count();
}

template class ExecutionTimer<double>;
template class ExecutionTimer<int>;
template class ExecutionTimer<float>;