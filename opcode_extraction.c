#include "monty.h"

/**
 * get_opcode - match the opcode with the corresponding instruction
 */
void get_opcode(void)
{
	int i;

	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pint", &pint},
		{"pop", &pop},
		{"swap", &swap}
		{NULL, NULL}
	};
	i = 0;

	if (arg_s->n_opcode_args == 0)
		return;

	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, arg_s->opcode_args[0]) == 0)
		{
			arg_s->instruction->opcode = instructions[i].opcode;
			arg_s->instruction->f = instructions[i].f;
			return;
		}
	}
	unknown_instruction();
}

/**
 * unknown_instruction - helps to free resources
 * in case the command is not known
 */
void unknown_instruction(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			arg_s->line_num, arg_s->opcode_args[0]);
	free_stream();
	free_opcode_args();
	free_args();
	exit(EXIT_FAILURE);
}
