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
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = temp->prev;
    free(temp);
}

/**
 * opcode_swap - Swap the top two elements.
 * @stack: doubly linked list.
 * @line_number: line of file.
 *
 * Return: Nothing.
*/

void opcode_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    int num = 0;

    if (*stack != NULL)
    {
        temp = temp->prev;
        if (temp != NULL)
        {
            num = temp->n;
            temp->n = temp->next->n;
            temp->next->n = num;
            return;            

        }
    }
    fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
    exit(EXIT_FAILURE);
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
