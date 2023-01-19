#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Macros */
#define DELIMS " \n\t\a\b"
#define MAX_LINE_LENGTH 256


/* Global tokens variable */
extern char **tokens;

/* Structs */
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
int monty_usage(void);
int file_open_error(char *file);
int malloc_failure(void);
int invalid_opcode(char *opcode, unsigned int line_number);
int invalid_monty_push(unsigned int line_number);
int pint_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int swap_error(unsigned int line_number);
int add_error(unsigned int line_number);

/* Monty prototypes */
void (*get_stack_op(char *opcode))(stack_t**, unsigned int);
int execute_monty(FILE *byte_code);
void stack_push(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);

/* Helper functions */
int stack_init(stack_t **stack);
void free_tokens(void);
void free_stack(stack_t **stack);
int empty_line_read(char *line, char *delims);

#endif /* __MONTY_H__ */
