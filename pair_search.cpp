//
// Created by Seweryn on 16.12.2019.
//

#include "pair_search.h"

template<class TNumber>
PairSearch<TNumber>::PairSearch(const TNumber *array, uli size): SingleSearch<TNumber>(array, size) {}

template<class TNumber>
SearchResult<TNumber> PairSearch<TNumber>::getResult() const {
    const uli size = SearchAlgorithmBase<TNumber>::getNumberArraySize();
    TNumber* maxValue = nullptr;
    TNumber* minValue = nullptr;
    uli maxValuePosition = -1;
    uli minValuePosition = -1;

    if (size == 0) {
        return SearchResult<TNumber>();
    }

    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();
    for (uli i = 0; i < size; i += 2) {
        uli nextIndex = i + 1 >= size ? i : i + 1;
        if (array[i] > array[i + 1]) {
            if (maxValue == nullptr || array[i] > *maxValue) {
                delete maxValue;

                maxValuePosition = i;
                maxValue = new TNumber(array[i]);
            }
            if (minValue == nullptr || array[nextIndex] < *minValue) {
                delete minValue;

                minValuePosition = i + 1;
                minValue = new TNumber(array[nextIndex]);
            }
        } else {
            if (maxValue == nullptr || array[nextIndex] > *maxValue) {
                delete maxValue;

                maxValuePosition = i + 1;
                maxValue = new TNumber(array[i]);
            }
            if (minValue == nullptr || array[i] < *minValue) {
                delete minValue;

                minValuePosition = i;
                minValue = new TNumber(array[nextIndex]);
            }
        }
    }
    SearchResult<TNumber> result = SearchResult<TNumber>(maxValue, minValue, maxValuePosition, minValuePosition);
    delete maxValue;
    delete minValue;
    return result;
}

template class PairSearch<int>;
template class PairSearch<float>;
template class PairSearch<double>;