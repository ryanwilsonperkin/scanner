#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "match.h"
#include "scanner.h"

#define MAX_LEXEME_SIZE 1024

void emit_token(enum Token tok)
{
        switch(tok) {
        case INT:
                printf("INT ");
                break;
        case HEX:
                printf("HEX ");
                break;
        case OCT:
                printf("OCT ");
                break;
        case REAL:
                printf("REAL ");
                break;
        case LPAREN:
                printf("LPAREN ");
                break;
        case RPAREN:
                printf("RPAREN ");
                break;
        case CAR:
                printf("CAR ");
                break;
        case CDR:
                printf("CDR ");
                break;
        case CHAR:
                printf("CHAR ");
                break;
        case STR:
                printf("STR ");
                break;
        }
}

int is_whitespace(char c)
{
        return c == ' ' || c == '\n' || c == '\t';
}

enum Token recognize_token(char *str)
{
        if (match_int(str)) return INT;
        else if (match_hex(str)) return HEX;
        else if (match_oct(str)) return OCT;
        else if (match_real(str)) return REAL;
        else if (match_lparen(str)) return LPAREN;
        else if (match_rparen(str)) return RPAREN;
        else if (match_car(str)) return CAR;
        else if (match_cdr(str)) return CDR;
        else if (strlen(str) == 1) return CHAR;
        else return STR;
}

int main()
{
        char c;
        char reading_lexeme = 0;
        char *lexeme = malloc(MAX_LEXEME_SIZE);
        size_t lexeme_len = 0;
        while (!feof(stdin)) {
                c = getchar();
                if (is_whitespace(c)) {
                        if (reading_lexeme) {
                                reading_lexeme = 0;
                                emit_token(recognize_token(lexeme));
                                memset(lexeme, 0, MAX_LEXEME_SIZE);
                                lexeme_len = 0;
                        } else {
                                continue;
                        }
                } else {
                        reading_lexeme = 1;
                        lexeme[lexeme_len] = c;
                        lexeme[++lexeme_len] = '\0';
                }
        }
}
