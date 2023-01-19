#include "monty.h"
#include <stdlib.h>

/**
 * stack_push - pushes a new element into the stack.
 *
 * @stack: A pointer to a pointer to a stack of type stack_t.
 * @line_number: Line number with opcode.
 * Return: void.
 */

void stack_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_failure();
		return;
	}

	if (tokens[1] == NULL)
	{
		invalid_monty_push(line_number);
		return;
	}

	new->n = atoi(tokens[1]);
	new->prev = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
	{
		new->next = NULL;
	}
	*stack = new;
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
	stack_t *tmp = (*stack)->next;

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
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL)
	{
		pint_error(line_number);
		return;
	}

	printf("%d\n", tmp->n);
	(void)line_number;
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
	stack_t *next = NULL;
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL)
	{
		pop_error(line_number);
		return;
	}
	next = tmp->next;
	free(tmp);
	if (next)
		next->prev = *stack;
	tmp = next;
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
	stack_t *top = (*stack)->next;
	stack_t *tmp;

	if (top == NULL || top->next == NULL)
	{
		swap_error(line_number);
		return;
	}

	tmp = top->next;
	top->next = tmp->next;
	top->prev = tmp;
	if (tmp->next)
		tmp->next->prev = top;
	tmp->next = top;
	tmp->prev = *stack;
	top = tmp;
}
