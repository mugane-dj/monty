#include "monty.h"
#include <stdlib.h>

/**
 * stack_add - adds top elements in the stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: Line number with opcode.
 * Return: void.
 */

void stack_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		add_error(line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}

	tmp = top->next;
	tmp->n += top->n;
	stack_pop(stack, line_number);
}

/**
 * stack_nop - does nothing.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: Line number with opcode.
 * Return: void.
 */

void stack_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
