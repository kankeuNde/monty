#include "monty.h"

/**
 * args_init - initializes an arguments_t
 *
 */
void args_init(void)
{
	arg_s = malloc(sizeof(arguments_t));
	if (arg_s == NULL)
		raise_malloc_error();
	arg_s->instruction = malloc(sizeof(instruction_t));
	if (arg_s->instruction == NULL)
		raise_malloc_error();
	arg_s->stream = NULL;
	arg_s->line = NULL;
	arg_s->line_num = 0;
	arg_s->opcode_args = NULL;
	arg_s->stack_len = 0;
}

/**
 * free_args - free resources
 */
void free_args(void)
{
	if (arg_s == NULL)
		return;
	if (arg_s->instruction)
	{
		free(arg_s->instruction);
		arg_s->instruction = NULL;
	}

	free_top();

	if (arg_s->line)
	{
		free(arg_s->line);
		arg_s->line = NULL;
	}
	free(arg_s);
}

/**
 * free_top - free memory of the top node
 */
void free_top(void)
{
	if (arg_s->top)
		free_stack(arg_s->top);
	arg_s->top = NULL;
}
