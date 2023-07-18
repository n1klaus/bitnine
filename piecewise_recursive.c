#include "headers.h"

/**
 * piecewiseRecursive - Recursively calculate nth Fibonacci number
 * @n: Index of Fibonacci number to calculate
 *
 * Return: nth Fibonacci number
 */

int piecewiseRecursive(int n)
{
	if (n == 0)
	{
		return (0);
	} else if (n == 1)
	{
		return (1);
	} else if (n == 2)
	{
		return (2);
	}
	return (piecewiseRecursive(n - 3) + piecewiseRecursive(n - 2));
}

/**
 * main - Driver function to test piecewiseRecursive()
 *
 * Return: 0 on successful completion.
 */
int main(void)
{
	int n = 10;
	int result = piecewiseRecursive(n);

	printf("F(%d) = %d\n", n, result);
	return (0);
}
