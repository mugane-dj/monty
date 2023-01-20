#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * monty_usage - Prints out usage error message for Monty.
 *
 * Return: void.
 */

void monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

/**
 * file_open_error - Prints out file open error message.
 *
 * @file: file name of specified Monty Byte Code file.
 * Return: void.
 */

void file_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
}

/**
 * malloc_failure - Prints error message for failed malloc.
 *
 * Return: void.
 */

void malloc_failure(void)
{
	fprintf(stderr, "Error: malloc failed\n");
}

/**
 * invalid_opcode - Prints error message for invalid instruction.
 *
 * @opcode: instruction specified.
 * @line_number: line number where instruction exists in file.
 * Return: void.
 */

void invalid_opcode(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
}

/**
 * invalid_monty_push - Prints error message for non-int monty push.
 *
 * @line_number: line number specified.
 * Return: void.
 */

void invalid_monty_push(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
}
