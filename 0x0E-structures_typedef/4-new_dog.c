#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @s: string to be valued
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
	{
		i++;
	}

	return (i);
}


/**
 * _strcopy - Copies a string pointed to by src, including the
 * @dest:pointer to the buffer in which we copy the string.
 * @s: The source string.
 *
 * Return: The pointer to dest.
 */

char *_strcopy(char *dest, char *s)
{
	int j = 0;

	for (j = 0; s[j]; j++)
		dest[j] = s[j];

	dest[j] = '\0';

	return (dest);
}

/**
 * new_dog - Creates a new dog.
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: name of owner of the dog.
 *
 * Return: new struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *max;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);

	max = malloc(sizeof(dog_t));
	if (max == NULL)
		return (NULL);

	max->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (max->name == NULL)
	{
		free(max);
		return (NULL);
	}

	max->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (max->owner == NULL)
	{
		free(max->name);
		free(max);
		return (NULL);
	}

	max->name = _strcopy(max->name, name);
	max->age = age;
	max->owner = _strcopy(max->owner, owner);

	return (max);
}
