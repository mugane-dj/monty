#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint_error - custom error message for pint error
 *              due to empty stack.
 * @line_number: line number with error.
 * Return: EXIT_FAILURE always.
 */

int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_error - custom error message for pop error
 *              due to empty stack.
 * @line_number: line number with error.
 * Return: EXIT_FAILURE always.
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an stack empty", line_number);
	return (EXIT_FAILURE);
}

/**
 * swap_error - custom error message for short stack.
 * @line_number: line number with error.
 * Return: EXIT_FAILURE always.
 */

int swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an stack empty", line_number);
	return (EXIT_FAILURE);
}

/**
 * add_error - custom error message for add error
 *              due to short stack.
 * @line_number: line number with error.
 * Return: EXIT_FAILURE always.
 */

int add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty", line_number);
	return (EXIT_FAILURE);
}
