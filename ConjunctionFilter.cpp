#include "ConjunctionFilter.h"
#include <utility>

ConjunctionFilter::ConjunctionFilter( std::vector<std::function<bool(VideoContent)>> filters_collection) {
    filtersCollection_ =  std::move(filters_collection);
}


bool ConjunctionFilter::operator()(const VideoContent &content) {
    for(const auto& filter: filtersCollection_)
        if(!filter(content))
            return false;

    return true;
}