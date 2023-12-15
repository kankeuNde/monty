#include "monty.h"

/**
 * free_opcode_args - free memory used for the opcode and args
 */
void free_opcode_args(void)
{
	int i;

	i = 0;
	if (arg_s->opcode_args == NULL)
		return;

	while (arg_s->opcode_args[i])
	{
		free(arg_s->opcode_args[i]);
		i++;
	}
	free(arg_s->opcode_args);
	arg_s->opcode_args = NULL;
}

/**
 * free_stream - free memory used by the opened stream
 */
void free_stream(void)
{
	if (arg_s->stream == NULL)
		return;

	fclose(arg_s->stream);
	arg_s->stream = NULL;
}

/**
 * free_stack - free stack memory
 * @top: head of the stack
 * Return: void
 */
void free_stack(stack_t *top)
{
	if (top == NULL)
		return;

	if (top->next != NULL)
	{
		free_stack(top->next);
	}
	free(top);
}

/**
 * free_all - frees all memory allocated
 */
void free_all(void)
{
	free_stream();
	free_opcode_args();
	free_args();
}
