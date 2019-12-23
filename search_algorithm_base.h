//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_SEARCH_ALGORITHM_BASE_H
#include "search_result.h"
#define PROJEKT_22_SEARCH_ALGORITHM_BASE_H

typedef unsigned long int uli;
typedef long long int lli;

template<class TNumber>
class SearchAlgorithmBase {
public:
    SearchAlgorithmBase() = delete;
    SearchAlgorithmBase(const TNumber* numberArray, uli);

    SearchAlgorithmBase(const SearchAlgorithmBase& searchAlgorithmBase) = default;
    SearchAlgorithmBase& operator=(const SearchAlgorithmBase& searchAlgorithmBase) = default;

    // TODO   virtual SearchResult<TNumber> getSearchResult() = 0;
    virtual TNumber* getMax() = 0;
    virtual TNumber* getMin() = 0;
    virtual lli getMaxPosition() = 0;
    virtual lli getMinPosition() = 0;

protected:
    const TNumber* getNumberArray();
    const uli getNumberArraySize();

private:
    const TNumber* _numberArray;
    uli _size;
};


#endif //PROJEKT_22_SEARCH_ALGORITHM_BASE_H
