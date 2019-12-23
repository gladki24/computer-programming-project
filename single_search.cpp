//
// Created by Seweryn on 16.12.2019.
//

#include "single_search.h"

template<class TNumber>
SingleSearch<TNumber>::SingleSearch(const TNumber *array, const uli size): SearchAlgorithmBase<TNumber>(array, size) {}

template<class TNumber>
TNumber* SingleSearch<TNumber>::getMax() {
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
TNumber* SingleSearch<TNumber>::getMin() {
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
lli SingleSearch<TNumber>::getMaxPosition() {
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();
    TNumber* minValue = nullptr;
    uli maxValuePosition = -1;
    if (size == 0) {
        maxValuePosition;
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
lli SingleSearch<TNumber>::getMinPosition() {
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();
    TNumber* minValue = nullptr;
    uli minValuePosition = -1;
    if (size == 0) {
        minValuePosition;
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

template class SingleSearch<float>;
template class SingleSearch<double>;
template class SingleSearch<int>;