#include "monty.h"

arguments_t *arg_s = NULL;

/**
 * main - main entry point of the program
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	size_t n;

	n = 0;
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	args_init();
	open_stream(argv[1]);

	while (getline(&arg_s->line, &n, arg_s->stream) != -1)
	{
		arg_s->line_num += 1; /*keep track of current line number*/
		tokenize();
		get_opcode();
		exec_instruction();
		free_opcode_args();
		/*		printf("%s", arg_s->line);*/
	}
	free_stream();/* close the stream*/
	free_args();
	return (0);
}


/**
 * open_stream_err - Error handling during stream reading
 * @filename: file name
 */
void open_stream_err(char *filename)
{
	dprintf(2, "Error: Can't open file %s\n", filename);
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * open_stream - open stream for reading
 * @filename: file name
 */
void open_stream(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		open_stream_err(filename);
	arg_s->stream = fdopen(fd, "r");
	if (arg_s->stream == NULL)
	{
		close(fd);
		open_stream_err(filename);
	}
}
