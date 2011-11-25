/*
 * text.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "object.h"
#include "element.h"
#include <stdlib.h>

#define TEXT "TEXT"

struct icst_text {
	struct icst_object *this;
};

struct icst_text *ini_text(struct icst_container *container, char *name)
{
	struct icst_text *text = malloc(sizeof(*text));

	text->this = ini_object(name, text, ini_element(container, name));

	return text;
}
