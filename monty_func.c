#include "monty.h"
#include <stdlib.h>

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
		free_stack(&new);
		exit(EXIT_FAILURE);
	}

	if ((atoi(n) == 0 && *n != 0) || isdigit(atoi(n)) != 0)
	{
		invalid_monty_push(line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(n);

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

	if (!stack || !*stack)
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

	if (!stack || !*stack)
	{
		pint_error(line_number);
		free(stack);
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
	stack_t *next = NULL;
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		pop_error(line_number);
		free(stack);
		exit(EXIT_FAILURE);
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
