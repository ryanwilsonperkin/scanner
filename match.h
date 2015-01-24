#ifndef MATCH_SCANNER_H
#define MATCH_SCANNER_H

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

enum Token recognize_token(char *str);

#endif  /* MATCH_SCANNER_H */
