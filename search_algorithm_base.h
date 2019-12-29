//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_SEARCH_ALGORITHM_BASE_H
#include "search_result.h"
#define PROJEKT_22_SEARCH_ALGORITHM_BASE_H

template<class TNumber>
class SearchAlgorithmBase {
public:
    SearchAlgorithmBase() = delete;
    SearchAlgorithmBase(const TNumber* numberArray, uli);

    SearchAlgorithmBase(const SearchAlgorithmBase& searchAlgorithmBase) = default;
    SearchAlgorithmBase& operator=(const SearchAlgorithmBase& searchAlgorithmBase) = default;

    virtual TNumber* getMax() const = 0;
    virtual TNumber* getMin() const = 0;
    virtual lli getMaxPosition() const = 0;
    virtual lli getMinPosition() const = 0;
    virtual SearchResult<TNumber> getResult() const = 0;

protected:
    const TNumber* getNumberArray() const;
    const uli getNumberArraySize() const;

private:
    const TNumber* _numberArray;
    uli _size;
};


#endif //PROJEKT_22_SEARCH_ALGORITHM_BASE_H
