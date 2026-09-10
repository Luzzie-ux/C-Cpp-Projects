#ifndef STYPE_H
# define STYPE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct {
	char *data;
	size_t length;
	size_t size;
	void *start;
	void *itr;
	void *end;
} t_string;

typedef struct {
	void(*display)(const t_string *self);
	bool(*empty)(const t_string *self);
} t_stable;

extern t_stable svt;

#endif /* STYPE_H */
