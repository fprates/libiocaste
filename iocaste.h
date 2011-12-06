/*
 * iocaste.h
 *
 *  Created on: 22/11/2011
 *      Author: francisco.prates
 */

#ifndef IOCASTE_H_
#define IOCASTE_H_

struct icst_object;

struct icst_api {
	int (*get_container_count)(struct icst_object *view);

	char *(*get_view_title)(struct icst_object *view);

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

	void (*set_view_title)(struct icst_object *view, char *title);

	struct icst_object *(*super)(struct icst_object *object);
};

struct icst_view_param {
	struct icst_object *view;
	struct icst_object *program;
	char *icst_path;
	struct icst_api *api;
};

extern int icst_get_container_count(struct icst_object *view);

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

extern void icst_set_view_title(struct icst_object *view, char *title);

extern struct icst_object *icst_super(struct icst_object *object);

#endif /* IOCASTE_H_ */
