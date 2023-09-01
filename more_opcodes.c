#include "monty.h"

/**
 * opcode_pop - removes the top element of the stack.
  * @stack: doubly linked list.
 * @line_number: line of file.
 *
 * Return: Nothing.
*/

void opcode_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = temp->prev;
    free(temp);
}

/**
 * opcode_err - print an error.
 * @stack: doubly linked list.
 * @line_number: line of file.
 *
 * Return: Nothing.
*/

void opcode_err(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, buff[0]);
	exit(EXIT_FAILURE);
}
