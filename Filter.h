#ifndef NETFLIX20_FILTER_H
#define NETFLIX20_FILTER_H

#include <iostream>
#include <optional>
#include "Characteristics.h"
#include "VideoContent.h"

class Filter {
public:
    Filter() = default;
    void setGenre(Genre genre);
    void setPublicationYear(int publicationYear);
    void setRating(int rating);
    void setContentType(ContentType contentType);

    virtual bool operator()(const VideoContent &content);

private:
    std::optional<std::string> name_ = std::nullopt;
    std::optional<Genre> genre_ = std::nullopt;
    std::optional<int> publicationYear_ = std::nullopt;
    std::optional<ContentType> type_ = std::nullopt;
};


#endif
