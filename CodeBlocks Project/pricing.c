#include "pricing.h"
#include "config.h"

double calculateSeatPrice(SeatTier tier, int isStudent, int isSenior,
                           int seatsInTransaction) {
    double base = seatTierBasePrice(tier);
    double discountPct = 0.0;

    /* A booking can only be flagged as ONE category. */
    if (isStudent) {
        discountPct += STUDENT_DISCOUNT_PCT;
    } else if (isSenior) {
        discountPct += SENIOR_DISCOUNT_PCT;
    }

    /* Group discount stacks on top of the category discount. */
    if (seatsInTransaction >= GROUP_MIN_SEATS) {
        discountPct += GROUP_DISCOUNT_PCT;
    }

    if (discountPct > 100.0) {
        discountPct = 100.0; /* safety net, should never trigger */
    }

    return base * (1.0 - discountPct / 100.0);
}
