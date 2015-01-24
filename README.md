scanner
===

A simple lexical scanner.

Tokens
---

###INT

*positive and negative natural numbers, including zero*

Corresponding regular expression: `-?(0|[1-9][0-9]*)`


###HEX

*a hexidecimal integer value (valid numerals are 0-F) with a 0x prefix*

Corresponding regular expression: `0x[0-9A-Fa-f]+`

###OCT

*an octal integer value (valid numerals are 0-7) with a 0 prefix*

Corresponding regular expression: `0[0-7]+`

###REAL

*floating point decimal and exponential notation*

Corresponding regular expression: `-?(0|[1-9][0-9]*)\.[0-9]+([eE][1-9][0-9]*)?`

####LPAREN

*left parenthesis '('*

Corresponding regular expression: `(`

###RPAREN

*right parenthesis ')'*

Corresponding regular expression: `)`

###CAR

*the string "car"*

Corresponding regular expression: `car`

###CDR

*the string "cdr"*

Corresponding regular expression: `cdr`

###CHAR

*any other single ASCII character*

Corresponding regular expression: `.`

###STR

*any other sequence of (more than 1) ASCII characters*

Corresponding regular expression: `..+`
