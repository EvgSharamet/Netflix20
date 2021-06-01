#ifndef NETFLIX20_VIDEOCONTENT_H
#define NETFLIX20_VIDEOCONTENT_H
#include <iostream>
#include <optional>
#include "Characteristics.h"
#include <optional>



class VideoContent {
public:
    VideoContent(std::optional<std::string> name, std::optional<Genre> genre,std::optional<ContentType> type,
                 std::optional<int> publicationYear);
    VideoContent(std::optional<std::string> name, std::optional<Genre> genre,std::optional<ContentType> type,
                 std::optional<int> publicationYear,std::optional<int> finishYear);

    std::optional<Genre> getGenre() const;
    std::optional<int> getPublicationYear() const;
    std::optional<int> getFinishYear() const;
    std::optional<ContentType> getType() const;
    void print() const;

private:
    std::optional<std::string> name_ = std::nullopt;
    std::optional<Genre> genre_ = std::nullopt;
    std::optional<int> publicationYear_ = std::nullopt;
    std::optional<int> finishYear_ = std::nullopt ;
    std::optional<ContentType> type_ = std::nullopt;
};


#endif
