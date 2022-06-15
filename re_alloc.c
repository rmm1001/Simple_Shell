#include "shell.h"

/**
 * _realloc - allocates memory
 * @ptr: pointer to memory previously allocated
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 *
 * Return: pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *point;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		point = malloc(new_size);
		if (point == NULL)
			return (NULL);
		else
			return (point);
	}
	point = malloc(new_size);
	if (point == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)point + 1) = *((char *)ptr + 1);
	free(ptr);
	return (0);
}
