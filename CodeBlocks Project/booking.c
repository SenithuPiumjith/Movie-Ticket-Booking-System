#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "pricing.h"

int bookSeat(Showtime *show, int row, int col, const char *name,
             int isStudent, int isSenior,
             int seatsInTransaction,
             double *priceOut)
{
    if(!isValidSeatPosition(row,col))
        return -1;

    Seat *seat=&show->seats[row][col];

    if(seat->isBooked)
        return -2;

    SeatTier tier = seatTierForRow(row);

    double price =
        calculateSeatPrice(
            tier,
            isStudent,
            isSenior,
            seatsInTransaction);

    seat->isBooked=1;

    strncpy(seat->customerName,name,MAX_NAME_LEN-1);
    seat->customerName[MAX_NAME_LEN-1]='\0';

    seat->pricePaid=price;
    seat->isStudent=isStudent;
    seat->isSenior=isSenior;

    show->ticketsSold++;
    show->totalRevenue+=price;

    if(priceOut)
        *priceOut=price;

    return 0;
}

int cancelSeat(Showtime *show,int row,int col)
{
    if(!isValidSeatPosition(row,col))
        return -1;

    Seat *seat=&show->seats[row][col];

    if(!seat->isBooked)
        return -2;

    show->ticketsSold--;
    show->totalRevenue-=seat->pricePaid;

    seat->isBooked=0;
    seat->customerName[0]='\0';
    seat->pricePaid=0;

    return 0;
}
