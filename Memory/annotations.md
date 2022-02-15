# Hexadecimal
0 1 2 3 4 5 6 7 8 9 A B C D E F

Each hexadecimal represents 4 bits.

<code>
16^1 -------  16^0

0  -----------  F
</code>

then:

<code>
16 ---------  1

0 ----------  F
</code>

then:

`
(16 * 0) + (1 * 15) =  15
`

## Representation
0x0F = 0F<sub>16</sub> = 15<sub>10</sub> = 0000 1111 <sub>2</sub>

# Pointers
- &: gets the address of some variable
- *variable : informs to the compiler that this variable is a pointer to some address.

<code>
int n = 50;

int *p = &n; // p is a pointer to the address where n is stored

printf("%p\n", p); // prints the address (eg.: 0x7ffc7cc653cc)

printf("%i\n", *p); // prints the value of that address (50)
</code>

## Strings
An string is actually a pointer to the beginning of a char.

<code>
string s = "Hi!";

equals to 

char *s = "Hi!";
</code>