#include "main.h"
/**
 *main - Entry point
 *Description:prints 10 times the alphabet,in lowercase
 *Return: 0
 */
int main(void)
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
return (0);
}
