/*
 * object.c
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#include "object.h"

struct icst_object {
	char *name;
	void *this;
	void *extension;
};

struct icst_object *ini_object(char *name, void *this, void *extension)
{
	struct icst_object *object = malloc(sizeof(*object));

	object->name = name;
	object->this = this;
	object->extension = extension;

	return object;
}
