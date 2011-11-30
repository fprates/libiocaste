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

struct s_view_data {
	struct fac_lista *containers;
};

struct icst_view_data *icst_ini_view(struct icst_program *program,
		char *view_name)
{
	struct icst_view_data *view;
	struct s_view_data *view_;
	struct icst_view_data *(*init_view)(struct icst_view_data *,
			struct icst_program *, void *);
	void *lib = fac_ld_lib(ret_iocaste_path(program));

	if (lib == NULL)
		return NULL;

	view = malloc(sizeof(*view));
	view_ = malloc(sizeof(*view_));
	view->this = ini_object(view_name, view_, NULL);
	view_->containers = fac_ini_lista();

	init_view = fac_ret_proc_lib(ret_program_lib(program), "init_view");
	init_view(view, program, lib);

	return view;
}

void icst_view_add(struct icst_view_data *view,
		struct icst_container *container)
{
	struct s_view_data *view_ = ret_extension(view->this);

	fac_inc_item(view_->containers, container);
}
