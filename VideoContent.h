#pragma once

#include <iostream>
#include <optional>
#include "Characteristics.h"

class VideoContent {
public:
    VideoContent(std::optional<std::string> name, std::optional<Genre> genre,std::optional<ContentType> type,
                 std::optional<int> publicationYear,std::optional<int> finishYear = std::nullopt);

    [[nodiscard]] std::optional<Genre> getGenre() const;
    [[nodiscard]] std::optional<int> getPublicationYear() const;
    [[nodiscard]] std::optional<int> getFinishYear() const;
    [[nodiscard]] std::optional<ContentType> getType() const;
    void print() const;

private:
    std::optional<std::string> name_ = std::nullopt;
    std::optional<Genre> genre_ = std::nullopt;
    std::optional<int> publicationYear_ = std::nullopt;
    std::optional<int> finishYear_ = std::nullopt ;
    std::optional<ContentType> type_ = std::nullopt;
};