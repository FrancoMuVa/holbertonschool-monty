#include "main.h"

char **buff = NULL;

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
	char *line = NULL;
	ssize_t ch_read = 0;
	size_t in_size = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	printf ("-->> antes argc\n");
	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file");
			exit(EXIT_FAILURE);
		}
		while(1)
		{
			printf ("-->> antes getline\n");
			ch_read = getline(&line, &in_size, file);
			if (ch_read == -1)
			{
				return (0);
			}
			printf ("-->> antes create_buff\n");
			buff = create_buff(line);
			
			if (buff != NULL)
			{
				printf ("-->> despues create_buff\n");
				line_number++;
				
				printf ("-->> ANTES get_opcode\n");

				get_opcode(buff[0])(&stack, line_number);
				
				printf ("-->> despues get_opcode\n");
				free_buff(buff);
			}
		}
		free(line);
		fclose(file);
	}
}