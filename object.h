/*
 * object.h
 *
 *  Created on: 25/11/2011
 *      Author: fprates
 */

#ifndef OBJECT_H_
#define OBJECT_H_

extern struct icst_object *ini_object(char *name, void *this,
		struct icst_object *extension);

extern void *ret_extension(struct icst_object *object);

#endif /* OBJECT_H_ */
