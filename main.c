#include <stdio.h>
#include <ctype.h>
#include "config.h"
#include "movie.h"
#include "seat.h"
#include "booking.h"
#include "display.h"
#include "input.h"
#include "auth.h"

/* Lets the user pick a movie, then one of its showtimes. */
static Showtime *selectShowtime(Movie movies[NUM_MOVIES]) {
    printShowtimesList(movies);
    int m = readInt("Select movie number: ", 1, NUM_MOVIES) - 1;
    int s = readInt("Select showtime number: ", 1, SHOWTIMES_PER_MOVIE) - 1;
    return &movies[m].showtimes[s];
}

/* Reads a row letter (A..E) and re-prompts on anything invalid. */
static int readValidRow(const char *prompt) {
    while (1) {
        char rowCh = (char) toupper((unsigned char) readChar(prompt));
        int  row   = rowCh - 'A';
        if (row >= 0 && row < NUM_ROWS) {
            return row;
        }
        printf("Invalid row. Please enter a letter between A and %c.\n",
               (char) ('A' + NUM_ROWS - 1));
    }
}

static void handleViewShowtimes(Movie movies[NUM_MOVIES]) {
    printShowtimesList(movies);
}

static void handleViewSeatMap(Movie movies[NUM_MOVIES]) {
    Showtime *show = selectShowtime(movies);
    printSeatMap(show);
}

static void handleBookSeat(Movie movies[NUM_MOVIES]) {
    Showtime *show = selectShowtime(movies);
    printSeatMap(show);

    int numSeats = readInt("How many seats to book in this transaction? ",
                            1, NUM_ROWS * SEATS_PER_ROW);

    char name[MAX_NAME_LEN];
    readLine("Customer name: ", name, sizeof(name));

    printf("Discount category:\n");
    printf("  0. None\n");
    printf("  1. Student (10%% off)\n");
    printf("  2. Senior Citizen (20%% off)\n");
    int category  = readInt("Choose category: ", 0, 2);
    int isStudent = (category == 1);
    int isSenior  = (category == 2);

    if (numSeats >= GROUP_MIN_SEATS) {
        printf("Group discount (10%% off) applies to this booking.\n");
    }

    int booked = 0;
    for (int i = 0; i < numSeats; i++) {
        printf("\nSeat %d of %d:\n", i + 1, numSeats);
        int row = readValidRow("  Row letter (A-E): ");
        int col = readInt("  Seat number (1-10): ", 1, SEATS_PER_ROW) - 1;

        double price;
        int status = bookSeat(show, row, col, name, isStudent, isSenior,
                               numSeats, &price);
        char rowCh = (char) ('A' + row);

        if (status == 0) {
            printf("  Booked seat %c%d for Rs. %.2f\n", rowCh, col + 1, price);
            booked++;
        } else if (status == -1) {
            printf("  Error: seat position out of range.\n");
        } else if (status == -2) {
            printf("  Error: seat %c%d is already booked.\n", rowCh, col + 1);
        }
    }

    printf("\n%d of %d requested seat(s) booked successfully.\n", booked, numSeats);
}

static void handleCancelBooking(Movie movies[NUM_MOVIES]) {
    Showtime *show = selectShowtime(movies);
    printSeatMap(show);

    int  row   = readValidRow("Row letter (A-E): ");
    int  col   = readInt("Seat number (1-10): ", 1, SEATS_PER_ROW) - 1;
    char rowCh = (char) ('A' + row);

    int status = cancelSeat(show, row, col);
    if (status == 0) {
        printf("Seat %c%d has been freed and removed from revenue.\n", rowCh, col + 1);
    } else if (status == -1) {
        printf("Error: seat position out of range.\n");
    } else if (status == -2) {
        printf("Error: seat %c%d is not currently booked.\n", rowCh, col + 1);
    }
}

static void handleSearchBooking(Movie movies[NUM_MOVIES]) {
    printf("Search by:\n  1. Customer name\n  2. Seat number\n");
    int mode = readInt("Choose option: ", 1, 2);

    if (mode == 1) {
        char name[MAX_NAME_LEN];
        readLine("Enter customer name to search: ", name, sizeof(name));
        searchByName(movies, name);
    } else {
        Showtime *show = selectShowtime(movies);
        int row = readValidRow("Row letter (A-E): ");
        int col = readInt("Seat number (1-10): ", 1, SEATS_PER_ROW) - 1;
        searchBySeat(show, row, col);
    }
}

static void handleRevenueReport(Movie movies[NUM_MOVIES]) {
    printRevenueReport(movies);
}

/* Customer session: booking-related operations only, no back-office access. */
static void runCustomerMenu(Movie movies[NUM_MOVIES]) {
    int choice;
    do {
        printCustomerMenu();
        choice = readInt("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1: handleViewShowtimes(movies); break;
            case 2: handleViewSeatMap(movies);   break;
            case 3: handleBookSeat(movies);      break;
            case 4: handleCancelBooking(movies); break;
            case 5: printf("Returning to main menu...\n"); break;
        }
    } while (choice != 5);
}

/* Admin session: full access, including search and revenue reporting. */
static void runAdminMenu(Movie movies[NUM_MOVIES]) {
    int choice;
    do {
        printAdminMenu();
        choice = readInt("Enter your choice: ", 1, 7);

        switch (choice) {
            case 1: handleViewShowtimes(movies);  break;
            case 2: handleViewSeatMap(movies);    break;
            case 3: handleBookSeat(movies);       break;
            case 4: handleCancelBooking(movies);  break;
            case 5: handleSearchBooking(movies);  break;
            case 6: handleRevenueReport(movies);  break;
            case 7: printf("Returning to main menu...\n"); break;
        }
    } while (choice != 7);
}

int main(void) {
    Movie movies[NUM_MOVIES];
    initMovies(movies);

    int role;
    do {
        printRoleMenu();
        role = readInt("Enter your choice: ", 1, 3);

        if (role == 1) {
            runCustomerMenu(movies);
        } else if (role == 2) {
            if (authenticateAdmin()) {
                runAdminMenu(movies);
            } else {
                printf("Returning to main menu...\n");
            }
        } else {
            printf("Goodbye!\n");
        }
    } while (role != 3);

    return 0;
}
