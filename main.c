/*
 * main.c
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include "element.h"
#include "text.h"
#include "text_field.h"

#include <stdlib.h>

struct icst_api *icst_ini(void)
{
	struct icst_api *api = malloc(sizeof(*api));

	api->ini_container = ini_container;
	api->ini_element = ini_element;
	api->ini_text = ini_text;
	api->ini_text_field = ini_text_field;

	return api;
}
