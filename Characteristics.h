#pragma once

enum class Genre {
    horror, comedy, action, drama, thriller, western, historical, adventure, fantasy,
    speculative, science_fiction, adventure_fiction,animation, missing
};

enum class ContentType{
    movies, series, missing
};

enum class FilterType{
    genre_comedy, content_type_movies, publication_year,  disjunction, conjunction
};