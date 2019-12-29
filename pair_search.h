//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_PAIR_SEARCH_H
#include "single_search.h"
#define PROJEKT_22_PAIR_SEARCH_H

template<class TNumber>
class PairSearch : public SingleSearch<TNumber> {
public:
    PairSearch() = delete;
    PairSearch(const TNumber* array, uli size);
    ~PairSearch() = default;

    PairSearch(const PairSearch& pairSearch) = default;
    PairSearch& operator=(const PairSearch& pairSearch) = default;

    SearchResult<TNumber> getResult() const override;
};


#endif //PROJEKT_22_PAIR_SEARCH_H
