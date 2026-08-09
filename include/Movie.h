#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
public:
    Movie(int id, std::string title, std::string genre, int durationMinutes);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getGenre() const;
    int getDurationMinutes() const;

private:
    int id_;
    std::string title_;
    std::string genre_;
    int durationMinutes_;
};

#endif
