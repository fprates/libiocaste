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

struct icst_text *icst_ini_text(struct icst_container *container, char *name)
{
	struct icst_text *text = malloc(sizeof(*text));
	struct s_text *text_ = malloc(sizeof(*text_));

	text->this = ini_object(name, text_, icst_ini_element(container, name));

	return text;
}
