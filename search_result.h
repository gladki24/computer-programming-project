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
    SearchResult();
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

    template<class UNumber>
    friend std::ostream& operator<<(std::ostream& ostream, const SearchResult<UNumber>& searchResult);

private:
    TNumber* _maxValue;
    TNumber* _minValue;
    lli _maxPosition;
    lli _minPosition;
};

template<class TNumber>
std::ostream& operator<<(std::ostream& ostream, const SearchResult<TNumber>& searchResult) {
    ostream << "Max: " << *searchResult.getMaxValue() << " at: " << searchResult.getMaxPosition();
    ostream << ", min: " << *searchResult.getMinValue() << " at: " << searchResult.getMinPosition() << std::endl;
    return ostream;
}


#endif //PROJEKT_22_SHARED_H
