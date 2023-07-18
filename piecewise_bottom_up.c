#include <stdio.h>

/**
 * piecewiseBottomUp - Calculate nth Fibonacci number using bottom-up dynamic programming
 * @n: Index of Fibonacci number to calculate
 * 
 * Return: The nth Fibonacci number
 */
int piecewiseBottomUp(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }

    // Create an array to store computed values
    int memo[n + 1];

    // Initialize the base cases
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    // Compute the remaining values
    for (int i = 3; i <= n; i++) {
        memo[i] = memo[i - 3] + memo[i - 2];
    }

    return memo[n];
}

/**
 * main - Driver function to test piecewiseBottomUp()
 * 
 * Return: 0 on successful completion.
 */
int main() {
    int n = 10;
    int result = piecewiseBottomUp(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
