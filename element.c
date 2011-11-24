/*
 * element.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "element.h"
#include <stdlib.h>

struct icst_element {
	char *name;
	char *type;
	int iscontainable;
	struct icst_container *container;
	void *ext;
};

struct icst_container {
	struct icst_element *super;
	struct icst_element *elements[];
};

struct icst_element *ini_element(struct icst_container *container, char *name)
{
	struct icst_element *element = malloc(sizeof(*element));

	element->name = name;
	element->container = container;
	element->iscontainable = 0;
	element->name = NULL;
	element->ext = NULL;

	return element;
}

void def_element_ext(struct icst_element *element, void *ext)
{
	element->ext = ext;
}

void def_element_type(struct icst_element *element, char *type)
{
	element->type = type;
}

struct icst_container *ini_container(struct icst_container *super, char *name)
{
	struct icst_container *container_ = malloc(sizeof(*container_));

	container_->super = ini_element(super, name);
	def_element_ext(container_->super, container_);

	return container_;
}
