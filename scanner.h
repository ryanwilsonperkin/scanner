#ifndef SCANNER_SCANNER_H
#define SCANNER_SCANNER_H

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

void emit_token(enum Token tok);
int is_whitespace(char c);
enum Token recognize_token(char *str);

#endif  // SCANNER_SCANNER_H
