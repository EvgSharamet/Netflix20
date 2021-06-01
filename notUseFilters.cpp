#include "notUseFilters.h"
#include <utility>
#include "VideoContent.h"



GenreFilter::GenreFilter(Genre genre) {
    genre_ = genre;
}

bool GenreFilter::checkContent(const VideoContent &content) {
    if(content.getGenre() == genre_)
        return true;
    return false;
}



ContentTypeFilter::ContentTypeFilter(ContentType type) {
    type_=type;
}

bool ContentTypeFilter::checkContent(const VideoContent &content) {
    if(content.getType() == type_)
        return true;
    return false;
}


ConjunctionFilter::ConjunctionFilter(std::vector<notUseFilters *> filtersCollection) {
    filtersCollection_ = std::move(filtersCollection);
}

bool ConjunctionFilter::checkContent(const VideoContent &content) {
    for(auto& filter : filtersCollection_)
        if(!filter->checkContent(content))
            return false;
    return true;
}
/*
RatingFilter::RatingFilter(int rating) {
    rating_ = rating;

}*/

/*
bool RatingFilter::check_content(const VideoContent &content) {
    if(content.get_rating()>=rating_)
        return true;
    return false;
}*/
