//
// Created by Seweryn on 16.12.2019.
//

#include "search_result.h"

// SearchResult class
template<class TNumber>
SearchResult<TNumber>::SearchResult(
        const int& maxValue,
        const int& minValue,
        const std::list<int>& maxPositionsList,
        const std::list<int>& minPositionsList
): _maxValue(maxValue),
   _minValue(minValue),
   _maxPositionsList(maxPositionsList),
   _minPositionsList(minPositionsList) {}

template<class TNumber>
const TNumber &SearchResult<TNumber>::getMaxValue() const {
    return _maxValue;
}

template<class TNumber>
const TNumber& SearchResult<TNumber>::getMinValue() const {
    return _minValue;
}

template<class TNumber>
const std::list<int> &SearchResult<TNumber>::getMaxPositionsList() const {
    return _maxPositionsList;
}

template<class TNumber>
const std::list<int> &SearchResult<TNumber>::getMinPositionsList() const {
    return _minPositionsList;
}