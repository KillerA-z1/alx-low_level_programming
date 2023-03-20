#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - freeing the memory.
 * @d: what we de-allocate from the memory.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->owner);
	free(d->name);
	free(d);
}
