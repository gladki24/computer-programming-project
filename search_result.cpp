//
// Created by Seweryn on 16.12.2019.
//

#include "search_result.h"

// SearchResult class
template<class TNumber>
SearchResult<TNumber>::SearchResult(
        TNumber* maxValue,
        TNumber* minValue,
        lli maxPositionsList,
        lli minPositionsList
): _maxValue(maxValue),
   _minValue(minValue),
   _maxPosition(maxPositionsList),
   _minPosition(minPositionsList) {}

template<class TNumber>
SearchResult<TNumber>::~SearchResult() {
    delete _maxValue;
    delete _minValue;
}

template<class TNumber>
SearchResult<TNumber>::SearchResult(const SearchResult& searchResult) {
    _minPosition = searchResult._minPosition;
    _maxPosition = searchResult._maxPosition;

    delete _maxValue;
    delete _minValue;

    _maxValue = new TNumber(*searchResult._maxValue);
    _minValue = new TNumber(*searchResult._minValue);
}

template<class TNumber>
SearchResult<TNumber>& SearchResult<TNumber>::operator=(const SearchResult& searchResult) {
    _minPosition = searchResult._minPosition;
    _maxPosition = searchResult._maxPosition;

    delete _maxValue;
    delete _minValue;

    _maxValue = new TNumber(*searchResult._maxValue);
    _minValue = new TNumber(*searchResult._minValue);

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

template<class TNumber>
std::ostream& operator<<(std::ostream& ostream, const SearchResult<TNumber>& searchResult) {
    ostream << "Max: " << searchResult.getMaxValue() << "at: " << searchResult.getMaxPosition();
    ostream << " min: " << searchResult.getMinValue() << "at: " << searchResult.getMinPosition();
    return ostream;
}

template class SearchResult<float>;
template class SearchResult<int>;
template class SearchResult<double>;
