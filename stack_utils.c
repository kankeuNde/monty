#include "monty.h"

/**
 * is_a_num - check if the arg is a number
 * @str: The string to check
 * Return: 1 if it is a number and 0 otherwise
 */
int is_a_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * remove_node - remove the top node
 *
 * Return: void
 */
void remove_node(void)
{
	stack_t *temp;

	temp = arg_s->top;
	arg_s->top = temp->next;
	free(temp);
}
