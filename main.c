#include "monty.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/**
 * execute_monty - executes the Monty intepreter.
 *
 * @buffer: A char pointer to a buffer.
 * Return; void.
 */

void execute_monty(stack_t **stack, char *buffer)
{
	unsigned int line_number = 1;
	int ispush = 0;
	char *token;

	token = strtok(buffer, DELIMS);
	while (token != NULL)
	{
		if (ispush == 1)
		{
			stack_push(stack, line_number, token);
			ispush = 0;
			token = strtok(NULL, DELIMS);
			line_number++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
			token = strtok(NULL, DELIMS);
			continue;
		}
		else
		{
			if (get_stack_op(token) != 0)
			{
				get_stack_op(token)(stack, line_number);
			}
			else
			{
				free_stack(stack);
				invalid_opcode(token, line_number);
			}
		}
		line_number++;
		token = strtok(NULL, DELIMS);
	}
}


/**
 * main - entry into Monty interpreter.
 *
 * @argc: number of arguments passed to main.
 * @argv: A pointer to an array of arguments passed to main.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */

int main(int argc, char *argv[])
{
	int fd;
	ssize_t n_read;
	char *buffer;
	stack_t *stack = NULL;

	if (argc != 2)
		return (monty_usage());

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (file_open_error(argv[1]));

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (!buffer)
		return (malloc_failure());

	n_read = read(fd, buffer, BUFFER_SIZE);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	execute_monty(&stack, buffer);
	free_stack(&stack);
	free(buffer);
	close(fd);
	return (EXIT_SUCCESS);
}
