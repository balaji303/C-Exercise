/*
C/C++ provides various data types that can be used in your programs.

In general, you'd commonly use:

int for most variables and "countable" things (for loop counts, variables, events)
char for characters and strings
float for general measurable things (seconds, distance, temperature)
uint32_t for bit manipulations, especially on 32-bit registers
The appropriate stdint.h types for storing and working with data explicitly at the bit level

**Integer Data Types**
C type             	stdint.h type	 Bits	 Sign	        Range
char	              uint8_t	        8	 Unsigned	      0 .. 255
signed char        	int8_t	 8	Signed	-128 .. 127
unsigned short     	uint16_t	16	Unsigned	0 .. 65,535
short	int16_t      	16	Signed	-32,768 .. 32,767
unsigned int       	uint32_t	32	Unsigned	0 .. 4,294,967,295
int	int32_t	        32	Signed	-2,147,483,648 .. 2,147,483,647
unsigned long long 	uint64_t	64	Unsigned	0 .. 18,446,744,073,709,551,615
long long	          int64_t	64	Signed	-9,223,372,036,854,775,808 .. 9,223,372,036,854,775,807

**Floating Point Data Types**
C type	IEE754 Name	Bits	Range
float	Single Precision	32	-3.4E38 .. 3.4E38
double	Double Precision	64	-1.7E308 .. 1.7E308

**Data Represention**

Bit: 1 bit (0/1)
Nibble: 4 bits (0-15)
Byte: 8 bits (0-255)
Word: 16 bits (0-65535)
Double word: 32 bit (0-4294967295)
Quad word: 64 bit (0-18446744073709551615)
*/
