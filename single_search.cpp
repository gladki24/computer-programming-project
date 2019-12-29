//
// Created by Seweryn on 16.12.2019.
//

#include "single_search.h"

template<class TNumber>
SingleSearch<TNumber>::SingleSearch(const TNumber *array, const uli size): SearchAlgorithmBase<TNumber>(array, size) {}

template<class TNumber>
TNumber* SingleSearch<TNumber>::getMax() const {
    TNumber* result = nullptr;
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();

    if (size == 0) {
        return nullptr;
    }

    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();
    for (uli i = 0; i < size; i++ ) {
        if (result == nullptr || array[i] > *result) {
            delete result;
            result = new TNumber(array[i]);
        }
    }
    return result;
}

template<class TNumber>
TNumber* SingleSearch<TNumber>::getMin() const {
    TNumber* result = nullptr;
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();

    if (size == 0) {
        return nullptr;
    }

    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();
    for (uli i = 0; i < size; i++) {
        if (result == nullptr || array[i] < *result) {
            delete result;
            result = new TNumber(array[i]);
        }
    }
    return result;
}

template<class TNumber>
lli SingleSearch<TNumber>::getMaxPosition() const {
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();
    TNumber* minValue = nullptr;
    uli maxValuePosition = -1;
    if (size == 0) {
        return maxValuePosition;
    }

    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();
    for (uli i = 0; i < size; i++) {
        if (minValue == nullptr || array[i] > *minValue) {
            delete minValue;
            minValue = new TNumber(array[i]);
            maxValuePosition = i;
        }
    }
    delete minValue;
    return maxValuePosition;
}

template<class TNumber>
lli SingleSearch<TNumber>::getMinPosition() const {
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();
    TNumber* minValue = nullptr;
    uli minValuePosition = -1;
    if (size == 0) {
        return minValuePosition;
    }

    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();
    for (uli i = 0; i < size; i++) {
        if (minValue == nullptr || array[i] < *minValue) {
            delete minValue;
            minValue = new TNumber(array[i]);
            minValuePosition = i;
        }
    }
    delete minValue;
    return minValuePosition;
}

template<class TNumber>
SearchResult<TNumber> SingleSearch<TNumber>::getResult() const {
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();
    TNumber* maxValue = nullptr;
    TNumber* minValue = nullptr;
    uli maxValuePosition = -1;
    uli minValuePosition = -1;

    if (size == 0) {
        return SearchResult<TNumber>();
    }

    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();
    for (uli i = 0; i < size; i++) {
        if (minValue == nullptr || array[i] < *minValue) {
            delete minValue;
            minValue = new TNumber(array[i]);
            minValuePosition = i;
        }

        if (maxValue == nullptr || array[i] > *maxValue) {
            delete maxValue;
            maxValue = new TNumber(array[i]);
            maxValuePosition = i;
        }
    }
    SearchResult<TNumber> result = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
    delete maxValue;
    delete minValue;
    return result;
}

template class SingleSearch<float>;
template class SingleSearch<double>;
template class SingleSearch<int>;