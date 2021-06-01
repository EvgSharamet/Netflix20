#pragma once

#include <vector>
#include "VideoContent.h"

class ConjunctionFilter{
public:
    explicit ConjunctionFilter(std::vector<std::function<bool(VideoContent)>> filtersCollection);
    bool operator()(const VideoContent &content);

private:
    std::vector<std::function<bool(VideoContent)>> filtersCollection_;

};