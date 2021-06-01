#include "DisjunctionFilter.h"
#include <utility>

DisjunctionFilter::DisjunctionFilter(std::vector<std::function<bool(VideoContent)>> filters_collection){
    filtersCollection_ = std::move(filters_collection);
}

bool DisjunctionFilter::operator()(const VideoContent &content) {
    for( const auto& filter: filtersCollection_)
        if(filter(content))
            return true;
    return false;
}
