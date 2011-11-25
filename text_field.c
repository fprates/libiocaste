/*
 * text_field.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "element.h"
#include "text_field.h"
#include <stdlib.h>

#define TEXT_FIELD "TEXT_FIELD"

struct icst_text_field {
	struct icst_element *super;
};

struct icst_text_field *ini_text_field(struct icst_container *container,
		char *name)
{
	struct icst_text_field *tfield = malloc(sizeof(*tfield));

	tfield->super = ini_element(container, name);
	def_element_type(tfield->super, TEXT_FIELD);
	def_element_ext(tfield->super, tfield);

	return tfield;
}

