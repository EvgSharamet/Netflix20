#include "Filter.h"
#include "VideoContent.h"


void Filter::setGenre(Genre genre) {
    genre_ = genre;
}

void Filter::setPublicationYear(int publicationYear) {
    publicationYear_ = publicationYear;
}


void Filter::setContentType(ContentType type) {
    type_ = type;
}


bool Filter::operator()(const VideoContent& content){

    if(publicationYear_)
        return (publicationYear_ <= content.getPublicationYear()) ;
    if(genre_)
        return (genre_ == content.getGenre());
    if(type_)
        return (type_ == content.getType()) ;

    return false;
}

