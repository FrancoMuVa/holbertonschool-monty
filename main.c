#include "main.h"

/**
 * free_buff - free a buffre.
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


/**
 * main - get the inputs.
 * 
 */

int main (int argc, char **argv)
{
	FILE *file;
	char *line = NULL, **buff = NULL;
	ssize_t ch_read = 0;
	size_t in_size = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		ch_read = getline(&line, &in_size, file);
		if (ch_read == -1)
		{
			return (0);
		}
		buff = create_buff(line);
		line_number++;
		get_opcode(buff[0])(&stack, line_number);
		
	}

}