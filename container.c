/*
 * container.c
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#include "object.h"
#include "element.h"
#include <stdlib.h>

#define CONTAINER "CONTAINER"

struct s_container {
	struct fac_lista *elements;
};

struct icst_object *icst_ini_container(struct icst_object *super,
		char *name)
{
	struct s_container *container_ = malloc(sizeof(*container_));
	struct icst_object *container = ini_object(name, container_,
			icst_ini_element(super, name));

	set_element_type(container, CONTAINER);

	return container;
}
