#include "monty.h"
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
	char line[MAX_LINE_LENGTH];
	unsigned int line_number;
	stack_t *stack;
	int found;
	size_t i;
	char *opcode;
	FILE *bytecode_file;
	char *conv_strtock, int_cv_str;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <bytecode_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	bytecode_file = fopen(argv[1], "r");
	if (!bytecode_file)
	{
		perror("Error opening file");
		return (EXIT_FAILURE);
	}

	stack = malloc(sizeof(stack_t));
	line_number = 1;
	while (fgets(line, sizeof(line), bytecode_file))
	{
		opcode = strtok(line, " \n");
		if (opcode)
		{
			instruction_t instructions[] = {
				{"push", push},
				{"pall", pall},
				{"pop", pop},
				{"pint", pint},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub}
			};

			found = 0;
			for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); ++i)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					found = 1;
					conv_strtock = strtok(NULL, " \n");
					if (conv_strtock != NULL)
					{
						int_cv_str = atoi(conv_strtock);
					}
					stack->n = int_cv_str;
					instructions[i].f(&stack, line_number);
					break;
				}
			}

			if (!found)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(bytecode_file);
				return (EXIT_FAILURE);
			}
		}

		line_number++;
	}
	fclose(bytecode_file);

	return (EXIT_SUCCESS);
}
