# Movie Ticket Booking System

A console-based movie ticket booking application written in C++ -- browse now-showing
movies, pick a showtime, reserve a seat, and manage bookings, all backed by simple file
persistence (no database required). Originally built as a C++ coursework project during
my bachelor's degree.

## Features

- Browse a small catalog of movies and showtimes
- Book a specific seat number for a show
- Cancel an existing booking by confirmation number
- Look up all bookings under a customer's name
- Bookings persist to `data/bookings.txt` between runs

## Building and running

Requires a C++17 compiler (g++ or clang++) and `make`.

```bash
make run
```

This builds the project into `bin/booking_system` and starts the interactive menu.

## Project structure

```
include/           # Class headers (Movie, Show, Booking, BookingSystem)
src/                # Implementation files + main.cpp entry point
data/               # Runtime booking storage (created on first run, gitignored)
Makefile
```

## Design notes

- `BookingSystem` owns the in-memory catalog and booking list, and is the only class
  that touches the data file -- callers never read/write `data/bookings.txt` directly.
- Seat availability is tracked per-`Show` as a `vector<bool>`, so double-booking a seat
  is rejected at the `Show::bookSeat` level rather than higher up.
- No external dependencies -- pure C++ standard library.
