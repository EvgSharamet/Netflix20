#ifndef NETFLIX20_CONJUNCTIONFILTER_H
#define NETFLIX20_CONJUNCTIONFILTER_H

#include <vector>
#include "VideoContent.h"

class ConjunctionFilter{
public:
    ConjunctionFilter(std::vector<std::function<bool(VideoContent)>> filtersCollection);
    bool operator()(const VideoContent &content);

private:
    std::vector<std::function<bool(VideoContent)>> filtersCollection_;

};


#endif
