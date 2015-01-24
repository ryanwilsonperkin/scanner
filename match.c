/*
 * match.c
 * A simple state based token matcher
 */
#include <string.h>
#include "match.h"

#define NUM_STATES 21
#define REJECT_STATE 21

enum Token recognize_token(char *str)
{
        int i, j;
        int transition;
        int length = strlen(str);
        short state = 0;
        short transitions[NUM_STATES + 1][256]; 

        for (i = 0; i < 256; i++) {
                transitions[0][i] = 7;
                for (j = 1; j < NUM_STATES + 1; j++) {
                        transitions[j][i] = REJECT_STATE;
                }
        }
        transitions[0]['-'] = 1;
        transitions[0]['0'] = 2;
        transitions[0]['1'] = 3;
        transitions[0]['2'] = 3;
        transitions[0]['3'] = 3;
        transitions[0]['4'] = 3;
        transitions[0]['5'] = 3;
        transitions[0]['6'] = 3;
        transitions[0]['7'] = 3;
        transitions[0]['8'] = 3;
        transitions[0]['9'] = 3;
        transitions[0]['('] = 4;
        transitions[0][')'] = 5;
        transitions[0]['c'] = 6;
        transitions[1]['0'] = 8;
        transitions[1]['1'] = 9;
        transitions[1]['2'] = 9;
        transitions[1]['3'] = 9;
        transitions[1]['4'] = 9;
        transitions[1]['5'] = 9;
        transitions[1]['6'] = 9;
        transitions[1]['7'] = 9;
        transitions[1]['8'] = 9;
        transitions[1]['9'] = 9;
        transitions[2]['0'] = 10;
        transitions[2]['1'] = 10;
        transitions[2]['2'] = 10;
        transitions[2]['3'] = 10;
        transitions[2]['4'] = 10;
        transitions[2]['5'] = 10;
        transitions[2]['6'] = 10;
        transitions[2]['7'] = 10;
        transitions[2]['x'] = 11;
        transitions[2]['X'] = 11;
        transitions[2]['.'] = 17;
        transitions[3]['0'] = 3;
        transitions[3]['1'] = 3;
        transitions[3]['2'] = 3;
        transitions[3]['3'] = 3;
        transitions[3]['4'] = 3;
        transitions[3]['5'] = 3;
        transitions[3]['6'] = 3;
        transitions[3]['7'] = 3;
        transitions[3]['8'] = 3;
        transitions[3]['9'] = 3;
        transitions[3]['.'] = 17;
        transitions[3]['e'] = 19;
        transitions[3]['E'] = 19;
        transitions[6]['a'] = 12;
        transitions[6]['d'] = 13;
        transitions[8]['.'] = 17;
        transitions[8]['e'] = 19;
        transitions[8]['E'] = 19;
        transitions[9]['0'] = 9;
        transitions[9]['1'] = 9;
        transitions[9]['2'] = 9;
        transitions[9]['3'] = 9;
        transitions[9]['4'] = 9;
        transitions[9]['5'] = 9;
        transitions[9]['6'] = 9;
        transitions[9]['7'] = 9;
        transitions[9]['8'] = 9;
        transitions[9]['9'] = 9;
        transitions[9]['.'] = 17;
        transitions[9]['e'] = 19;
        transitions[9]['E'] = 19;
        transitions[10]['0'] = 10;
        transitions[10]['1'] = 10;
        transitions[10]['2'] = 10;
        transitions[10]['3'] = 10;
        transitions[10]['4'] = 10;
        transitions[10]['5'] = 10;
        transitions[10]['6'] = 10;
        transitions[10]['7'] = 10;
        transitions[11]['0'] = 14;
        transitions[11]['1'] = 14;
        transitions[11]['2'] = 14;
        transitions[11]['3'] = 14;
        transitions[11]['4'] = 14;
        transitions[11]['5'] = 14;
        transitions[11]['6'] = 14;
        transitions[11]['7'] = 14;
        transitions[11]['8'] = 14;
        transitions[11]['9'] = 14;
        transitions[11]['A'] = 14;
        transitions[11]['B'] = 14;
        transitions[11]['C'] = 14;
        transitions[11]['D'] = 14;
        transitions[11]['E'] = 14;
        transitions[11]['F'] = 14;
        transitions[11]['a'] = 14;
        transitions[11]['b'] = 14;
        transitions[11]['c'] = 14;
        transitions[11]['d'] = 14;
        transitions[11]['e'] = 14;
        transitions[11]['f'] = 14;
        transitions[12]['r'] = 15;
        transitions[13]['r'] = 16;
        transitions[14]['0'] = 14;
        transitions[14]['1'] = 14;
        transitions[14]['2'] = 14;
        transitions[14]['3'] = 14;
        transitions[14]['4'] = 14;
        transitions[14]['5'] = 14;
        transitions[14]['6'] = 14;
        transitions[14]['7'] = 14;
        transitions[14]['8'] = 14;
        transitions[14]['9'] = 14;
        transitions[14]['A'] = 14;
        transitions[14]['B'] = 14;
        transitions[14]['C'] = 14;
        transitions[14]['D'] = 14;
        transitions[14]['E'] = 14;
        transitions[14]['F'] = 14;
        transitions[14]['a'] = 14;
        transitions[14]['b'] = 14;
        transitions[14]['c'] = 14;
        transitions[14]['d'] = 14;
        transitions[14]['e'] = 14;
        transitions[14]['f'] = 14;
        transitions[17]['0'] = 18;
        transitions[17]['1'] = 18;
        transitions[17]['2'] = 18;
        transitions[17]['3'] = 18;
        transitions[17]['4'] = 18;
        transitions[17]['5'] = 18;
        transitions[17]['6'] = 18;
        transitions[17]['7'] = 18;
        transitions[17]['8'] = 18;
        transitions[17]['9'] = 18;
        transitions[18]['0'] = 18;
        transitions[18]['1'] = 18;
        transitions[18]['2'] = 18;
        transitions[18]['3'] = 18;
        transitions[18]['4'] = 18;
        transitions[18]['5'] = 18;
        transitions[18]['6'] = 18;
        transitions[18]['7'] = 18;
        transitions[18]['8'] = 18;
        transitions[18]['9'] = 18;
        transitions[18]['e'] = 19;
        transitions[18]['E'] = 19;
        transitions[19]['1'] = 20;
        transitions[19]['2'] = 20;
        transitions[19]['3'] = 20;
        transitions[19]['4'] = 20;
        transitions[19]['5'] = 20;
        transitions[19]['6'] = 20;
        transitions[19]['7'] = 20;
        transitions[19]['8'] = 20;
        transitions[19]['9'] = 20;
        transitions[20]['0'] = 20;
        transitions[20]['1'] = 20;
        transitions[20]['2'] = 20;
        transitions[20]['3'] = 20;
        transitions[20]['4'] = 20;
        transitions[20]['5'] = 20;
        transitions[20]['6'] = 20;
        transitions[20]['7'] = 20;
        transitions[20]['8'] = 20;
        transitions[20]['9'] = 20;

        for (i = 0; i < length; i++) {
                transition = (int)str[i];
                state = transitions[state][transition];
        }

        switch(state) {
        case 2:
        case 3:
        case 8:
        case 9:
                return INT;
        case 14:
                return HEX;
        case 10:
                return OCT;
        case 18:
        case 20:
                return REAL;
        case 4:
                return LPAREN;
        case 5:
                return RPAREN;
        case 15:
                return CAR;
        case 16:
                return CDR;
        case 1:
        case 6:
        case 7:
                return CHAR;
        default:
                return STR;
        }
}
