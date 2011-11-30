/*
 * text.c
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "object.h"
#include <stdlib.h>

#define TEXT "TEXT"

struct s_text {

};

struct icst_object *icst_ini_text(struct icst_object *container, char *name)
{
	struct s_text *text_ = malloc(sizeof(*text_));
	struct icst_object *text = ini_object(name, text_, icst_ini_element(container, name));

	return text;
}
