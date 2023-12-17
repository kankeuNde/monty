#include "monty.h"

/**
 * mod - mod division of the top two elts
 * @stack: Pointer to the stack
 * @line_num: Current line number
 */
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) stack;
	if (arg_s->stack_len < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (arg_s->top->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = arg_s->top->next;
	temp->n = temp->n % arg_s->top->n;
	remove_node();
	arg_s->stack_len -= 1;
}
