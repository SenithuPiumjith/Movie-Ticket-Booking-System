# Movie-Ticket-Booking-System

A command-line movie ticket booking system written in C for CSC 1031. Theater
staff and customers can view showtimes, book and cancel seats, search
bookings, and check revenue - all managed in memory during the program's run.

## How to Compile

From inside the project folder, with all `.c`/`.h` files present:

```
gcc *.c -o booking
```

This compiles every source file (`main.c`, `movie.c`, `seat.c`, `pricing.c`,
`booking.c`, `display.c`, `input.c`, `auth.c`) into a single executable named
`booking` (or `booking.exe` on Windows).

If you want compiler warnings enabled (recommended while developing):

```
gcc -Wall -Wextra -std=c99 *.c -o booking
```

## How to Run

**Linux / macOS:**
```
./booking
```

**Windows (Command Prompt or PowerShell):**
```
booking.exe
```

You'll be dropped into the main menu, where you choose between the Customer
Menu and the Admin Menu.

### Admin login

Selecting the Admin Menu prompts for a username and password. Use:

```
Username: admin1
Password: 1234
```

You get 3 attempts before being sent back to the main menu.

## Feature List

### Main Menu
- **Customer Menu** - booking-related operations, open to anyone
- **Admin Menu** - full access, requires login
- **Exit** - closes the program

### Customer Menu
1. **View Showtimes** - lists all 3 movies and their 2 showtimes each
2. **View Seat Map** - shows a chosen showtime's 5*10 seat grid (`.` = free,
   `X` = booked), with each row labeled by pricing tier (Regular / Premium /
   VIP)
3. **Book a Seat** - books one or more seats in a single transaction for a
   named customer, applying the correct discount automatically
4. **Cancel a Booking** - frees a booked seat and removes it from revenue
5. **Back to Main Menu**

### Admin Menu
Everything in the Customer Menu, plus:
- **Search Booking** - find a booking by customer name (across all movies and
  showtimes) or by a specific seat
- **View Revenue Report** - tickets sold and revenue per showtime, plus grand
  totals across all movies

### Pricing & Discounts
| Seat Tier | Rows | Base Price |
|---|---|---|
| Regular | A-B | Rs. 500 |
| Premium | C-D | Rs. 750 |
| VIP     | E   | Rs. 1000 |

- **Student discount:** 10% off
- **Senior citizen discount:** 20% off
- **Group discount:** additional 10% off when booking 4 or more seats in one
  transaction - combines with the student/senior discount
- A booking can only be flagged as *one* of Student or Senior (not both)

### Validations
- Can't book a seat that's already taken
- Can't book or cancel a seat number that's out of range
- Can't cancel a seat that isn't booked
- Handles non-numeric or otherwise invalid input without crashing (re-prompts
  instead)

## Project Structure

| File | Responsibility |
|---|---|
| `config.h` | Shared constants (grid size, prices, discount rates, admin credentials) |
| `seat.h` / `seat.c` | Seat struct, pricing tier lookup |
| `movie.h` / `movie.c` | Movie & Showtime structs, hardcoded data setup |
| `pricing.h` / `pricing.c` | Discount/price calculation |
| `booking.h` / `booking.c` | Book, cancel, and search operations |
| `display.h` / `display.c` | All screen output: menus, seat map, revenue report |
| `auth.h` / `auth.c` | Admin login |
| `input.h` / `input.c` | Crash-proof input reading |
| `main.c` | Menu loop tying everything together |
