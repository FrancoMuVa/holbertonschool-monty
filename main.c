#include "monty.h"

char **buff;

/**
 * free_buff - free a buffer.
 * @buff: buffer to free.
 *
 * Return: Nothing.
*/

void free_buff(char **buff)
{
	int i = 0;

	while (buff[i] != NULL)
		free(buff[i++]);

	free(buff);
}


FILE *open_file(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - main program.
 * @argc: number of arguments.
 * @argv: array of arguments.
 *
 * Return: 0 (Success).
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	ssize_t ch_read = 0;
	size_t in_size = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc == 2)
	{
		file = open_file(argv[1]);
		buff = NULL;
		while (1)
		{
			ch_read = getline(&line, &in_size, file);
			if (ch_read == -1)
			{
				fclose(file);
				free(line);
				free_list(stack);
				return (0);
			}
			buff = create_buff(line);
			line_number++;
			if (buff != NULL)
			{
				get_opcode(buff[0])(&stack, line_number);
				free_buff(buff);
			}
		}
		free_list(stack);
		free(line);
		fclose(file);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
