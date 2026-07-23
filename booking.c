#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "pricing.h"

int bookSeat(Showtime *show, int row, int col, const char *name,
             int isStudent, int isSenior, int seatsInTransaction,
             double *priceOut) {
    if (!isValidSeatPosition(row, col)) {
        return -1;                               /* out of range */
    }

    Seat *seat = &show->seats[row][col];
    if (seat->isBooked) {
        return -2;                              /* already taken */
    }

    SeatTier tier  = seatTierForRow(row);
    double   price = calculateSeatPrice(tier, isStudent, isSenior,
                                         seatsInTransaction);

    seat->isBooked = 1;
    strncpy(seat->customerName, name, MAX_NAME_LEN - 1);
    seat->customerName[MAX_NAME_LEN - 1] = '\0';
    seat->pricePaid = price;
    seat->isStudent = isStudent;
    seat->isSenior  = isSenior;

    show->ticketsSold++;
    show->totalRevenue += price;

    if (priceOut) {
        *priceOut = price;
    }
    return 0;
}

int cancelSeat(Showtime *show, int row, int col) {
    if (!isValidSeatPosition(row, col)) {
        return -1;
    }

    Seat *seat = &show->seats[row][col];
    if (!seat->isBooked) {
        return -2;                                 /* nothing to cancel */
    }

    /* Refund: remove this seat's price from revenue before clearing it. */
    show->totalRevenue -= seat->pricePaid;
    show->ticketsSold--;

    seat->isBooked = 0;
    seat->customerName[0] = '\0';
    seat->pricePaid = 0.0;
    seat->isStudent = 0;
    seat->isSenior  = 0;

    return 0;
}

void searchByName(Movie movies[NUM_MOVIES], const char *name) {
    int found = 0;

    for (int m = 0; m < NUM_MOVIES; m++) {
        for (int s = 0; s < SHOWTIMES_PER_MOVIE; s++) {
            Showtime *show = &movies[m].showtimes[s];
            for (int r = 0; r < NUM_ROWS; r++) {
                for (int c = 0; c < SEATS_PER_ROW; c++) {
                    Seat *seat = &show->seats[r][c];
                    if (seat->isBooked && strstr(seat->customerName, name)) {
                        printf("  %-20s | %-16s | %-8s | Seat %c%-2d | Rs. %.2f\n",
                               seat->customerName, movies[m].title, show->time,
                               (char) ('A' + r), c + 1, seat->pricePaid);
                        found = 1;
                    }
                }
            }
        }
    }

    if (!found) {
        printf("No bookings found matching \"%s\".\n", name);
    }
}

void searchBySeat(Showtime *show, int row, int col) {
    if (!isValidSeatPosition(row, col)) {
        printf("Invalid seat position.\n");
        return;
    }

    Seat *seat  = &show->seats[row][col];
    char  rowCh = (char) ('A' + row);

    if (!seat->isBooked) {
        printf("Seat %c%d is not currently booked.\n", rowCh, col + 1);
        return;
    }

    printf("Seat %c%d | Customer: %s | Price paid: Rs. %.2f\n",
           rowCh, col + 1, seat->customerName, seat->pricePaid);
}
