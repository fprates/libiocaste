/*
 * text_field.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "object.h"
#include "element.h"
#include <stdlib.h>

#define TEXT_FIELD "TEXT_FIELD"

struct s_text_field {

};

struct icst_object *icst_ini_text_field(struct icst_object *container,
		char *name)
{
	struct s_text_field *tfield_ = malloc(sizeof(*tfield_));
	struct icst_object *tfield = ini_object(name, tfield_,
			icst_ini_element(container, name));

	set_element_type(tfield, TEXT_FIELD);

	return tfield;
}

