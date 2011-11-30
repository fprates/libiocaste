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

struct icst_std_container *icst_ini_std_container(
		struct icst_container *container, char *name) {
	struct icst_std_container *std_container = malloc(sizeof(*std_container));
	struct s_std_container *std_container_ = malloc(sizeof(*std_container_));

	std_container->this = ini_object(name, std_container_,
			icst_ini_container(container, name));

	return std_container;
}
