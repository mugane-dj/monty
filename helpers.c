#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - free a stack of type stack_t.
 *
 * @stack: A stack of type stack_t.
 * Return: void.
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}


/**
 * isdigit - checks if integer is a digit between 0 and 9
 * @c: integer to be checked
 *
 * Return: 1 if c is a digit between 0 and 9, 0 if otherwise
 */

int isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
