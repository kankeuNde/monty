#ifndef _MONTY_H_
#define _MONTY_H_
#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instructions_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arguments_s - process arguments
 * @stream: File that connect to the stream from file
 * @line: text line read from the stream
 * @line_num: line number of the current instruction
 * @opcode_args: tokens of the line constituted of the opcode and args
 * @n_opcode_args: number of words on the line
 * @instruction: corresponding opcode function
 *
 * Description: hold file management variables that will require malloc
 */
typedef struct arguments_s
{
	FILE *stream;
	char *line;
	unsigned int line_num;
	char **opcode_args;
	int n_opcode_args;
	instruction_t *instruction;
	stack_t *top;
	unsigned int stack_len;
} arguments_t;

extern arguments_t *arg_s;

void raise_malloc_error(void);
void args_init();
void open_stream(char *filename);
void open_stream_err(char *filename);
void free_args();
void tokenize(void);
void get_opcode();
void unknown_instruction();
void exec_instruction();
void free_stream();
void free_opcode_args();
int is_a_num(char *str);

void push(stack_t **stack, unsigned int line_num);
/*void pop(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
*/void pall(stack_t **stack, unsigned int line_num);
/*void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);
void stack(stack_t **stack, unsigned int line_num);
void queue(stack_t **stack, unsigned int line_num);
*/

#endif
