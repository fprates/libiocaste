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
	char *title;
	struct fac_lista *containers;
};

struct icst_object *icst_ini_view(struct icst_object *program,
		char *view_name)
{
	struct icst_object *(*init_view)(struct icst_view_param);
	struct icst_view_param view_param;
	struct s_view_data *view_ = malloc(sizeof(*view_));

	view_param.program = program;
	view_param.view = ini_object(view_name, view_, NULL);
	view_param.icst_path = ret_iocaste_path(program);
	view_param.api = icst_ini();

	view_->title = view_name;
	view_->containers = fac_ini_lista();
	init_view = fac_ret_proc_lib(ret_program_lib(program), "init_view");
	init_view(view_param);

	return view_param.view;
}

void icst_view_add(struct icst_object *view, struct icst_object *container)
{
	struct s_view_data *view_ = ret_extension(view);

	fac_inc_item(view_->containers, container);
}

struct fac_iterador *icst_get_container_iterator(
		struct icst_object *view)
{
	struct s_view_data *view_ = ret_extension(view);

	return fac_ini_iterador(view_->containers);
}

char *icst_get_view_title(struct icst_object *view)
{
	struct s_view_data *view_ = ret_extension(view);

	return view_->title;
}

void icst_set_view_title(struct icst_object *view, char *title)
{
	struct s_view_data *view_ = ret_extension(view);

	view_->title = title;

}

int icst_has_container(struct fac_iterador *itc)
{
	return fac_existe_prox(itc);
}

struct icst_object *icst_get_container(struct fac_iterador *itc)
{
	return fac_proximo(itc);
}
