/*
 * iocaste.h
 *
 *  Created on: 22/11/2011
 *      Author: francisco.prates
 */

#ifndef IOCASTE_H_
#define IOCASTE_H_

#include <faclib.h>

struct icst_object;

struct icst_api {
    struct icst_object *(*get_container)(struct fac_iterador *itc);

    struct fac_iterador *(*get_container_iterator)(struct icst_object *view);

	char *(*get_element_type)(struct icst_object *element);

	char *(*get_object_name)(struct icst_object *element);

	char *(*get_view_title)(struct icst_object *view);

	int (*has_container)(struct fac_iterador *itc);

	struct icst_object *(*ini_container)(struct icst_object *container,
			char *name);

	struct icst_object *(*ini_element)(struct icst_object *container,
			char *name);

	struct icst_object *(*ini_text)(struct icst_object *container, char *name);

	struct icst_object *(*ini_text_field)(struct icst_object *container,
			char *name);

	struct icst_object *(*ini_std_container)(struct icst_object *container,
			char *name);

	struct icst_object *(*ini_program)(char *name, char *prog_path,
			char *icst_path);

	struct icst_object *(*ini_view)(struct icst_object *program,
			char *view_name);

	void (*view_add)(struct icst_object *view, struct icst_object *container);

	void (*set_element_type)(struct icst_object *element, char *type);

	void (*set_view_title)(struct icst_object *view, char *title);

	struct icst_object *(*super)(struct icst_object *object);
};

struct icst_view_param {
	struct icst_object *view;
	struct icst_object *program;
	char *icst_path;
	struct icst_api *api;
};

extern struct icst_object *icst_get_container(struct fac_iterador *itc);

extern struct fac_iterador *icst_get_container_iterator(
		struct icst_object *view);

extern char *icst_get_element_type(struct icst_object *element);

extern char *icst_get_object_name(struct icst_object *object);

extern int icst_has_container(struct fac_iterador *itc);

extern struct icst_object *icst_ini_container(struct icst_object *container,
		char *name);

extern struct icst_object *icst_ini_element(struct icst_object *container,
		char *name);

extern struct icst_api *icst_ini(void);

extern struct icst_object *icst_ini_std_container(struct icst_object *container,
		char *name);

extern struct icst_object *icst_ini_text(struct icst_object *container,
		char *name);

extern struct icst_object *icst_ini_text_field(struct icst_object *container,
		char *name);

extern struct icst_object *icst_ini_program(char *name, char *prog_path,
		char *icst_path);

extern struct icst_object *icst_ini_view(struct icst_object *program,
		char *view_name);

extern void icst_view_add(struct icst_object *view,
		struct icst_object *container);

extern char *icst_get_view_title(struct icst_object *view);

extern void icst_set_element_type(struct icst_object *element, char *type);

extern void icst_set_view_title(struct icst_object *view, char *title);

extern struct icst_object *icst_super(struct icst_object *object);

#endif /* IOCASTE_H_ */
