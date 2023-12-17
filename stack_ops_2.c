#include "monty.h"

/**
 * add - sum up the top two elts
 * @stack: Pointer to the stack
 * @line_num: Current line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) stack;
	if (arg_s->stack_len < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp = arg_s->top->next;
	temp->n = arg_s->top->n + temp->n;
	remove_node();
	arg_s->stack_len -= 1;
}

/**
 * nop - do nothing
 * @stack: Pointer to the stack
 * @line_num: Current line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
