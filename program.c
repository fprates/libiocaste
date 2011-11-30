/*
 * program.c
 *
 *  Created on: 29/11/2011
 *      Author: francisco.prates
 */

#include "program.h"
#include "object.h"
#include <stdlib.h>
#include <stddef.h>
#include <faclib.h>

struct icst_program {
	struct icst_object *this;
	char *name;
	char *prog_path;
	void *prog_lib;
	char *icst_path;
};

struct icst_program *icst_ini_program(char *name, char *prog_path,
		char *icst_path)
{
	struct icst_program *program;
	void *lib = fac_ld_lib(prog_path);

	if (lib == NULL)
		return NULL;

	program = malloc(sizeof(*program));
	program->this = ini_object(name, program, NULL);
	program->name = name;
	program->prog_path = prog_path;
	program->prog_lib = lib;
	program->icst_path = icst_path;

	return program;
}

char *ret_iocaste_path(struct icst_program *program)
{
	return program->icst_path;
}

void *ret_program_lib(struct icst_program *program)
{
	return program->prog_lib;
}
