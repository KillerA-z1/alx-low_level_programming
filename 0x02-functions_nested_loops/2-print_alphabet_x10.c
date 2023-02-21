#include "main.h"
/**
 *print_alphabet_x10 - Entry point
 *Description:Prints 10 times the alphabet in lowercase
 */
void print_alphabet_x10(void)
{
int chl = 'a';
int c = 0;

while (c <= 9)
{
while (chl <= 'z')
{
_putchar(chl);
chl++;
}
chl = 'a'; /* reste the value of chl of next loop */
_putchar('\n');
c++;
}
}
