//
// Created by Seweryn on 16.12.2019.
//

#ifndef PROJEKT_22_SHARED_H
#include <list>
#define PROJEKT_22_SHARED_H

template<class TNumber>
class SearchResult {
public:
    SearchResult() = delete;
    SearchResult& operator=(const SearchResult&) = delete;
    SearchResult(const SearchResult&) = delete;
    SearchResult(
            const int &maxValue,
            const int &minValue,
            const std::list<int> &maxPositionsList,
            const std::list<int> &minPositionsList
    );

    const TNumber& getMaxValue() const;
    const TNumber& getMinValue() const;
    const std::list<int>& getMaxPositionsList() const;
    const std::list<int>& getMinPositionsList() const;

private:
    TNumber _maxValue;
    TNumber _minValue;
    std::list<int> _maxPositionsList;
    std::list<int> _minPositionsList;
};

#endif //PROJEKT_22_SHARED_H
