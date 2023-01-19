#define _GNU_SOURCE
#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **tokens;

/**
 * execute_monty - execute opcodes from file with byte code.
 *
 * @byte_code: A pointer to file with byte code.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */

int execute_monty(FILE *byte_code)
{
	char *line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int exit = EXIT_SUCCESS;
	unsigned int line_number = 1;
	void (*stack_op)(stack_t**, unsigned int);

	tokens = (char **)malloc(sizeof(char *) * MAX_LINE_LENGTH);

	nread = getline(line, &len, byte_code);

	while (nread != -1)
	{
		line_number++;
		*tokens = strtok(*line, DELIMS);
		if (tokens == NULL)
		{
			if (empty_line_read(*line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_failure());
		}
		stack_op = get_stack_op(tokens[0]);
		if (stack_op == NULL)
		{
			free_stack(&stack);
			exit = invalid_opcode(tokens[0], line_number);
			free_tokens();
			break;
		}
		stack_op(&stack, line_number);
		free_tokens();
	}
	free_stack(&stack);
	return (exit);
}

/**
 * main - entry point for running Monty Interpreter.
 *
 * @argc: count of arguments.
 * @argv: pointer to an array of char pointers to arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	FILE *byte_code = NULL;
	int exit = EXIT_SUCCESS;

	if (argc != 2)
		return (monty_usage());

	byte_code = fopen(argv[1], "r");

	if (byte_code == NULL)
		return (file_open_error(argv[1]));

	exit = execute_monty(byte_code);
	fclose(byte_code);
	return (exit);
}
