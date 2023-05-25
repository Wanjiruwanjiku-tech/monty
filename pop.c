#include "monty.h"

/**
*pop - Deletes the top item of a stack
*@stack: Double pointer to stack
*@line_number: Parameter
*Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;

	if (top->next)
		top->next->prev = NULL;
	free(top);
}
