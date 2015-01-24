/*
 * match.h
 * A simple state based token matcher
 */
#ifndef MATCH_SCANNER_H
#define MATCH_SCANNER_H

/* List of all possible token types */
enum Token {
        INT,
        HEX,
        OCT,
        REAL,
        LPAREN,
        RPAREN,
        CAR,
        CDR,
        CHAR,
        STR
};

/*
 * recognize_token
 * Matches string to associated token type
 */
enum Token recognize_token(char *str);

#endif  /* MATCH_SCANNER_H */
