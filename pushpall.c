#include "monty.h"

/**
 * push - push elements to stack
 *
 * @heady: linked lists head
 *
 * @nmbr_line: number of line
 *
 * Return: no return
 */
 
void push(stack_t **heady, unsigned int nmbr_line)
{
	int z;
	int y;
/* z stores the pushed integer & y is to go over characters in arg field*/
    y = 0;
/* if characters are not digits or minus sign print error message and exit */
while (globv.arg[y] != '\0')
{
	if (!isdigit(globv.arg[y]) && globv.arg[y] != '-')
	{
		dprintf(2, "L%u: ", nmbr_line);
		dprintf(2, "usage: push integer\n");
		free_stacky();
		exit(EXIT_FAILURE);
	}
	y++;
}
/* if arg field is empty error message and exit */
if (!globv.arg)
{
	dprintf(2, "L%u: ", nmbr_line);
	dprintf(2, "usage: push integer\n");
	free_stacky();
	exit(EXIT_FAILURE);
}
/* convert the arg to integer */
	z = atoi(globv.arg);
/* if lifo field of the global globv variable is set to 1 push element to front of stack otherwise push element to the end of stack*/
	if (globv.lifo == 1)
		add_dnodeint(heady, z);
	else
		add_dnodeint_end(heady, z);
}

/**
 * pall - prints all values on the stack
 *
 * @heady: linked lists head
 *
 * @nmbr_line: number of line
 *
 * Return: no return
 */
 
void pall(stack_t **heady, unsigned int nmbr_line)
{
	stack_t *usb;
	(void)nmbr_line;
/*loop adds usb variable at the head of linked list then checks if usb is NULL if yes terminates */
/*& print its value to standard output then increases usb to move to next element in linked list then repeats until usb is NULL*/
	for (usb = *heady; usb != NULL; usb = usb->next)
	{
		printf("%d\n", usb->n);
	}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @heady: linked lists head
 *
 * @nmbr_line: number of line
 *
 * Return: no return
 */
 
void pint(stack_t **heady, unsigned int nmbr_line)
{
	(void)nmbr_line;
/*if the heady is NULL print an error message and exits */
	if (*heady == NULL)
	{
		dprintf(2, "L%u: ", nmbr_line);
		dprintf(2, "can't pint, stack empty\n");
		free_stacky();
		exit(EXIT_FAILURE);
	}
/* if not, print heady to standard output at the top of stack */
	printf("%d\n", (*heady)->z);
}

/**
 * pop - removes the top element of the stack
 *
 * @heady: linked lists head
 *
 * @nmbr_line: number of line
 *
 * Return: no return
 */
 
void pop(stack_t **heady, unsigned int nmbr_line)
{
	stack_t *usb;
/*usb to store the top element ofstack*/
/*if the heady is NULL or stack is empty print an error message and exits */
	if (heady == NULL || *heady == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", nmbr_line);
		free_stacky();
		exit(EXIT_FAILURE);
	}
	
	usb = *heady;
	*heady = (*heady)->next;
	
	free(usb);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @heady: linked lists head
 *
 * @nmbr_line: number of line
 *
 * Return: no return
 */
 
void swap(stack_t **heady, unsigned int nmbr_lin)
{
	int x = 0;
	stack_t *usb = NULL;
/* x is used to count the number of elements in stack */
/* usb is used to store temporary pointer at the top element of stack*/
	usb = *heady;
/* count number of elements in stack */
	while (usb != NULL)
	{
		usb = usb->next;
		x++;
	}
/* if the stack doesnt contain two elements print an error message and exits */
	if (x < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nmbr_line);
		free_stacky();
		exit(EXIT_FAILURE);
	}

	usb = *heady;
	*heady = (*heady)->next;
	usb->next = (*heady)->next;
	usb->prev = *heady;
	(*heady)->next = usb;
	(*heady)->prev = NULL;
}
