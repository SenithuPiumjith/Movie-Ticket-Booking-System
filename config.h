#ifndef CONFIG_H
#define CONFIG_H

/* ---- Layout ---- */
#define NUM_MOVIES            3
#define SHOWTIMES_PER_MOVIE   2
#define NUM_ROWS              5   /* rows A..E */
#define SEATS_PER_ROW         10
#define MAX_NAME_LEN          50
#define MAX_TITLE_LEN         50
#define MAX_TIME_LEN          20

/* ---- Base ticket prices (Rs.) ---- */
#define PRICE_REGULAR  500.0   /* rows A-B */
#define PRICE_PREMIUM  750.0   /* rows C-D */
#define PRICE_VIP     1000.0   /* row  E   */

/* ---- Discounts ---- */
#define STUDENT_DISCOUNT_PCT 10.0
#define SENIOR_DISCOUNT_PCT  20.0
#define GROUP_DISCOUNT_PCT   10.0
#define GROUP_MIN_SEATS      4

/* ---- Admin login (hardcoded for this assignment) ---- */
#define ADMIN_USERNAME     "admin1"
#define ADMIN_PASSWORD     "1234"
#define MAX_LOGIN_ATTEMPTS 3

#endif /* CONFIG_H */
