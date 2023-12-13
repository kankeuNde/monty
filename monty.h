#ifndef _MONTY_H_
#define _MONTY_H_
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instructions_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void remove_spaces(char *str);
char **tokenize_cmd(char *cmd, const char *delim, int *num_tokens);
void push(stack_t *topPtr, int data);
void pop(stack_t *topPtr, int data);
int isEmpty(stack_t *topPtr);
#endif
