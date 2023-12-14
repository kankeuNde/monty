#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int add_sum;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	add_sum = tmp->n + tmp->next->n;
	tmp->next->n = add_sum;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}
