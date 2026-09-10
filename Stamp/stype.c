#include "stype.h"
#include <stdio.h>

t_stable svt;

void display(const t_string *self);
bool empty(const t_string *self);

void display(const t_string *self)
{
	printf("%s", self->data);
}

bool empty(const t_string *self)
{
	if (!self->data)
		return (true);
	return (false);
}

t_stable *init_string_vtable(void)
{
	svt.display = &display;
	svt.empty = &empty;
	return (&svt);
}
