//
// Created by Seweryn on 16.12.2019.
//

#include "search_algorithm_base.h"

template<class TNumber>
SearchAlgorithmBase<TNumber>::SearchAlgorithmBase(const TNumber* numberArray, uli size)
: _numberArray(numberArray), _size(size)
{ }

template<class TNumber>
const TNumber* SearchAlgorithmBase<TNumber>::getNumberArray() const  {
    return _numberArray;
}

template<class TNumber>
const uli SearchAlgorithmBase<TNumber>::getNumberArraySize() const {
    return _size;
}

template class SearchAlgorithmBase<float>;
template class SearchAlgorithmBase<int>;
template class SearchAlgorithmBase<double>;