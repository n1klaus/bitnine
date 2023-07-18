#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/**
 * TypeTag - Enumeration for arithmetic operation types
 *
 * ADD - Addition operation
 * SUB - Subtraction operation
 * MUL - Multiplication operation
 * DIV - Division operation
 */
typedef enum
{
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
typedef struct Node
{
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
typedef union OperandUnion
{
	int intValue;
	Node *node;
} Operand;

#endif /* __HEADERS_H__ */
