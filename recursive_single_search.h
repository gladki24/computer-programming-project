//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_RECURSIVE_SINGLE_SEARCH_H
#include "search_algorithm_base.h"
#define PROJEKT_22_RECURSIVE_SINGLE_SEARCH_H

template<class TNumber>
class RecursiveSingleSearch : public SearchAlgorithmBase<TNumber> {
public:
    RecursiveSingleSearch() = delete;
    RecursiveSingleSearch(const TNumber* array, uli size);
    ~RecursiveSingleSearch() = default;

    RecursiveSingleSearch(const RecursiveSingleSearch& recursiveSingleSearch) = default;
    RecursiveSingleSearch& operator=(const RecursiveSingleSearch& searchAlgorithmBase) = default;

    TNumber* getMax() const override;
    TNumber* getMin() const override;
    lli getMaxPosition() const override;
    lli getMinPosition() const override;
    SearchResult<TNumber> getResult() const override;

private:
    TNumber* _recursiveGetMax(lli& index, const TNumber* array, TNumber* result = nullptr) const;
    TNumber* _recursiveGetMin(lli& index, const TNumber* array, TNumber* result = nullptr) const;
    lli _recursiveGetMaxPosition(lli& index, const TNumber* array, TNumber* value, lli result = -1) const;
    lli _recursiveGetMinPosition(lli& index, const TNumber* array, TNumber* value, lli result = -1) const;
    SearchResult<TNumber> _recursiveGetResult(lli& index, const TNumber* array, SearchResult<TNumber> searchResult) const;
};


#endif //PROJEKT_22_RECURSIVE_SINGLE_SEARCH_H
