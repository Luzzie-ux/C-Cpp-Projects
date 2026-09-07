#ifndef GLOBAL_SCOPE_H
# define GLOBAL_SCOPE_H

# include <stdlib.h>
# include "c_string.h"
# include "typing.h"

# define Undo(self) _Generic((self), \
	string *: undo_string \
	)(self)
# define Make(self, value) _Generic((self), \
	string *: make_string \
	const string *: make_string \
	)(self, value)
# define Del(self) _Generic((self), \
	string **: del_string \
	)(self)
# define Fresh(value) _Generic((value), \
	char *: fresh_string \
	const char *: fresh_string \
	)(value)
# define Repl(other, self) _Generic((self), \
	string *: repl_string \
	const string *:repl_string \
	)(other, self)

typedef struct Object{
	Type *type;
	void *data;
} object;

object *Object(Type *type, void *data);
object _Object(object *self);

typedef struct scope{
	Object *String;
	Object *Int;
	Object *Float;
	Object *Bool;
	Object *File;
	Object *Stream;
	Object *Array;
	Object *Stack;
	Object *Queue;
	Object *Deque;
} scope;

void init_scope(scope *global);

typedef object var;

#endif /* GLOBAL_SCOPE_H */

