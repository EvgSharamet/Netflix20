#ifndef NETFLIX20_FILTER_H
#define NETFLIX20_FILTER_H
#include <iostream>
#include <optional>
#include <vector>
#include "Characteristics.h"
#include "VideoContent.h"



class notUseFilters {
public:
    virtual ~notUseFilters() = default;
    virtual bool checkContent(const VideoContent &content) = 0;
};

class GenreFilter: public notUseFilters{
public:
    GenreFilter(Genre genre);
    ~GenreFilter() override = default;
    bool checkContent(const VideoContent &content) override;

private:
    Genre genre_;
};


class ContentTypeFilter: public notUseFilters{
public:
    ContentTypeFilter(ContentType type);
    ~ContentTypeFilter() override = default;
    bool checkContent(const VideoContent &content) override ;

private:
    ContentType type_;
};


class ConjunctionFilter: public notUseFilters{
public:
    ConjunctionFilter(std::vector<notUseFilters*> filtersCollection);
    ~ConjunctionFilter() override = default;
    bool checkContent(const VideoContent &content) override;

private:
    std::vector<notUseFilters*> filtersCollection_;
};

/*
class RatingFilter: public notUseFilters{
public:
    RatingFilter(int rating);
    ~RatingFilter() override = default;
    bool check_content(const VideoContent &content) override ;

private:
    int rating_;
};*/

#endif