/*
 * test.c
 *
 *  Created on: 22/11/2011
 *      Author: francisco.prates
 */

#include "test.h"
#include <stdlib.h>
#include <stdio.h>

#define STANDARD_CONTAINER "STANDARD_CONTAINER";
#define FORM "FORM"
#define TEXT "TEXT"
#define TEXT_FIELD "TEXT_FIELD"

struct iocaste_view_data {
	char *page;
};

struct s_element {
	char *name;
	char *type;
	int iscontainable;
	struct iocaste_container *container;
	union u_child {
		struct iocaste_container *container;
		struct s_text *text;
		struct s_text_field *text_field;
	} *child;
};

struct iocaste_container {
	struct s_element *base;
	struct s_element *elements[];
};

struct s_text {
	struct s_element *base;
};

struct s_text_field {
	struct s_element *base;
};

static struct s_element *ini_element(
		struct iocaste_container *scontainer, char *name)
{
	struct s_element *element = malloc(sizeof(*element));

	element->name = name;
	element->container = scontainer;
	element->iscontainable = 0;
	element->name = NULL;

	return element;
}

/**
 * inicializa container
 * scontainer: container pai
 * name: nome do container
 */
static struct iocaste_container *ini_standard_container(
		struct iocaste_container *scontainer, char *name)
{
	struct iocaste_container *container = malloc(sizeof(*container));

//	container->base = ini_element(scontainer, name);
//	container->base->iscontainable = 1;
//	container->base->type = STANDARD_CONTAINER;
//	container->base->child->container = container;

	return container;
}

static struct s_text *ini_text(struct iocaste_container *scontainer, char *name)
{
	struct s_text *text = malloc(sizeof(*text));

	text->base = ini_element(scontainer, name);
	text->base->type = TEXT;
	text->base->child->text = text;

	return text;
}

static struct s_text_field *ini_text_field(struct iocaste_container *scontainer,
		char *name)
{
	struct s_text_field *tfield = malloc(sizeof(*tfield));

	tfield->base = ini_element(scontainer, name);
	tfield->base->type = TEXT_FIELD;
	tfield->base->child->text_field = tfield;

	return tfield;
}

/**
 *
 */
struct iocaste_container *get_container(struct iocaste_view_data *view)
{
	struct iocaste_container *container =
			ini_standard_container(NULL, "test.form");
//
//	ini_text(container, "test.text");
//	ini_text_field(container, "test.tfield");

	return container;
}
