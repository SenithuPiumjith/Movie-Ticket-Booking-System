#include <stdio.h>
#include "display.h"
#include "seat.h"

void printMainMenu(void) {
    printf("\n===== Movie Ticket Booking System =====\n");
    printf("1. View Showtimes\n");
    printf("2. View Seat Map\n");
    printf("3. Book a Seat\n");
    printf("4. Cancel a Booking\n");
    printf("5. Search Booking\n");
    printf("6. View Revenue Report\n");
    printf("7. Exit\n");
}

void printShowtimesList(Movie movies[NUM_MOVIES]) {
    printf("\n--- Movies & Showtimes ---\n");
    for (int m = 0; m < NUM_MOVIES; m++) {
        printf("%d. %s\n", m + 1, movies[m].title);
        for (int s = 0; s < SHOWTIMES_PER_MOVIE; s++) {
            printf("     %d) %s\n", s + 1, movies[m].showtimes[s].time);
        }
    }
}

void printSeatMap(Showtime *show) {
    printf("\nSeat map for %s   (. = free, X = booked)\n", show->time);

    printf("      ");
    for (int c = 0; c < SEATS_PER_ROW; c++) {
        printf("%2d ", c + 1);
    }
    printf("\n");

    for (int r = 0; r < NUM_ROWS; r++) {
        SeatTier tier = seatTierForRow(r);
        printf(" %c [%c] ", 'A' + r, seatTierSymbol(tier));
        for (int c = 0; c < SEATS_PER_ROW; c++) {
            char symbol = show->seats[r][c].isBooked ? 'X' : '.';
            printf(" %c ", symbol);
        }
        printf("\n");
    }
    printf("Legend: [R]=Regular Rs.500  [P]=Premium Rs.750  [V]=VIP Rs.1000\n");
}

void printRevenueReport(Movie movies[NUM_MOVIES]) {
    double grandTotal   = 0.0;
    int    grandTickets = 0;

    printf("\n===== Revenue Report =====\n");
    for (int m = 0; m < NUM_MOVIES; m++) {
        printf("%s\n", movies[m].title);
        for (int s = 0; s < SHOWTIMES_PER_MOVIE; s++) {
            Showtime *show = &movies[m].showtimes[s];
            printf("   %-10s | Tickets sold: %2d | Revenue: Rs. %.2f\n",
                   show->time, show->ticketsSold, show->totalRevenue);
            grandTotal   += show->totalRevenue;
            grandTickets += show->ticketsSold;
        }
    }
    printf("-----------------------------------------\n");
    printf("Total tickets sold: %d\n", grandTickets);
    printf("Total revenue:      Rs. %.2f\n", grandTotal);
}
