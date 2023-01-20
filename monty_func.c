#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * stack_push - pushes a new element into the stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: Line number with opcode.
 * @n: token.
 * Return: void.
 */

void stack_push(stack_t **stack, unsigned int line_number, const char *n)
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_failure();
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);
	if((new->n == 0 && *n != '0') || (new->n == 0 && *n == '0')
	{
		invalid_monty_push(line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
	}
}

/**
 * stack_pall - prints all elements in the stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: The line number where opcode is located.
 * Return: void.
 */

void stack_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * stack_pint - prints the elements at the top of the stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: The line number where opcode is located.
 * Return: void.
 */

void stack_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		pint_error(line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}

/**
 * stack_pop - removes the top element on a stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: The line number where opcode is located.
 * Return: void.
 */

void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pop_error(line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = *stack;
		if ((*stack)->next == NULL)
		{
			*stack = NULL;
			free(tmp);
		}
		else
		{
			*stack = (*stack)->next;
			tmp->prev = NULL;
			free(tmp);
		}
	}
}

/**
 * stack_swap - swaps top elements in the stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: Line number with opcode.
 * Return: void.
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		swap_error(line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	if (tmp->next)
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	else
	{
		(*stack)->next = tmp->next;
		(*stack)->next->prev = *stack;
	}
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
}
