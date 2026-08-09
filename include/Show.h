#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <vector>

class Show {
public:
    Show(int id, int movieId, std::string showTime, int totalSeats);

    int getId() const;
    int getMovieId() const;
    const std::string& getShowTime() const;
    int getTotalSeats() const;

    bool isSeatBooked(int seatNumber) const;
    bool bookSeat(int seatNumber);
    bool cancelSeat(int seatNumber);
    int countAvailableSeats() const;

private:
    int id_;
    int movieId_;
    std::string showTime_;
    int totalSeats_;
    std::vector<bool> seatBooked_;
};

#endif
