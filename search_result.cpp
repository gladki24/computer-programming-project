//
// Created by Seweryn on 16.12.2019.
//

#include "search_result.h"

template<class TNumber>
SearchResult<TNumber>::SearchResult(): _maxValue(nullptr), _minValue(nullptr), _maxPosition(-1), _minPosition(-1) {}

template<class TNumber>
SearchResult<TNumber>::SearchResult(
        TNumber* maxValue,
        TNumber* minValue,
        lli maxPositionsList,
        lli minPositionsList
): _maxPosition(maxPositionsList), _minPosition(minPositionsList) {
    _maxValue = maxValue == nullptr ? nullptr : new TNumber(*maxValue);
    _minValue = minValue == nullptr ? nullptr : new TNumber(*minValue);
}

template<class TNumber>
SearchResult<TNumber>::~SearchResult() {
    delete _maxValue;
    delete _minValue;
}

template<class TNumber>
SearchResult<TNumber>::SearchResult(const SearchResult& searchResult) {
    _minPosition = searchResult._minPosition;
    _maxPosition = searchResult._maxPosition;

    _maxValue = searchResult._maxValue == nullptr ? nullptr : new TNumber(*searchResult._maxValue);
    _minValue = searchResult._minValue == nullptr ? nullptr : new TNumber(*searchResult._minValue);
}

template<class TNumber>
SearchResult<TNumber>& SearchResult<TNumber>::operator=(const SearchResult& searchResult) {
    _minPosition = searchResult._minPosition;
    _maxPosition = searchResult._maxPosition;

    delete _maxValue;
    delete _minValue;

    _maxValue = searchResult._maxValue == nullptr ? nullptr : new TNumber(*searchResult._maxValue);
    _minValue = searchResult._minValue == nullptr ? nullptr : new TNumber(*searchResult._minValue);

    return *this;
}

template<class TNumber>
const TNumber* SearchResult<TNumber>::getMaxValue() const {
    return _maxValue;
}

template<class TNumber>
const TNumber* SearchResult<TNumber>::getMinValue() const {
    return _minValue;
}

template<class TNumber>
lli SearchResult<TNumber>::getMaxPosition() const {
    return _maxPosition;
}

template<class TNumber>
lli SearchResult<TNumber>::getMinPosition() const {
    return _minPosition;
}

template class SearchResult<float>;
template class SearchResult<int>;
template class SearchResult<double>;
