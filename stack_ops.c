#include "monty.h"

/**
 * push - push an element onto the stack.
 * @stack: Pointer to the stack
 * @line_num: current line number of the instruction
 */
void push(stack_t **stack, unsigned int line_num)
{
	if (arg_s->n_opcode_args <= 1 || !(is_a_num(arg_s->opcode_args[1])))
	{
		free_args();
		dprintf(2, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		raise_malloc_error();
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->n = (int) atoi(arg_s->opcode_args[1]);

	if (arg_s->top != NULL)
	{
		(*stack)->next = arg_s->top;
		arg_s->top->prev = *stack;
	}
	arg_s->top = *stack;
	arg_s->stack_len += 1;
}

/**
 * pall - prints all elemnts from the top of the stack
 * @stack: Pointer to the stack
 * @line_num: current line number
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (arg_s->top == NULL)
		return;
	(void)line_num;
	(void) stack;
	temp = arg_s->top;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
