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

struct s_text_field {

};

struct icst_text_field *icst_ini_text_field(struct icst_container *container,
		char *name)
{
	struct icst_text_field *tfield = malloc(sizeof(*tfield));
	struct s_text_field *tfield_ = malloc(sizeof(*tfield_));

	tfield->this = ini_object(name, tfield_, icst_ini_element(container, name));

	return tfield;
}

