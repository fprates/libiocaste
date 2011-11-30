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

struct s_program {
	char *name;
	char *prog_path;
	void *prog_lib;
	char *icst_path;
};

struct icst_object *icst_ini_program(char *name, char *prog_path,
		char *icst_path)
{
	struct icst_object *program;
	struct s_program *program_;
	void *lib = fac_ld_lib(prog_path);

	if (lib == NULL)
		return NULL;

	program_ = malloc(sizeof(*program_));
	program = ini_object(name, program_, NULL);

	program_->name = name;
	program_->prog_path = prog_path;
	program_->prog_lib = lib;
	program_->icst_path = icst_path;

	return program;
}

char *ret_iocaste_path(struct icst_object *program)
{
	struct s_program *program_ = ret_extension(program);

	return program_->icst_path;
}

void *ret_program_lib(struct icst_object *program)
{
	struct s_program *program_ = ret_extension(program);

	return program_->prog_lib;
}
