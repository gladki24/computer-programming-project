//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_SINGLE_SEARCH_H
#include "search_algorithm_base.h"
#define PROJEKT_22_SINGLE_SEARCH_H

template<class TNumber>
class SingleSearch : public SearchAlgorithmBase<TNumber> {
public:
    SingleSearch() = delete;
    SingleSearch(const TNumber* array, uli size);
    ~SingleSearch() = default;

    SingleSearch(const SingleSearch& singleSearch) = default;
    SingleSearch& operator=(const SingleSearch& singleSearch) = default;

    TNumber* getMax() const override;
    TNumber* getMin() const override;
    lli getMaxPosition() const override;
    lli getMinPosition() const override;
    SearchResult<TNumber> getResult() const override;
};

#endif //PROJEKT_22_SINGLE_SEARCH_H
