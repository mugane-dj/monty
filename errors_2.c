#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint_error - custom error message for pint error
 *              due to empty stack.
 * @line_number: line number with error.
 * Return: void.
 */

void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
}

/**
 * pop_error - custom error message for pop error
 *              due to empty stack.
 * @line_number: line number with error.
 * Return: void.
 */

void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an stack empty\n", line_number);
}

/**
 * swap_error - custom error message for short stack.
 * @line_number: line number with error.
 * Return: void.
 */

void swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an stack empty\n", line_number);
}

/**
 * add_error - custom error message for add error
 *              due to short stack.
 * @line_number: line number with error.
 * Return: void.
 */

void add_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
}
