#include "headers.h"

/**
 * addFunc - Perform addition on two integers
 * @a: First integer operand
 * @b: Second integer operand
 *
 * Return: Pointer to the result Node containing the sum.
 */
Node *addFunc(int a, int b)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->type = ADD;
	node->leftOperand = a;
	node->rightOperand = b;
	node->value = (node->leftOperand + node->rightOperand);
	return (node);
}

/**
 * subFunc - Perform subtraction on two Node operands
 * @a: Pointer to first Node operand
 * @b: Pointer to second Node operand
 *
 * Return: Pointer to result Node containing the difference.
 */
Node *subFunc(Node *a, Node *b)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->type = SUB;
	node->leftOperand = (a ? a->value : 0);
	node->rightOperand = (b ? b->value : 0);
	node->value = (node->leftOperand - node->rightOperand);
	return (node);
}

/**
 * mulFunc - Perform multiplication on two integers
 * @a: First integer operand
 * @b: Second integer operand
 *
 * Return: Pointer to the result Node containing the product.
 */
Node *mulFunc(int a, int b)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->type = MUL;
	node->leftOperand = a;
	node->rightOperand = b;
	node->value = (node->leftOperand * node->rightOperand);
	return (node);
}


/**
 * divFunc - Perform division on two integers
 * @a: First integer operand
 * @b: Second integer operand
 *
 * Return: Pointer to the result Node containing the quotient.
 */
Node *divFunc(int a, int b)
{
	Node *node = (Node *)malloc(sizeof(Node));

	node->type = DIV;
	node->leftOperand = a;
	node->rightOperand = b;
	node->value = (node->leftOperand / node->rightOperand);
	return (node);
}
