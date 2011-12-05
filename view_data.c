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

struct icst_object *icst_ini_view(struct icst_object *program,
		char *view_name)
{
	struct icst_object *view;
	struct icst_object *(*init_view)(struct icst_object *, struct icst_object *,
			void *);
	struct s_view_data *view_ = malloc(sizeof(*view_));

	view = ini_object(view_name, view_, NULL);
	view_->containers = fac_ini_lista();

	init_view = fac_ret_proc_lib(ret_program_lib(program), "init_view");

	init_view(view, program, ret_iocaste_path(program));

	return view;
}

void icst_view_add(struct icst_object *view, struct icst_object *container)
{
	struct s_view_data *view_ = ret_extension(view);

	fac_inc_item(view_->containers, container);
}

int icst_get_container_count(struct icst_object *view)
{
	struct s_view_data *view_ = ret_extension(view);

	return fac_qt_itens(view_->containers);
}
