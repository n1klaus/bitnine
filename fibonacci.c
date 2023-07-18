#include "headers.h"
#include "arithmetics.c"

/**
 * fibonacci - Calculate nth Fibonacci number
 * @n: Index of Fibonacci number to calculate
 *
 * Return: The nth Fibonacci number
 */
int fibonacci(int n)
{
	int fib[n + 1];

	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return (fib[n]);
}

/**
 * calc - Calculate result for arithmetic Node based on its operation type
 * @node: Pointer to Node containing operation
 *
 * Return: Nothing
 */
void calc(Node *node)
{

	switch (node->type)
	{
		case ADD:
			/* Perform addition */
			printf("add : %d + %d = %d\n",
			node->leftOperand, node->rightOperand, node->value);
			break;

		case SUB:
			/* Perform subtraction */
			printf("sub : %d - %d = %d\n",
			node->leftOperand, node->rightOperand, node->value);
			break;

		case MUL:
			/* Perform multiplication */
			printf("mul : %d * %d = %d\n",
			node->leftOperand, node->rightOperand, node->value);
			break;

		case DIV:
			/* Perform division */
			printf("div : %d / %d = %d\n",
			node->leftOperand, node->rightOperand, node->value);
			break;

		default:
			printf("Invalid operation type");
	}
}

/**
 * makeFunc - Get function pointer for the appropriate arithmetic
 * function based on the provided TypeTag operation type.
 * @type: TypeTag enum value indicating operation type
 *
 * Return: Pointer to arithmetic function, or NULL on error.
 */
FuncPtr makeFunc(TypeTag type)
{

	switch (type)
	{
		case ADD:
			return (&addFunc);

		case SUB:
			return (&subFunc);

		case MUL:
			return (&mulFunc);

		case DIV:
			return (&divFunc);

		default:
			printf("Invalid operation type");
			return (NULL);
	}
}

/**
 * main - Driver function to test arithmetic operations
 *
 * Return: 0 on successful completion.
*/
int main(void)
{
	Node *add = (*makeFunc(ADD))(10, 6);
	Node *mul = (*makeFunc(MUL))(5, 4);
	Node *sub = (*makeFunc(SUB))(mul, add);
	Node *fibo = (*makeFunc(SUB))(sub, NULL);

	calc(add);
	calc(mul);
	calc(sub);
	calc(fibo);
	return (0);
}
