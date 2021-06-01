#pragma once
#include <vector>
#include "VideoContent.h"


class DisjunctionFilter {
public:
    explicit DisjunctionFilter(std::vector<std::function<bool(VideoContent)>> filtersCollection);
    bool operator()(const VideoContent &content);

private:
    std::vector<std::function<bool(VideoContent)>> filtersCollection_;
};
