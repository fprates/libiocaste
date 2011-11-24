/*
 * iocaste.h
 *
 *  Created on: 22/11/2011
 *      Author: francisco.prates
 */

#ifndef IOCASTE_H_
#define IOCASTE_H_

struct icst_element;
struct icst_container;
struct icst_text;
struct icst_text_field;

extern struct icst_container *ini_container(struct icst_container *super,
		char *name);

extern struct icst_element *ini_element(struct icst_container *container,
		char *name);

extern struct icst_text *ini_text(struct icst_container *container, char *name);

extern struct icst_text_field *ini_text_field(struct icst_container *container,
		char *name);

//struct icst_view_data;
//struct icst_container;
//
//extern struct s_text_field *ini_text_field(struct icst_container *scontainer,
//		char *name);
//
//extern element_extension(struct icst_container *container, void *extension);

#endif /* IOCASTE_H_ */
