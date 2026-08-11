#ifndef BOOKING_SYSTEM_H
#define BOOKING_SYSTEM_H

#include <string>
#include <vector>
#include "Movie.h"
#include "Show.h"
#include "Booking.h"

class BookingSystem {
public:
    explicit BookingSystem(std::string dataFile);

    void seedCatalog();
    void loadBookings();
    void saveBookings() const;

    const std::vector<Movie>& getMovies() const;
    const std::vector<Show>& getShows() const;

    const Show* findShow(int showId) const;
    const Movie* findMovie(int movieId) const;

    bool bookTicket(int showId, int seatNumber, const std::string& customerName, int& bookingIdOut);
    bool cancelBooking(int bookingId);
    std::vector<Booking> bookingsForCustomer(const std::string& customerName) const;

private:
    std::string dataFile_;
    std::vector<Movie> movies_;
    std::vector<Show> shows_;
    std::vector<Booking> bookings_;
    int nextBookingId_;

    Show* findShowMutable(int showId);
};

#endif
