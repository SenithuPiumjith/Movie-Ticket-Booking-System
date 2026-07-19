#ifndef BOOKING_H
#define BOOKING_H

#include "movie.h"

int bookSeat(Showtime *show,
             int row,
             int col,
             const char *name,
             int isStudent,
             int isSenior,
             int seatsInTransaction,
             double *priceOut);

int cancelSeat(Showtime *show,
               int row,
               int col);

#endif
