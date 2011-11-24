/*
 * text.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "element.h"
#include <stdlib.h>

#define TEXT "TEXT"

struct icst_text {
	struct icst_element *super;
};

struct icst_text *ini_text(struct icst_container *container, char *name)
{
	struct icst_text *text = malloc(sizeof(*text));

	text->super = ini_element(container, name);
	def_element_type(text->super, TEXT);
	def_element_ext(text->super, text);

	return text;
}
