#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_stack_op - function pointer that matches opcodes
 *                to stack operations.
 *
 * @opcode: opcode to match.
 * Return: A pointer to a stack operation on success, NULL on failure.
 */

void (*get_stack_op(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int index;
	instruction_t ops[] = {
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"nop", stack_nop},
		{NULL, NULL},
	};

	for (index = 0; ops[index].opcode; index++)
	{
		if (strcmp(opcode, ops[index].opcode) == 0)
			return (ops[index].f);
	}

	return (NULL);
}
