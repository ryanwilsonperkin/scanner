scanner
===

A simple lexical scanner.

Tokens
---

###INT

Description: *positive and negative natural numbers, including zero*

Corresponding regular expression: `-?(0|[1-9][0-9]*)`


###HEX

Description: *a hexidecimal integer value (valid numerals are 0-F) with a 0x prefix*

Corresponding regular expression: `0x[0-9A-Fa-f]+`

###OCT

Description: *an octal integer value (valid numerals are 0-7) with a 0 prefix*

Corresponding regular expression: `0[0-7]+`

###REAL

Description: *floating point decimal and exponential notation*

Corresponding regular expression: `-?(0|[1-9][0-9]*)\.[0-9]+([eE][1-9][0-9]*)?`

####LPAREN

Description: *left parenthesis '('*

Corresponding regular expression: `(`

###RPAREN

Description: *right parenthesis ')'*

Corresponding regular expression: `)`

###CAR

Description: *the string "car"*

Corresponding regular expression: `car`

###CDR

Description: *the string "cdr"*

Corresponding regular expression: `cdr`

###CHAR

Description: *any other single ASCII character*

Corresponding regular expression: `[^\(\)01-9]`

###STR

Description: *any other sequence of (more than 1) ASCII characters*

Rather than a regular expression for matching STR tokens, the token is found when the DFA is not in an accept state for any of the above tokens.
