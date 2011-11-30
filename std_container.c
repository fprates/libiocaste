/*
 * std_container.c
 *
 *  Created on: 24/11/2011
 *      Author: francisco.prates
 */

#include "iocaste.h"
#include "object.h"
#include <stdlib.h>

#define STD_CONTAINER "STANDARD_CONTAINER"

struct s_std_container {

};

struct icst_object *icst_ini_std_container(struct icst_object *container,
		char *name) {
	struct s_std_container *std_container_ = malloc(sizeof(*std_container_));
	struct icst_object *std_container = ini_object(name, std_container_,
			icst_ini_container(container, name));

	return std_container;
}
