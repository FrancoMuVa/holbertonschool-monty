#include "main.h"

/**
 * create_buff - create a buffer.
 * @line: line readed of a file.
 * 
 * Return: buffer.
*/

char **create_buff(char *line)
{
	const char *delim = " \t\n";
	char *line_cpy = NULL, *token = NULL;
	int num_token = 0, i = 0;

	line_cpy = strdup(line);
	token = strtok(line, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	
	if (num_token == 1)
	{
		free(line_cpy);
		return(NULL);
	}

	buff = malloc(sizeof(char *) * num_token);
	if (!buff)
	{
		free(line_cpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	printf("-->>line_cpy:%s\n", line_cpy);
	token = strtok(line_cpy, delim);
	printf("\n-->>token: %s|\n", token);
	for (i = 0; token != NULL; i++)
	{
		buff[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (!buff[i])
		{
			free(line_cpy);
			free_buff(buff);
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(buff[i], token);
		token = strtok(NULL, delim);
		printf("\n-->>token2: %s|\n", token);
	}
	buff[i] = NULL;
	free(line_cpy);
	return(buff);
}

/**
 * get_opcod - get the opcode.
 * 
 * 
*/

void (*get_opcode(char *str))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"nop", opcode_nop}
	};
	int i = 0;

	printf ("-->> Get opcode func\n");
	while (i < 2)
	{
		printf ("\t\n-->> in while get_opcode\n");
		if (strcmp(opcodes[i].opcode, str) == 0)
			break;
		i++;
	}
	return (opcodes[i].f);
}