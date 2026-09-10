#include "stamp.h"
#include "stype.h"
#include <string.h>

t_stamp g_scope;

void stamp(void)
{
	g_scope.string = init_string_vtable();
}

static bool if_null(t_string **self, const char *data)
{
	if (data != NULL)
		return false;
	(*self)->data = strdup("");
	if (!(*self)->data)
		return true;
	(*self)->start = &(*self)->data;
	(*self)->itr = &(*self)->data;
	(*self)->end = &(*self)->data;
	(*self)->length = 0;
	(*self)->size = 0;
	return false;
}

void string(t_string *self, const char *data)
{
	int i;

	i = 0;
	if (if_null(&self, data))
		return ;
	while(data[i])
		i++;
	self->length = i;
	self->data = strdup(data);
	self->start = &self->data;
	self->itr = &self->data;
	self->end = &self->data[i];
	self->size = i + 1;
}
