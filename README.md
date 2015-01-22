scanner
===

A simple lexical scanner.

Tokens
---

- __INT__: positive and negative natural numbers, including zero
- __HEX__: a hexidecimal integer value (valid numerals are 0-F) with a 0x prefix
- __OCT__: an octal integer value (valid numerals are 0-7) with a 0 prefix
- __REAL__: floating point decimal and exponential notation
- __LPAREN__: left parenthesis '('
- __RPAREN__: right parenthesis ')'
- __CAR__: the string "car"
- __CDR__: the string "cdr"
- __CHAR__: any other single ASCII character
- __STR__: any other sequence of (more than 1) ASCII characters
