#ifndef DISPLAY_H
#define DISPLAY_H

#include "movie.h"

void printRoleMenu(void);
void printCustomerMenu(void);
void printAdminMenu(void);
void printShowtimesList(Movie movies[NUM_MOVIES]);
void printSeatMap(Showtime *show);
void printRevenueReport(Movie movies[NUM_MOVIES]);

#endif /* DISPLAY_H */
