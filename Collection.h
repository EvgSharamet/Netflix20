#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "VideoContent.h"
#include "ConjunctionFilter.h"
#include "DisjunctionFilter.h"
#include "Filter.h"

class Collection {
public:
    Collection() = default;
    //Collection(std::string *pString);

    void createContent( std::string& fileName);
    void createFilters();
    std::vector<VideoContent> extract(FilterType type);
    void print();

private:

    std::vector<VideoContent> content_;
    using FilterFunction = std::function<bool(VideoContent)>;
    std::map<FilterType, FilterFunction> filters_;


};

