#ifndef NETFLIX20_DISJUNCTIONFILTER_H
#define NETFLIX20_DISJUNCTIONFILTER_H
#include <vector>
#include "VideoContent.h"


class DisjunctionFilter {
public:
    DisjunctionFilter(std::vector<std::function<bool(VideoContent)>> filtersCollection);
    bool operator()(const VideoContent &content);

private:
    std::vector<std::function<bool(VideoContent)>> filtersCollection_;
};

#endif
