#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include "VideoContent.h"
#include "notUseFilters.h"
#include "ConjunctionFilter.h"
#include "DisjunctionFilter.h"
#include "Filter.h"

class Collection {
public:
    Collection() = default;
    //Collection(std::string *pString);
    ~Collection();

    void createContent( std::string& fileName);
    std::vector<VideoContent> extract(FilterType type);
    void print();
private:
    void createFilters();
    std::vector<VideoContent> content_;
    using FilterFunction = std::function<bool(VideoContent)>;
    std::map<FilterType, FilterFunction> filters_;


};

