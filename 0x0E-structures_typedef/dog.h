#ifndef DOG_H
#define DOG_H

/*
 * File: dog.h
 * Desc: Header file that defines a new type struct dog.
 */

/**
 * struct dog - A new type describing a dog.
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: owner of the dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif
