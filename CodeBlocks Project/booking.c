#include <stdio.h>
#include <string.h>
#include "booking.h"

int bookSeat(Showtime *show, int row, int col, const char *name,
             int isStudent, int isSenior, int seatsInTransaction,
             double *priceOut)
{
    if (!isValidSeatPosition(row, col))
        return -1;

    Seat *seat = &show->seats[row][col];

    if (seat->isBooked)
        return -2;

    seat->isBooked = 1;

    strncpy(seat->customerName, name, MAX_NAME_LEN - 1);
    seat->customerName[MAX_NAME_LEN - 1] = '\0';

    if (priceOut)
        *priceOut = 0;

    return 0;
}
