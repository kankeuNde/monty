#include "monty.h"

/*void push(stack_t *top, int data)
{
	stack_t *newElt;

	newElt = malloc(sizeof(stack_t));
	if (newElt == NULL)
	{
		perror("No memory available...");
		exit(EXIT_FAILURE);
	}
	newElt->n = data;
	newElt->prev = NULL;
	newElt->next = top;
	if (top != NULL)
	{
		top->prev = newElt;
	}
	top = newElt;
}

void pop(stack_t *top)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t));
	if (!top)
	{
		free(tmp);
		perror("Empty stack, cannot remove from an Empty stack");
		exit(EXIT_FAILURE);
	}
	else if (top->next == NULL && top->prev == NULL)
	{
		tmp = top;
		top = NULL;
		free(top);
	}
	else
	{
		tmp = top;
		top = top->next;
		top->prev = NULL;
	}
}

int isEmpty(stack_t *top)
{
	if (top == NULL)
		return (1);
	else
		return (0);
}
*/
void print_stack(stack_t *top)
{
	stack_t *tmp;

	tmp = top;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

