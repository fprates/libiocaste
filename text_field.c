/*
 * text_field.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "object.h"
#include <stdlib.h>

#define TEXT_FIELD "TEXT_FIELD"

struct icst_text_field {
	struct icst_object *this;
};

struct icst_text_field *icst_ini_text_field(struct icst_container *container,
		char *name)
{
	struct icst_text_field *tfield = malloc(sizeof(*tfield));

	tfield->this = ini_object(name, tfield, icst_ini_element(container, name));

	return tfield;
}

