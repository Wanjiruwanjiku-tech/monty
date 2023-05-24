#include "monty.h"

/**
*add - Sums up the top two items
*@stack: Double pointer to stack
*@line_number: Parameter
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack  == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next += (*stack)->n;
	pop(stack, line_number);
}
