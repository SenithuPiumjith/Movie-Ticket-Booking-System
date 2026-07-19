#ifndef BOOKING_H
#define BOOKING_H

#include "movie.h"

/*
  Books one seat.
  Returns  0 on success (priceOut is set to the price charged)
          -1 if (row, col) is out of range
          -2 if the seat is already booked
 */

int bookSeat(Showtime *show, int row, int col, const char *name,
             int isStudent, int isSenior, int seatsInTransaction,
             double *priceOut);

/*
  Cancels a booking, frees the seat, and removes it from revenue.
  Returns  0 on success
          -1 if (row, col) is out of range
          -2 if the seat was not booked
 */

int cancelSeat(Showtime *show, int row, int col);

// Prints every booking across all movies/showtimes matching `name`.
void searchByName(Movie movies[NUM_MOVIES], const char *name);

// Prints the booking (if any) for one specific seat.
void searchBySeat(Showtime *show, int row, int col);

#endif /* BOOKING_H */
