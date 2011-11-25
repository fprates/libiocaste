/*
 * element.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "object.h"
#include <stdlib.h>
#include <stddef.h>

struct icst_element {
	struct icst_object *this;
	char *type;
	int iscontainable;
	struct icst_container *container;
};

struct icst_element *ini_element(struct icst_container *container, char *name)
{
	struct icst_element *element = malloc(sizeof(*element));

	element->this = ini_object(name, element, NULL);
	element->container = container;
	element->iscontainable = 0;

	return element;
}

void def_element_type(struct icst_element *element, char *type)
{
	element->type = type;
}
