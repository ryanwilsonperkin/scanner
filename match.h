#ifndef MATCH_SCANNER_H
#define MATCH_SCANNER_H

char match_int(char *str);
char match_hex(char *str);
char match_oct(char *str);
char match_real(char *str);
char match_lparen(char *str);
char match_rparen(char *str);
char match_car(char *str);
char match_cdr(char *str);

#endif  // MATCH_SCANNER_H
