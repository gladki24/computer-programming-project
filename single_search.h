//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_SINGLE_SEARCH_H
#include "search_algorithm_base.h"
#define PROJEKT_22_SINGLE_SEARCH_H

template<class TNumber>
class SingleSearch : public SearchAlgorithmBase<TNumber> {
public:
    SingleSearch(const TNumber* array, uli size);
    TNumber* getMax() override;
    TNumber* getMin() override;
    lli getMaxPosition() override;
    lli getMinPosition() override;
};

#endif //PROJEKT_22_SINGLE_SEARCH_H
