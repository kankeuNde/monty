#include "monty.h"

void pall(stack_t **my_stack, unsigned int line_number)
{
	stack_t *print_node = stack;
	if (line_number && my_stack != NULL)
	{
		while (print_node != NULL)
		{
			printf("%d\n", print_node->n);
			print_node = print_node->next;
		}
	}
}
