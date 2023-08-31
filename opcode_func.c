#include "monty.h"

/**
 * opcode_push - push to the stak.
 * @stack: doubly linked list.
 * @line_number: line of file.
 *
 * Return: Nothing.
*/

void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *temp;
	int i, num;

	if (buff[1][0] == '-' || isdigit(buff[1][0]) != 0)
	{
		for (i = 1; buff[1][i]; i++)
		{
			if (isdigit(buff[1][i]) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		/*close file*/
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	num = atoi(buff[1]);
	new->n = num;
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		temp->next = new;
		new->prev = *stack;
		*stack = new;
	}
}

/**
 * opcode_pall - print the stack.
 * @stack: doubly linked list.
 * @line_number: line of file.
 *
 * Return: Nothing.
*/

void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (!stack)
	{
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n > -1)
			printf("%u\n", temp->n);
		else
			printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * opcode_nop - Do nothing.
 * @stack: doubly linked list.
 * @line_number: line of file.
 *
 * Return: Nothing.
*/

void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
