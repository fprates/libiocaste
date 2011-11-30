/*
 * object.c
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "object.h"
#include <stdlib.h>

struct icst_object {
	char *name;
	void *this;
	struct icst_object *extension;
};

struct icst_object *ini_object(char *name, void *this,
		struct icst_object *extension)
{
	struct icst_object *object = malloc(sizeof(*object));

	object->name = name;
	object->this = this;
	object->extension = extension;

	return object;
}

struct icst_object *icst_super(struct icst_object *object)
{
	return object->extension;
}

void *ret_extension(struct icst_object *object)
{
	return object->this;
}
