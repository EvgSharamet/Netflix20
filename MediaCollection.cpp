#include "MediaCollection.h"
#include <vector>
#include <fstream>
#include <string>
#include <optional>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

template<typename T>
std::optional<T> extractFromJson(const json& j, const std::string& key) {
    if (j.contains(key))
        return j[key];
    return std::nullopt;
}

Genre StringToGenre(std::optional<std::string> stringWithGenre) {
    if (!stringWithGenre)
        return Genre::missing;

    if (*stringWithGenre == "horror")
        return Genre::horror;

    if (*stringWithGenre == "comedy")
        return Genre::comedy;

    if (*stringWithGenre == "action")
        return Genre::action;

    if (*stringWithGenre == "drama")
        return Genre::drama;

    if (*stringWithGenre == "thriller")
        return Genre::thriller;

    if (*stringWithGenre == "western")
        return Genre::western;

    if (*stringWithGenre == "historical")
        return Genre::historical;

    if (*stringWithGenre == "adventure")
        return  Genre::adventure;

    if (*stringWithGenre == "fantasy")
        return Genre::fantasy;

    if (*stringWithGenre == "speculative")
        return Genre::speculative;

    if (*stringWithGenre == "science_fiction")
        return Genre::science_fiction;

    if (*stringWithGenre == "adventure_fiction")
        return Genre::adventure_fiction;

    if (*stringWithGenre == "animation")
        return Genre::animation;

    return Genre::missing;
}

ContentType StringToContentType(std::optional<std::string> stringWithContentType) {
    if (!stringWithContentType)
        return ContentType::missing;

    if (*stringWithContentType == "movies")
        return ContentType::movies;

    if (*stringWithContentType == "series")
        return ContentType::series;

    return ContentType::missing;
}

void MediaCollection::createContent(std::string& fileName) {
    std::ifstream in{fileName};
    json data;
    in >> data; //TODO add try catch
    for(auto& element : data) {
        auto name = extractFromJson<std::string>(element , "name");
        Genre genre = StringToGenre(extractFromJson<std::string>(element, "genre"));
        auto type = StringToContentType(extractFromJson<std::string>(element, "type"));
        auto publicationYear = extractFromJson<int>(element, "year");
        auto finishYear = extractFromJson<int>(element, "finishYear");

        content_.emplace_back(name, genre, type, publicationYear, finishYear);
    }
}

void MediaCollection::createFilters() {
    auto genreComedy =  [](const VideoContent& content){
        return (content.getGenre() == Genre::comedy);
    };
    filters_.insert({FilterType::genre_comedy, genreComedy});

    auto contentMovies = [](const VideoContent& content){
        return bool (content.getType() == ContentType::movies);
    };
    filters_.insert({ FilterType::content_type_movies, contentMovies });

    auto  publicationYearMore2005 = [](const VideoContent& content){
        return content.getPublicationYear()>=2005;
    };
    filters_.insert({FilterType::publication_year, publicationYearMore2005});

    ConjunctionFilter conjunction{{ contentMovies, publicationYearMore2005}};
    filters_.insert({FilterType::conjunction,conjunction});

    DisjunctionFilter disjunction{{ genreComedy, publicationYearMore2005}};
    filters_.insert({FilterType::disjunction, disjunction});
}

std::vector<VideoContent> MediaCollection::extract(FilterType type) {
    std::vector<VideoContent> result;
    for(const auto& item : content_)
        if (filters_[type](item))
            result.push_back(item);
    return result;
}

void MediaCollection::print() {
    for( const auto& item: content_)
        item.print();
}

