//
// Created by Seweryn on 16.12.2019.
//

#include "recursive_single_search.h"

template<class TNumber>
RecursiveSingleSearch<TNumber>::RecursiveSingleSearch(const TNumber *array, uli size): SearchAlgorithmBase<TNumber>(array, size) {}

template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::getMax() const {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMax(index, array, nullptr);
}

template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::getMin() const {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMin(index, array, nullptr);
}

template<class TNumber>
lli RecursiveSingleSearch<TNumber>::getMaxPosition() const {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMaxPosition(index, array, nullptr);
}

template<class TNumber>
lli RecursiveSingleSearch<TNumber>::getMinPosition() const {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMinPosition(index, array, nullptr);
}

template<class TNumber>
SearchResult<TNumber> RecursiveSingleSearch<TNumber>::getResult() const {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetResult(index, array, SearchResult<TNumber>(nullptr, nullptr, -1, -1));
}


template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::_recursiveGetMax(lli& index, const TNumber* array, TNumber* result) const {
    if (result == nullptr || *result < array[index]) {
        delete result;
        result = new TNumber(array[index]);
    }

    if (index == 0) {
        return result;
    } else {
        return _recursiveGetMax(--index, array, result);
    }
}

template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::_recursiveGetMin(lli& index, const TNumber* array, TNumber* result) const {
    if (result == nullptr || *result > array[index]) {
        delete result;
        result = new TNumber(array[index]);
    }

    if (index == 0) {
        return result;
    } else {
        return _recursiveGetMin(--index, array, result);
    }
}

template<class TNumber>
lli RecursiveSingleSearch<TNumber>::_recursiveGetMaxPosition(lli& index, const TNumber* array, TNumber* value, lli result) const {
    if (value == nullptr || *value < array[index]) {
        delete value;
        value = new TNumber(array[index]);
        result = index;
    }

    if (index == 0) {
        delete value;
        return result;
    } else {
        return _recursiveGetMaxPosition(--index, array, value, result);
    }
}

template<class TNumber>
lli RecursiveSingleSearch<TNumber>::_recursiveGetMinPosition(lli& index, const TNumber* array, TNumber* value, lli result) const {
    if (value == nullptr || *value > array[index]) {
        delete value;
        value = new TNumber(array[index]);
        result = index;
    }

    if (index == 0) {
        delete value;
        return result;
    } else {
        return _recursiveGetMinPosition(--index, array, value, result);
    }
}

template<class TNumber>
SearchResult<TNumber> RecursiveSingleSearch<TNumber>::_recursiveGetResult(lli &index, const TNumber *array,
        SearchResult<TNumber> searchResult) const {

    TNumber* minValue = searchResult.getMinValue() == nullptr ? nullptr : new TNumber(*searchResult.getMinValue());
    TNumber* maxValue = searchResult.getMaxValue() == nullptr ? nullptr : new TNumber(*searchResult.getMaxValue());

    lli minValuePosition = searchResult.getMinPosition();
    lli maxValuePosition = searchResult.getMaxPosition();

    if (minValue == nullptr || *minValue > array[index]) {
        delete minValue;

        minValuePosition = index;
        minValue = new TNumber(array[index]);
        searchResult = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
    }

    if (maxValue == nullptr || *maxValue < array[index]) {
        delete maxValue;

        maxValuePosition = index;
        maxValue = new TNumber(array[index]);
        searchResult = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
    }

    delete minValue;
    delete maxValue;

    if (index == 0) {
        return searchResult;
    } else {
        return _recursiveGetResult(--index, array, searchResult);
    }
}

template class RecursiveSingleSearch<float>;
template class RecursiveSingleSearch<int>;
template class RecursiveSingleSearch<double>;