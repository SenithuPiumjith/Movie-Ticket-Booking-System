#include <string.h>
#include "movie.h"

static void initShowtime(Showtime *show, const char *time) {
    strncpy(show->time, time, MAX_TIME_LEN - 1);
    show->time[MAX_TIME_LEN - 1] = '\0';
    show->ticketsSold  = 0;
    show->totalRevenue = 0.0;

    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < SEATS_PER_ROW; c++) {
            show->seats[r][c].isBooked = 0;
            show->seats[r][c].customerName[0] = '\0';
            show->seats[r][c].pricePaid = 0.0;
            show->seats[r][c].isStudent = 0;
            show->seats[r][c].isSenior  = 0;
        }
    }
}

static void initMovie(Movie *movie, const char *title,
                       const char *time1, const char *time2) {
    strncpy(movie->title, title, MAX_TITLE_LEN - 1);
    movie->title[MAX_TITLE_LEN - 1] = '\0';
    initShowtime(&movie->showtimes[0], time1);
    initShowtime(&movie->showtimes[1], time2);
}

/* Hardcoded data set: 3 movies, 2 showtimes each, as required. */
void initMovies(Movie movies[NUM_MOVIES]) {
    initMovie(&movies[0], "Ben 10 Alien Force",  "10:00 AM", "6:30 PM");
    initMovie(&movies[1], "Odyssy",  "1:00 PM",  "9:00 PM");
    initMovie(&movies[2], "Spider Man 4",   "11:30 AM", "4:15 PM");
}
