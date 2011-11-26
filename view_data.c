/*
 * view_data.c
 *
 *  Created on: 25/11/2011
 *      Author: francisco.prates
 */

#include "iocaste.h"
#include "object.h"
#include <stdlib.h>
#include <stddef.h>

struct icst_view_data {
	struct icst_object *this;
};

struct icst_view_data *icst_ini_view(char *view_name)
{
	struct icst_view_data *view = malloc(sizeof(*view));
	view->this = ini_object(view_name, view, NULL);

	return view;
}
