//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_SHARED_H


#include "utils.h"
#include <list>
#include <iostream>

#define PROJEKT_22_SHARED_H

template<class TNumber>
class SearchResult {
public:
    SearchResult() = delete;
    SearchResult& operator=(const SearchResult&);
    SearchResult(const SearchResult&);
    SearchResult(
            TNumber* maxValue,
            TNumber* minValue,
            lli maxPosition,
            lli minPosition
    );
    ~SearchResult();

    const TNumber* getMaxValue() const;
    const TNumber* getMinValue() const;
    lli getMaxPosition() const;
    lli getMinPosition() const;

    template<class TN>
    friend std::ostream& operator<<(std::ostream& ostream, const SearchResult<TN>& searchResult);

private:
    TNumber* _maxValue;
    TNumber* _minValue;
    lli _maxPosition;
    lli _minPosition;
};

#endif //PROJEKT_22_SHARED_H
