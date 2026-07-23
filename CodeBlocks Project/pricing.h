#ifndef PRICING_H
#define PRICING_H

#include "seat.h"

double calculateSeatPrice(SeatTier tier,
                          int isStudent,
                          int isSenior,
                          int seatsInTransaction);

#endif
