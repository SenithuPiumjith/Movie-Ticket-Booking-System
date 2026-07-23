#include "pricing.h"
#include "config.h"

double calculateSeatPrice(SeatTier tier, int isStudent, int isSenior,
                          int seatsInTransaction)
{
    double base = seatTierBasePrice(tier);

    if (isStudent)
    {
        base = base * (1.0 - STUDENT_DISCOUNT_PCT / 100.0);
    }
    else if (isSenior)
    {
        base = base * (1.0 - SENIOR_DISCOUNT_PCT / 100.0);
    }

    return base;
}
#include "pricing.h"
#include "config.h"

double calculateSeatPrice(SeatTier tier, int isStudent, int isSenior,
                          int seatsInTransaction)
{
    double base = seatTierBasePrice(tier);

    if (isStudent)
    {
        base = base * (1.0 - STUDENT_DISCOUNT_PCT / 100.0);
    }
    else if (isSenior)
    {
        base = base * (1.0 - SENIOR_DISCOUNT_PCT / 100.0);
    }

    return base;
}
