#ifndef STAMP_H
# define STAMP_H

# include "stype.h"
# include "vektor.h"

t_stable *init_string_vtable(void);

typedef struct {
	t_stable *string;
}t_stamp;

extern t_stamp g_scope;

void string(t_string *self, const char *data);

void stamp(void);

void __attribute__((constructor)) stamp();

#endif /* STAMP_H  */
