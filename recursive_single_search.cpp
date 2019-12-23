//
// Created by Seweryn on 16.12.2019.
//

#include "recursive_single_search.h"

template<class TNumber>
RecursiveSingleSearch<TNumber>::RecursiveSingleSearch(const TNumber *array, uli size): SearchAlgorithmBase<TNumber>(array, size) {}

template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::getMax() {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMax(index, array, nullptr);
}

template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::getMin() {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMin(index, array, nullptr);
}

template<class TNumber>
lli RecursiveSingleSearch<TNumber>::getMaxPosition() {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMaxPosition(index, array, nullptr);
}

template<class TNumber>
lli RecursiveSingleSearch<TNumber>::getMinPosition() {
    lli index = SearchAlgorithmBase<TNumber>::getNumberArraySize() - 1;
    const TNumber* array = SearchAlgorithmBase<TNumber>::getNumberArray();

    return _recursiveGetMinPosition(index, array, nullptr);
}

template<class TNumber>
TNumber* RecursiveSingleSearch<TNumber>::_recursiveGetMax(lli& index, const TNumber* array, TNumber* result) {
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
TNumber* RecursiveSingleSearch<TNumber>::_recursiveGetMin(lli& index, const TNumber* array, TNumber* result) {
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
lli RecursiveSingleSearch<TNumber>::_recursiveGetMaxPosition(lli& index, const TNumber* array, TNumber* value, lli result) {
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
lli RecursiveSingleSearch<TNumber>::_recursiveGetMinPosition(lli& index, const TNumber* array, TNumber* value, lli result) {
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



template class RecursiveSingleSearch<float>;
template class RecursiveSingleSearch<int>;
template class RecursiveSingleSearch<double>;