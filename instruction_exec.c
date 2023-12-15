#include "monty.h"

/**
 * exec_instruction - run the corresponding instruction
 */
void exec_instruction(void)
{
	stack_t *stack;

	stack = NULL;
	if (arg_s->n_opcode_args == 0)
		return;
	arg_s->instruction->f(&stack, arg_s->line_num);
}
