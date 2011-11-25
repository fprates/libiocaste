/*
 * main.c
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#include "iocaste.h"
#include <stdlib.h>

struct icst_api *icst_ini(void)
{
	struct icst_api *api = malloc(sizeof(*api));

	api->ini_container = icst_ini_container;
	api->ini_element = icst_ini_element;
	api->ini_text = icst_ini_text;
	api->ini_text_field = icst_ini_text_field;

	return api;
}
