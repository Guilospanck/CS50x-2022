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

## Array
It's the same thing as above (because a string is an array of char).

You can do `Pointer arithmetic` just moving bytes. We know that `1 char equals to 1 byte`,` so when we move something like:

<code>
char *s = "Hi!";

printf("%c\n", *s);

printf("%c\n", *(s + 1));
</code>

We're moving 1 byte per time, and then getting the next char.

But we also know that usually `1 integer equals 4 bytes`. If we do the same for an array of integers, would it just move 1 byte?

The fortunate thing is NO, because the compiler know how many bytes a type needs, so it's going to move that necessary amount.

Each `pointer arithmetic` for this array of integers will move 4 bytes and we don't even have to say it to the compiler.

E.g.:
<code>
int numbers[] = {1, 2, 3};

printf("%i\n", *numbers); // will print 1

printf("%i\n", *(numbers + 1)); // will print 2
</code>