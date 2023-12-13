#include "monty.h"
#define BUFSIZE 1024

int main(int argc, char **argv)
{
	char *filename;
	FILE *file;
	char *line;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else{
		filename = argv[1];	
		file = NULL;
		line = malloc(BUFSIZE * sizeof(char));
		if (!line)
		{
			perror("Error: Memory allocated failed\n");
			exit(EXIT_FAILURE);
		}
		/* fopen opens file; exits program if file cannot be opened*/
		if ((file = fopen(filename, "r")) == NULL)
		{
			perror("Error: Can't open file\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			while (fgets(line, sizeof(line), file))
			{
				/*remove_spaces(line);*/
				printf("%s", line);
			}
			fclose(file);
			if (line)
				free(line);
		}
	}
	return (0);
}
