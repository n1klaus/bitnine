#include <stdio.h>
#include <stdlib.h>

/**
 * TypeTag - Enumeration for arithmetic operation types
 *
 * ADD - Addition operation
 * SUB - Subtraction operation 
 * MUL - Multiplication operation
 * DIV - Division operation
 */
typedef enum {
	ADD, 
	SUB,
	MUL,
	DIV 
} TypeTag;

/**
 * Node - Structure to represent a node in expression tree
 * 
 * type - The TypeTag enum value indicating operation type 
 * leftOperand - Left operand for the operation
 * rightOperand - Right operand for the operation
 * value - Result of applying the operation to the operands
 */
typedef struct Node {
	TypeTag type;
	int leftOperand;
	int rightOperand;
	int value;
} Node;

/**
 * FuncPtr - Pointer to function returning Node pointer
 */
typedef Node * (*FuncPtr)();

/**
 * OperandUnion - Union to store int or Node pointer  
 *
 * intValue - Stores an integer value 
 * node - Stores a pointer to a Node
 */
typedef union OperandUnion {
	int intValue;
	Node *node;
} Operand;

/**
 * fibonacci - Calculate nth Fibonacci number 
 * @n: Index of Fibonacci number to calculate
 *
 * Returns: The nth Fibonacci number
 */
int fibonacci(int n) {
	int fib[n + 1];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];
}

/**
 * addFunc - Perform addition on two integers
 * @a: First integer operand
 * @b: Second integer operand  
 *
 * Returns: Pointer to the result Node containing the sum.
 */
Node* addFunc(int a, int b) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->type = ADD;
	node->leftOperand = a;
	node->rightOperand = b;
	node->value = (node->leftOperand + node->rightOperand);
	return node;
}

/**
 * subFunc - Perform subtraction on two Node operands
 * @a: Pointer to first Node operand
 * @b: Pointer to second Node operand
 * 
 * Returns: Pointer to result Node containing the difference.
 */
Node* subFunc(Node *a, Node *b) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->type = SUB;
	node->leftOperand = (a ? a->value : 0);
	node->rightOperand = (b ? b->value: 0);
	node->value = (node->leftOperand - node->rightOperand);
	return node;
}

/**
 * mulFunc - Perform multiplication on two integers
 * @a: First integer operand 
 * @b: Second integer operand
 *
 * Returns: Pointer to the result Node containing the product.
 */
Node* mulFunc(int a, int b) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->type = MUL;
	node->leftOperand = a;
	node->rightOperand = b;
	node->value = (node->leftOperand * node->rightOperand);
	return node;
}  


/**
 * divFunc - Perform division on two integers  
 * @a: First integer operand
 * @b: Second integer operand
 *
 * Return: Pointer to the result Node containing the quotient.
 */
Node* divFunc(int a, int b) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->type = DIV;
	node->leftOperand = a;
	node->rightOperand = b;
	node->value = (node->leftOperand / node->rightOperand);
	return node;
}

/**
 * calc - Calculate result for arithmetic Node based on its operation type
 * @node: Pointer to Node containing operation
 * 
 * Return: Nothing
 */
void calc(Node* node) {

	switch(node->type) {

		case ADD:
			// Perform addition
			printf("add : %d + %d = %d\n", node->leftOperand, node->rightOperand, node->value);
			break;

		case SUB:
			// Perform subtraction
			printf("sub : %d - %d = %d\n", node->leftOperand, node->rightOperand, node->value);
			break;

		case MUL:
			// Perform multiplication
			printf("mul : %d * %d = %d\n", node->leftOperand, node->rightOperand, node->value);
			break;

		case DIV:
			// Perform division
			printf("div : %d / %d = %d\n", node->leftOperand, node->rightOperand, node->value);
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
FuncPtr makeFunc(TypeTag type) {

	switch(type) {

		case ADD:
			return &addFunc;

		case SUB:
			return &subFunc;  

		case MUL:
			return &mulFunc;

		case DIV:
			return &divFunc;

		default:
			printf("Invalid operation type");
			return NULL;
	}
}

/**
 * main - Driver function to test arithmetic operations
 *
 * Return: 0 on successful completion.
*/
int main() {
	Node *add = (*makeFunc(ADD))(10, 6);
	Node *mul = (*makeFunc(MUL))(5, 4);
	Node *sub = (*makeFunc(SUB))(mul, add);
	Node *fibo = (*makeFunc(SUB))(sub, NULL);
	calc(add);
	calc(mul);
	calc(sub);
	calc(fibo);
	return 0;
}
