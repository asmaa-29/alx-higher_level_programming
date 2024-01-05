#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - Checks a linkedlist for palindrome
 * @head: Head linkedlist
 * Return: 1 or 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int *cont;
	int len = 0;
	int i;
	int j = 0;

	if (current->next == NULL || current == NULL)
		return (1);
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	current = *head;
	cont = malloc(2 + sizeof(int) * len / 2);
	for (i = 0; i < len; i++)
	{
		if (i >= len / 2)
		{
			cont[j] = current->n;
			j++;
		}
		current = current->next;
	}
	i = 0;
	current = *head;
	while (i < len / 2)
	{
		if (current->n != cont[j - 1])
		{
			free(cont);
			return (0);
		}
		current = current->next;
		i++;
		j--;
	}
	free(cont);
	return (1);
}
