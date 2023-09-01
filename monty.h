#ifndef monty_h
#define monty_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern char **buff;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **create_buff(char *line);

void free_buff(char **buff);

void free_list(stack_t *stack);

void (*get_opcode(char *str))(stack_t **stack, unsigned int line_number);

void opcode_push(stack_t **stack, unsigned int line_number);

void opcode_pall(stack_t **stack, unsigned int line_number);

void opcode_pint(stack_t **stack, unsigned int line_number);

void opcode_pop(stack_t **stack, unsigned int line_number);

void opcode_nop(stack_t **stack, unsigned int line_number);

void opcode_err(stack_t **stack, unsigned int line_number);

#endif
