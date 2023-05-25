#include "monty.h"

/**
*swap - Swaps The first two items of a stack
*@stack: Double pointer to stack
*@line_number: Parameter
*Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int temp;

	if(*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
