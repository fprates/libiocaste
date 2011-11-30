/*
 * container.c
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "object.h"
#include <stdlib.h>

struct s_container {
	struct fac_lista *elements;
};

struct icst_container *icst_ini_container(struct icst_container *super,
		char *name)
{
	struct icst_container *container = malloc(sizeof(*container));
	struct s_container *container_ = malloc(sizeof(*container_));

	container->this = ini_object(name, container_,
			icst_ini_element(super, name)->this);

	return container;
}
