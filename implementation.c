#include "monty.h"
#include <stdio.h>

#define MAX_LINE_SIZE 100

/**
*main - The Main Entry point
*
*Description: Code implementations for the prototypes
*Return: void
*/
int main(void)
{
	char *opcode;
	int value;
	ssize_t read;
	char line[MAX_LINE_SIZE];
	unsigned int line_number = 0;
	char *arg;

	while (fgets(line, sizeof(line), stdin) != NULL
)
	{
		read = strlen(line);
		if (line[read - 1] == '\n')
		{
			line[read -1] = '\0';
		}
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);

		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
