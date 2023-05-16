# Input Format in C

scanf() plays a vital role in getting input from the user

| Conversion Character | Meaning |
| --- | --- |
| %c | read a single character |
| %d | read a signed decimal integer |
| %i | reads signed integer based on the prefix* |
| %u | reads an unsigned decimal integer |
| %o | reads an unsigned octal integer |
| %x, %X | reads an unsigned hexadecimal integer |
| %f | reads a floating point integer |
| %e, %E | reads a floating point integer |
| %g, %G | reads a floating point integer |
| %s | reads a string |

*Base is defined by the prefix of the input number. Reads a signed hexadecimal format if the prefix is 0x
Reads a signed octadecimal format if the prefix is 0 

# Output Format in C

printf() plays a vital role of the C Programming language.

| Conversion Character | Meaning |
| --- | --- |
| %c | print a single character |
| %d,%i | prints a decimal integer |
| %u | prints unsigned decimal integer |
| %o | prints octal integer |
| %x | print an unsigned hexadecimal integer using small alphabets |
| %X | print an unsigned hexadecimal integer using Capital alphabets |
| %f | print a floating point number |
| %e | print a floating point number in exponential format |
| %E | print a floating point number in exponential format but uses E for exponential|
| %g | prints a floating point number %f or %e  whichever is shorter |
| %G | prints a floating point number using %f or %E whichever is shorter |
| %s | print a string |
| %% | print a percentage value |
| %p | print a pointer in hexadecimal format |

# QandA

1. What is the format to read 
   1. Integer input
   1. Floating point input
   1. String input