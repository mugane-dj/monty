#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Macros */
#define DELIMS " \n\t\a\b"
#define BUFFER_SIZE 1000


/* Data structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Error message prototypes */
void monty_usage(void);
void file_open_error(char *file);
void malloc_failure(void);
void invalid_opcode(char *opcode, unsigned int line_number);
void invalid_monty_push(unsigned int line_number);
void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);
void swap_error(unsigned int line_number);
void add_error(unsigned int line_number);

/* Monty prototypes */
void (*get_stack_op(char *opcode))(stack_t **stack, unsigned int line_number);
void execute_monty(stack_t **stack, char *buffer);
void stack_push(stack_t **stack, unsigned int line_number, const char *n);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);

/* Helper functions */
void free_stack(stack_t **stack);
int isdigit(int c);

#endif /* __MONTY_H__ */
