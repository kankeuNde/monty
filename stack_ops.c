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

/**
 * pint - prints the top
 * @stack: Pointer to the stack
 * @line_num: current line number
 */
void pint(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	if (arg_s->top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", arg_s->top->n);
}

/**
 * pop - remove the top node
 * @stack: Pointer to the stack
 * @line_num: current line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	if (arg_s->top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	remove_node();
	arg_s->stack_len -= 1;
}

/**
 * swap - swaps the top two nodes
 * @stack: Pointer to the stack
 * @line_num: current line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *node1, *node2;

	(void) stack;
	if (arg_s->stack_len < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	node1 = arg_s->head;
	node2 = node1->next;
	node1->next = node2->next;
	if (node1->next)
		node1->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
	node2->prev = NULL;
	arg_s->head = node2;
}
