#include "monty.h"

/**
*pint - Prints 'THEE' valu at the top of the stack
*@stack: Double pointer to stack
*@line_number: Parameter
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n",(*stack)->n);
}
