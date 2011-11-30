/*
 * view_data.c
 *
 *  Created on: 25/11/2011
 *      Author: francisco.prates
 */

#include "iocaste.h"
#include "object.h"
#include "program.h"
#include <stdlib.h>
#include <stddef.h>
#include <faclib.h>

struct icst_view_data {
	struct icst_object *this;
};

struct icst_view_data *icst_ini_view(struct icst_program *program,
		char *view_name)
{
	struct icst_view_data *view;
	struct icst_view_data *(*init_view)(struct icst_view_data *,
			struct icst_program *, void *);
	void *lib = fac_ld_lib(ret_iocaste_path(program));

	if (lib == NULL)
		return NULL;

	view = malloc(sizeof(*view));
	view->this = ini_object(view_name, view, NULL);

	init_view = fac_ret_proc_lib(ret_program_lib(program), "init_view");
	init_view(view, program, lib);

	return view;
}
