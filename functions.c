#include "monty.h"

/**
 * free_list - free the doubly linked list.
 * @stack: doubly linked list.
 *
 * Return: Nothing.
*/

void free_list(stack_t *stack)
{
	stack_t *temp = stack;

	while (stack != NULL)
	{
		temp = stack;
		stack = temp->prev;
		free(stack);
	}
}

/**
 * counter_token - counts the token of a line.
 * @line: line of the file.
 * @delim: delim.
 *
 * Return: 0.
*/

int counter_token(char *line, const char *delim)
{
	char *token = NULL;
	int num_token = 0;

	token = strtok(line, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;
	return (num_token);
}


/**
 * create_buff - create a buffer.
 * @line: line readed of a file.
 * @stack: list.
 *
 * Return: buffer.
*/

char **create_buff(char *line)
{
	const char *delim = " \t\n";
	char *line_cpy = NULL, *token = NULL;
	int num_token = 0, i = 0;

	line_cpy = strdup(line);
	num_token = counter_token(line, delim);
	if (num_token == 1)
	{
		free(line_cpy);
		return (NULL);
	}
	buff = malloc(sizeof(char *) * num_token);
	if (!buff)
	{
		free(line);
		free(line_cpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_cpy, delim);
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
	}
	buff[i] = NULL;
	free(line_cpy);
	return (buff);
}

/**
 * get_opcode - get the opcode.
 * @str: string.
 *
 * Return: Nothing.
*/

void (*get_opcode(char *str))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"nop", opcode_nop},
		{"err", opcode_err}
	};
	int i = 0;

	while (i < 2)
	{
		if (strcmp(opcodes[i].opcode, str) == 0)
			break;
		if (strcmp(opcodes[i].opcode, "err") == 0)
			break;
		i++;
	}
	return (opcodes[i].f);
}
