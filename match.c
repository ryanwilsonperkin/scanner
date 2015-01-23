#include <string.h>

char match_int(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_states[2] = {2, 3};
        for(i = 0; i < length; i++) {
                c = str[i];
                switch (state) {
                case 0:
                        if (c == '-') {
                                state = 1;
                        } else if (c == '0') {
                                state = 2;
                        } else if (c >= '0' && c <= '9') {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        if (c == '0') {
                                state = 2;
                        } else if (c >= '0' && c <= '9') {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 2:
                        return 0;
                        break;
                case 3:
                        if (!(c >= '0' && c <= '9')) {
                                return 0;
                        }
                        break;
                }
        }
        for(i = 0; i < 2; i++) {
                if (state == accept_states[i]) {
                        return 1;
                }
        }
        return 0;
}

char match_hex(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_state = 3;
        for(i = 0; i < length; i++) {
                c = str[i];
                switch (state) {
                case 0:
                        if (c == '0') {
                                state = 1;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        if (c == 'x') {
                                state = 2;
                        } else {
                                return 0;
                        }
                        break;
                case 2:
                        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 3:
                        if (!((c >= '0' && c <= '9') ||
                                        (c >= 'A' && c <= 'F'))) {
                                return 0;
                        }
                }
        }
        return (state == accept_state);
}

char match_oct(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_state = 2;
        for(i = 0; i < length; i++) {
                c = str[i];
                switch (state) {
                case 0:
                        if (c == '0') {
                                state = 1;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        if (c >= '0' && c <= '7') {
                                state = 2;
                        } else {
                                return 0;
                        }
                        break;
                case 2:
                        if (!(c >= '0' && c <= '7')) {
                                return 0;
                        }
                        break;
                }
        }
        return (state == accept_state);
}

char match_real(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_states[2] = {5, 7};
        for(i = 0; i < length; i++) {
                c = str[i];
                switch (state) {
                case 0:
                        if (c == '-') {
                                state = 1;
                        } else if (c == '0') {
                                state = 2;
                        } else if (c >= '1' && c <= '9') {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        if (c == '0') {
                                state = 2;
                        } else if (c >= '1' && c <= '9') {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 2:
                        if (c == '.') {
                                state = 4;
                        } else if (c == 'e' || c == 'E') {
                                state = 6;
                        } else {
                                return 0;
                        }
                        break;
                case 3:
                        if (c == '.') {
                                state = 4;
                        } else if (c == 'e' || c == 'E') {
                                state = 6;
                        } else if (!(c >= '0' && c <= '9')) {
                                return 0;
                        }
                        break;
                case 4:
                        if (c >= '0' && c<= '9') {
                                state = 5;
                        } else {
                                return 0;
                        }
                        break;
                case 5:
                        if (c == 'e' || c == 'E') {
                                state = 6;
                        } else if (!(c >= '0' && c <= '9')) {
                                return 0;
                        }
                        break;
                case 6:
                        if (c >= '1' && c <= '9') {
                                state = 7;
                        } else {
                                return 0;
                        }
                        break;
                case 7:
                        if (!(c >= '0' && c <= '9')) {
                                return 0;
                        }
                        break;
                }
        }
        for(i = 0; i < 2; i++) {
                if (state == accept_states[i]) {
                        return 1;
                }
        }
        return 0;
}

char match_lparen(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_state = 1;
        for(i = 0; i < length; i++) {
                c = str[i];
                switch(state) {
                case 0:
                        if (c == '(') {
                                state = 1;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        return 0;
                }
        }
        return (state == accept_state);
}

char match_rparen(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_state = 1;
        for(i = 0; i < length; i++) {
                c = str[i];
                switch(state) {
                case 0:
                        if (c == ')') {
                                state = 1;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        return 0;
                }
        }
        return (state == accept_state);
}

char match_car(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_state = 3;
        for(i = 0; i < length; i++) {
                c = str[i];
                switch(state) {
                case 0:
                        if (c == 'c') {
                                state = 1;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        if (c == 'a') {
                                state = 2;
                        } else {
                                return 0;
                        }
                        break;
                case 2:
                        if (c == 'r') {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 3:
                        return 0;
                }
        }
        return (state == accept_state);
}

char match_cdr(char *str)
{
        int i;
        int length = strlen(str);
        char c;
        char state = 0;
        const char accept_state = 3;
        for(i = 0; i < length; i++) {
                c = str[i];
                switch(state) {
                case 0:
                        if (c == 'c') {
                                state = 1;
                        } else {
                                return 0;
                        }
                        break;
                case 1:
                        if (c == 'd') {
                                state = 2;
                        } else {
                                return 0;
                        }
                        break;
                case 2:
                        if (c == 'r') {
                                state = 3;
                        } else {
                                return 0;
                        }
                        break;
                case 3:
                        return 0;
                }
        }
        return (state == accept_state);
}
