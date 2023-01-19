#include "monty.h"
#include <stdlib.h>

/**
 * stack_init - initializes a newly created stack.
 *
 * @stack: A pointer to a pointer to stack_t stack.
 * Return: EXIT_SUCCESS on success,
 *         EXIT_FAILURE on error.
 */

int stack_init(stack_t **stack)
{
	stack_t *t;

	t = malloc(sizeof(stack_t));
	if (t == NULL)
		return (malloc_failure());

	t->n = 0;
	t->prev = NULL;
	t->next = NULL;

	*stack = t;

	return (EXIT_SUCCESS);
}

/**
 * free_tokens - free tokens from global var tokens.
 *
 * Return: void.
 */

void free_tokens(void)
{
	int index;

	if (tokens == NULL)
		return;

	for (index = 0; tokens[index]; index++)
		free(tokens[index]);
	free(tokens);
}

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
 * empty_line_read - checks if the line read by getline()
 *                   contains delimeters only.
 * @line: A pointer to the line read by getline().
 * @delims: A pointer to the delimeters to match.
 * Return: 1 when the line contains delims only,
 *         0 if delim is terminating null byte.
 */

int empty_line_read(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}
