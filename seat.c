#include "seat.h"

SeatTier seatTierForRow(int row) {
    if (row == 0 || row == 1) return TIER_REGULAR;   /* A, B */
    if (row == 2 || row == 3) return TIER_PREMIUM;   /* C, D */
    return TIER_VIP;                                  /* E     */
}

const char *seatTierName(SeatTier tier) {
    switch (tier) {
        case TIER_REGULAR: return "Regular";
        case TIER_PREMIUM: return "Premium";
        case TIER_VIP:     return "VIP";
        default:            return "Unknown";
    }
}

double seatTierBasePrice(SeatTier tier) {
    switch (tier) {
        case TIER_REGULAR: return PRICE_REGULAR;
        case TIER_PREMIUM: return PRICE_PREMIUM;
        case TIER_VIP:     return PRICE_VIP;
        default:            return 0.0;
    }
}

char seatTierSymbol(SeatTier tier) {
    switch (tier) {
        case TIER_REGULAR: return 'R';
        case TIER_PREMIUM: return 'P';
        case TIER_VIP:     return 'V';
        default:            return '?';
    }
}

int isValidSeatPosition(int row, int col) {
    return (row >= 0 && row < NUM_ROWS && col >= 0 && col < SEATS_PER_ROW);
}
