#ifndef MOVIE_H
#define MOVIE_H

#include "config.h"
#include "seat.h"

/*
 * One showtime "owns" a full seat map and keeps running totals.
 * Everything about a showing (its seats, its revenue) lives here.
 */
typedef struct {
    char time[MAX_TIME_LEN];
    Seat seats[NUM_ROWS][SEATS_PER_ROW];
    int  ticketsSold;
    double totalRevenue;
} Showtime;

/* A movie "has" a fixed number of showtimes. */
typedef struct {
    char title[MAX_TITLE_LEN];
    Showtime showtimes[SHOWTIMES_PER_MOVIE];
} Movie;

void initMovies(Movie movies[NUM_MOVIES]);

#endif /* MOVIE_H */
