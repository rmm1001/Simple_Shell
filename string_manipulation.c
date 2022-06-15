#include "shell.h"

/**
 * _strlen - gets the length of a string
 * @str: pointer to the input string
 *
 * Return: lenght of string
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strdup - duplicates string
 * @str: string to duplicate
 *
 * Return: pointer to the diplicated string
 */

char *_strdup(char *str)
{
	char *dup;
	int i = 0, len;

	len = _strlen(str) + 1;
	if (str == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * len);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

/**
 * _strcat - concatenates two strings
 * @src: string to append
 * @dest: location to append string at
 *
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, len = 0, k = 0;

	while (dest[i] != '\0')
	{
		i++;
		len++;
	}
	while (src[j] != '\0')
	{
		j++;
		len++;
	}
	dest = _realloc(dest, i, sizeof(char) * len + 1);
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: 1st string input
 * @s2: 2nd string input
 *
 * Return: number of spaces with no matching character
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	if (s2[i])
		return (s1[i] - s2[i]);
	else
		return (0);
}

/**
 * _strcpy - copies a string
 * @src: string to be copied
 * @dest: destination to paste copied string
 *
 * Return: pointer to the destination of copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];
	return (dest);
}
