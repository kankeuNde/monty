#include "monty.h"

void push(stack_t **my_node, unsigned int line_number)
{
	int n;

	if (stack == NULL)
	{
		stack = malloc(sizeof(stack_t));
		stack->next = NULL;
		stack->prev = NULL;
		stack->n = ((*my_node)->n);
		return;
	}

	stack_t *push_node;

	if (*my_node == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = ((*my_node)->n);
	push_node = malloc(sizeof(stack_t));
	if (push_node == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	push_node->n = n;
	push_node->prev = NULL;
	push_node->next = stack;
	if (stack != NULL)
	{
		stack->prev = NULL;
	}
	stack = push_node;
}
