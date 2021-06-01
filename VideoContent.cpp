#include "VideoContent.h"
#include <utility>

VideoContent::VideoContent(std::optional<std::string> name, std::optional<Genre> genre,
                           std::optional<ContentType> type,std::optional<int> publicationYear)
                           : name_(std::move(name)),genre_(genre),type_(type),
                           publicationYear_(publicationYear){
}
VideoContent::VideoContent(std::optional<std::string> name, std::optional<Genre> genre,
                           std::optional<ContentType> type, std::optional<int> publicationYear,
                           std::optional<int> finishYear) :
name_(std::move(name)),genre_(genre),type_(type), publicationYear_(publicationYear),finishYear_(finishYear){

}


std::optional<Genre> VideoContent::getGenre() const{
    return genre_;
}
std::optional<int> VideoContent::getPublicationYear() const{
    return publicationYear_;
}

std::optional<int> VideoContent::getFinishYear() const {
    return finishYear_;
}

std::optional<ContentType> VideoContent::getType() const {
    return type_;
}


void VideoContent::print() const {
    if(name_)
        std::cout<<"Name = "<< *name_<<std::endl;

    switch (*type_) {
        case ContentType::movies:
            std::cout << "type = movies" << std::endl;
        case ContentType::series:
            std::cout << "type = series" << std::endl;
        case ContentType::missing:
            std::cout << "type = missing" << std::endl;

        }
    if(genre_)
        switch (*genre_) {
            case Genre::horror:
                std::cout << "Genre = horror" << std::endl;
                break;
            case Genre::comedy:
                std::cout << "Genre = comedy" << std::endl;
                break;
            case Genre::action:
                std::cout << "Genre = action" << std::endl;
                break;
            case Genre::drama:
                std::cout << "Genre = drama" << std::endl;
                break;
            case Genre::thriller:
                std::cout << "Genre = thriller" << std::endl;
                break;
            case Genre::western:
                std::cout << "Genre = western" << std::endl;
                break;
            case Genre::historical:
                std::cout << "Genre = historical" << std::endl;
                break;
            case Genre::adventure:
                std::cout << "Genre = adventure" << std::endl;
                break;
            case Genre::fantasy:
                std::cout << "Genre = fantasy" << std::endl;
                break;
            case Genre::speculative:
                std::cout << "Genre = speculative" << std::endl;
                break;
            case Genre::science_fiction:
                std::cout << "Genre = science_fiction" << std::endl;
                break;
            case Genre::adventure_fiction:
                std::cout << "Genre = adventure_fiction" << std::endl;
                break;
            case Genre::animation:
                std::cout << "Genre = animation" << std::endl;
                break;
            case Genre::missing:
                std::cout << "Genre = missing" << std::endl;
                break;
        }

    if(publicationYear_)
        std::cout<<"Publication year = "<<*publicationYear_<<std::endl;
    if(finishYear_)
        std::cout<<"Finish year= " << *finishYear_ << std::endl;
    std::cout<<""<<std::endl;
}


