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

    RecursiveSingleSearch(const RecursiveSingleSearch& recursiveSingleSearch) = default;
    RecursiveSingleSearch& operator=(const RecursiveSingleSearch& searchAlgorithmBase) = default;

    TNumber* getMax() override;
    TNumber* getMin() override;
    lli getMaxPosition() override;
    lli getMinPosition() override;

private:
    TNumber* _recursiveGetMax(lli& index, const TNumber* array, TNumber* result = nullptr);
    TNumber* _recursiveGetMin(lli& index, const TNumber* array, TNumber* result = nullptr);
    lli _recursiveGetMaxPosition(lli& index, const TNumber* array, TNumber* value, lli result = -1);
    lli _recursiveGetMinPosition(lli& index, const TNumber* array, TNumber* value, lli result = -1);
};


#endif //PROJEKT_22_RECURSIVE_SINGLE_SEARCH_H
