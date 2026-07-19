#ifndef SEAT_H
#define SEAT_H

#include "config.h"

/* Pricing tier a seat belongs to, based on its row. */
typedef enum {
    TIER_REGULAR,   /* rows A-B */
    TIER_PREMIUM,   /* rows C-D */
    TIER_VIP        /* row  E   */
} SeatTier;

/*
 * A single seat. Acts like the smallest "object" in the system:
 * its own state (booked/free, who booked it, what they paid).
 */
typedef struct {
    int  isBooked;                    /* 0 = free, 1 = booked */
    char customerName[MAX_NAME_LEN];
    double pricePaid;
    int  isStudent;
    int  isSenior;
} Seat;

SeatTier    seatTierForRow(int row);
const char *seatTierName(SeatTier tier);
double      seatTierBasePrice(SeatTier tier);
char        seatTierSymbol(SeatTier tier);
int         isValidSeatPosition(int row, int col);

#endif /* SEAT_H */
