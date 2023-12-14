#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *push_node;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = ((*stack)->n);
	push_node = malloc(sizeof(stack_t));
	if (push_node == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	push_node->n = n;
	push_node->prev = NULL;
	push_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	*stack = push_node;
}
