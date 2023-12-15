#include "monty.h"

/**
 * tokenize - get the opcode and arguments from a line
 */
void tokenize(void)
{
	int i;
	char *delimiters, *token, *line_cp;

	i = 0;
	delimiters = " \n";
	token = NULL;
	line_cp = NULL;

	line_cp = malloc((strlen(arg_s->line) + 1) * sizeof(char));
	strcpy(line_cp, arg_s->line);
	arg_s->n_opcode_args = 0;
	token = strtok(line_cp, delimiters);
	while (token)
	{
		arg_s->n_opcode_args += 1;
		token = strtok(NULL, delimiters);
	}

	arg_s->opcode_args = malloc((arg_s->n_opcode_args + 1) * sizeof(char *));
	strcpy(line_cp, arg_s->line);
	token = strtok(line_cp, delimiters);
	while (token)
	{
		arg_s->opcode_args[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (arg_s->opcode_args[i] == NULL)
			raise_malloc_error();
		strcpy(arg_s->opcode_args[i], token);
		token = strtok(NULL, delimiters);
		i++;
	}
	arg_s->opcode_args[i] = NULL;
	free(line_cp);

}
