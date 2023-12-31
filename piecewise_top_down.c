#include "headers.h"

/**
 * piecewiseTopDown - Recursively calculate nth Fibonacci number
 * using memoization
 * @n: Index of Fibonacci number to calculate
 * @memo: Array to store computed fibonacci numbers
 *
 * Return: nth Fibonacci number
 */
int piecewiseTopDown(int n, int *memo)
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

	/* Check if already computed */
	if (memo[n] != -1)
	{
		return (memo[n]);
	}

	/* Compute and store the value */
	memo[n] = piecewiseTopDown(n - 3, memo) + piecewiseTopDown(n - 2, memo);
	return (memo[n]);
}

/**
 * main - Driver function to test piecewiseTopDown()
 *
 * Return: 0 on successful completion.
*/
int main(void)
{
	int n = 10;
	int memo[MAX_SIZE];

	/* Initialize the memoization table with -1 */
	for (int i = 0; i < MAX_SIZE; i++)
	{
		memo[i] = -1;
	}

	int result = piecewiseTopDown(n, memo);

	printf("F(%d) = %d\n", n, result);
	return (0);
}
