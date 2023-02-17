#include <stdio.h>
/**
 * main - program that prints the size of various types on the computer
 * Return: 0 excellent
 */
int main(void)
{
	char b;
	int c;
	long int a;
	long long int f;
	float g;
printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(b));
printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(c));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(a));
printf("Size of a long long: %lu byte(s)\n", (unsigned long)sizeof(f));
printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(g));
return (0);
}
