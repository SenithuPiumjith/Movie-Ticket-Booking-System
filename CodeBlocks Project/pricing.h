#ifndef PRICING_H
#define PRICING_H

#include "seat.h"

/*
 * Computes the final price for one seat of the given tier.
 *
 * Rules:
 *   - isStudent  -> 10% off   \
 *   - isSenior   -> 20% off    > only ONE of these two can apply
 *   - neither    -> 0% off    /
 *   - seatsInTransaction >= GROUP_MIN_SEATS -> additional 10% off,
 *     and this DOES combine with student/senior.
 */
double calculateSeatPrice(SeatTier tier, int isStudent, int isSenior,
                           int seatsInTransaction);

#endif /* PRICING_H */
