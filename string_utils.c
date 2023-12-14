#include "monty.h"

int find_character(char *string, char character)
{
	int index = 0;

	while (string[index] != '\0')
	{
		if (string[index] == character)
		{
			break;
		}
		index++;
	}
	if (string[index] == character)
		return (1);
	else
		return (0);
}

/**
 * cut_string - function that cuts a string into tokens depending on the delimiter
 * @string: string to cut in parts
 * @delimiter: delimiters
 * Return: first partition
 */
char *cut_string(char *string, char *delimiter)
{
	static char *last_token;
	int i = 0, j = 0;

	if (!string)
		string = last_token;
	while (string[i] != '\0')
	{
		if (find_character(delimiter, string[i]) == 0 && string[i + 1] == '\0')
		{
			last_token = string + i + 1;
			*last_token = '\0';
			string = string + j;
			return (string);
		}
		else if (find_character(delimiter, string[i]) == 0 && find_character(delimiter, string[i + 1]) == 0)
			i++;
		else if (find_character(delimiter, string[i]) == 0 && find_character(delimiter, string[i + 1]) == 1)
		{
			last_token = string + i + 1;
			*last_token = '\0';
			last_token++;
			string = string + j;
			return (string);
		}
		else if (find_character(delimiter, string[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}


/**
 * tokenize_cmd - tokenize a command
 * @cmd: command to tokenize
 * @delim: delimiter
 * @num_tokens: number of tokens
 *
 * Return: the array of tokens
 */
char **tokenize_cmd(char *cmd, const char *delim, int *num_tokens)
{
	char **tokens, *token;
	int max_tokens, i;

	max_tokens = strlen(cmd) / 2 + 1;
	tokens = malloc(max_tokens * sizeof(char *));
	i = 0;
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(cmd, delim);
	while (token != NULL && i < max_tokens)
	{
		tokens[i] = malloc((strlen(token) + 1) * sizeof(char));
		if (!tokens[i])
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	*num_tokens = i;

	return (tokens);
}

void remove_spaces(char *str)
{
        int len, i, j, k;

        len = strlen(str);
        i = 0;
        j = len - 1;
        while (str[i] == ' ')
                i++;
        while (str[j] == ' ')
                j--;
        for (k = 0; k <= j - i; k++)
                str[k] = str[k + i];
        str[j - i + 1] = '\0';
}

/*void _perror(int fd, char *msg)
{
	int len;
	char buf[1024];

	len = 0;
	len = sprintf(buf, "%s", msg);
	write(fd, buf, len);
}*/
