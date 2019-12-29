//
// Created by Seweryn on 29.12.2019.
//

#ifndef PROJEKT_22_RECURSIVE_PAIR_SEARCH_H

#include "recursive_single_search.h"
#define PROJEKT_22_RECURSIVE_PAIR_SEARCH_H

template<class TNumber>
class RecursivePairSearch : public RecursiveSingleSearch<TNumber> {
public:
    RecursivePairSearch() = delete;
    RecursivePairSearch(const TNumber*, uli size);
    ~RecursivePairSearch() = default;

    RecursivePairSearch(const RecursivePairSearch& recursivePairSearch) = default;
    RecursivePairSearch& operator=(const RecursivePairSearch& recursivePairSearch) = default;

    SearchResult<TNumber> getResult() const override;

private:
    SearchResult<TNumber> _getRecursiveResult(lli& index, const TNumber* array,
                                              SearchResult<TNumber> searchResult) const;
};


#endif //PROJEKT_22_RECURSIVE_PAIR_SEARCH_H
