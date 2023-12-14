#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || *stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
