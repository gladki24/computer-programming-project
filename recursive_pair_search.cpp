//
// Created by Seweryn on 29.12.2019.
//

#include "recursive_pair_search.h"

template<class TNumber>
RecursivePairSearch<TNumber>::RecursivePairSearch(const TNumber* array, uli size)
: RecursiveSingleSearch<TNumber>(array, size) {}

template<class TNumber>
SearchResult<TNumber> RecursivePairSearch<TNumber>::getResult() const {
    if (SearchAlgorithmBase<TNumber>::getNumberArraySize() == 0) {
        return SearchResult<TNumber>();
    }

    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _getRecursiveResult(index, array, SearchResult<TNumber>());
}

template<class TNumber>
SearchResult<TNumber> RecursivePairSearch<TNumber>::_getRecursiveResult(lli& index, const TNumber* array,
        SearchResult<TNumber> searchResult) const {
    TNumber* minValue = searchResult.getMinValue() == nullptr ? nullptr : new TNumber(*searchResult.getMinValue());
    TNumber* maxValue = searchResult.getMaxValue() == nullptr ? nullptr : new TNumber(*searchResult.getMaxValue());

    lli minValuePosition = searchResult.getMinPosition();
    lli maxValuePosition = searchResult.getMaxPosition();

    uli previousIndex = index > 0 ? index - 1 : 0;
    if (array[index] > array[previousIndex]) {
        if (minValue == nullptr || *minValue > array[previousIndex]) {
            delete minValue;
            minValuePosition = previousIndex;
            minValue = new TNumber(array[previousIndex]);
            searchResult = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
        }
        if (maxValue == nullptr || *maxValue < array[index]) {
            delete maxValue;
            maxValuePosition = index;
            maxValue = new TNumber(array[index]);
            searchResult = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
        }
    } else {
        if (minValue == nullptr || *minValue > array[index]) {
            delete minValue;
            minValuePosition = index;
            minValue = new TNumber(array[index]);
            searchResult = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
        }
        if (maxValue == nullptr || *maxValue > array[previousIndex]) {
            delete maxValue;
            maxValuePosition = previousIndex;
            maxValue = new TNumber(array[previousIndex]);
            searchResult = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
        }
    }

    delete minValue;
    delete maxValue;

    if (index == 0) {
        return searchResult;
    } else {
        return _getRecursiveResult(--index, array, searchResult);
    }
}


template class RecursivePairSearch<float>;
template class RecursivePairSearch<double>;
template class RecursivePairSearch<int>;