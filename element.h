/*
 * element.h
 *
 *  Created on: 24/11/2011
 *      Author: fprates
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "iocaste.h"

extern struct icst_container *ini_container(struct icst_container *super,
		char *name);

extern struct icst_element *ini_element(struct icst_container *container,
		char *name);

extern void def_element_ext(struct icst_element *element, void *ext);

extern void def_element_type(struct icst_element *element, char *type);

#endif /* ELEMENT_H_ */
