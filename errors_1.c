#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * monty_usage - Prints out usage error message for Monty.
 *
 * Return: EXIT_FAILURE always.
 */

int monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - Prints out file open error message.
 *
 * @file: file name of specified Monty Byte Code file.
 * Return: EXIT_FAILURE always.
 */

int file_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}

/**
 * malloc_failure - Prints error message for failed malloc.
 *
 * Return: EXIT_FAILURE always.
 */

int malloc_failure(void)
{
	fprintf(stderr, "Error: malloc failed");
	return (EXIT_FAILURE);
}

/**
 * invalid_opcode - Prints error message for invalid instruction.
 *
 * @opcode: instruction specified.
 * @line_number: line number where instruction exists in file.
 * Return: EXIT_FAILURE always.
 */

int invalid_opcode(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * invalid_monty_push - Prints error message for non-int monty push.
 *
 * @line_number: line number specified.
 * Return: EXIT_FAILURE always.
 */

int invalid_monty_push(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer", line_number);
	return (EXIT_FAILURE);
}
