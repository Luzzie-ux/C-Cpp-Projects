#include "c_string.h"

void del_string(string **self)
{
	if (!self || !*self)
		return;
	if (!(*self)->value)
		return ((*self)->len = 0, free(*self));
	free((*self)->value);
	(*self)->value = NULL;
	(*self)->len = 0;
	return (free(*self));
}

static void assign_methods(string **self)
{
	(*self)->clear = clear;
	(*self)->length = length;
	(*self)->display = display;
	(*self)->resize = resize;
	(*self)->append = append;
	(*self)->replace = replace;
	(*self)->compare = compare;
}

string *fresh_string(const char *value)
{
	if (!value)
		return (NULL);
	string *obj = (string *)malloc(sizeof(string));
	if (!obj)
		return (NULL);
	obj->value = ft_strdup(value);
	if (!obj->value)
		return (del_string(&obj), NULL);
	assign_methods(&obj);
	obj->len = obj->length(obj);
	return (obj);
}

string *repl_string(string *other, const string *self)
{
	if (!other || !self)
		return (NULL);
	if (other == self)
		return (other);
	char *tmp = ft_strdup(self->value);
	if (!tmp)
		return (NULL);
	if (other->value)
		free(other->value);
	other->value = tmp;
	other->len = self->len;
	return (other);
}

int clear(string *self)
{
	if (!self)
		return (1);
	if (!self->value)
		return (0);
	memset(self->value, ' ', self->length(self));
	self->value[self->len] = 0;
	return (0);
}

int length(const string *self)
{
	if (!self || !self->value)
		return (0);
	return ft_strlen(self->value);
}

int display(const string *self)
{
	if (!self)
		return (1);
	return printf("%s", self->value);
}

int resize(string *self, const int n)
{
	char *tmp;
	if (!self)
		return (1);
	tmp = realloc(self->value, (n + 1) * sizeof(char));
	if (!tmp)
		return (del_string(&self), 1);
	self->value = tmp;
	return (0);
}

int append(string *self, const char *value)
{
	if (!self || !value)
		return (1);
	int size = ft_strlen(value);
	int total = self->len + size;
	if (self->resize(self, total))
		return (1);
	int i = -1;
	while (++i < size)
		self->value[i + self->len] = value[i];
	self->value[total] = 0;
	self->len = total;
	return (0);
}

int replace(string *self, const char *value)
{
	if (!self || !value)
		return (1);
	if (self->value)
		free(self->value);
	self->value = ft_strdup(value);
	if (!self->value)
		return (del_string(&self), 1);
	return (0);
}

int compare(const string *self, const string *other)
{
	if (!self || !other)
		return (-1);
	if (!self->value || !other->value)
		return (-1);
	int i = 0;
	while (self->value[i] && other->value[i])
	{
		if (self->value[i] != other->value[i])
			return (self->value[i] - other->value[i]);
		i++;
	}
	return (0);
}
