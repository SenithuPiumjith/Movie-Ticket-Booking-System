#include "pricing.h"

double calculateSeatPrice(SeatTier tier, int isStudent, int isSenior,
                          int seatsInTransaction)
{
    switch (tier)
    {
        case SEAT_STANDARD:
            return 1000.0;

        case SEAT_PREMIUM:
            return 1500.0;

        case SEAT_VIP:
            return 2000.0;

        default:
            return 1000.0;
    }
}
