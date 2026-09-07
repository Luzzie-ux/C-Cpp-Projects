#ifndef TYPING_H
# define TYPING_H

# include <stddef.h>
# include <stdbool.h>

# define fptr(RETURN_VALUE, ptr_name, ...) RETURN_VALUE (*ptr_name)(__VA_ARGS__)
# define mptr(RETURN_VALUE, ptr_name, ...) RETURN_VALUE (*ptr_name)(__VA_ARGS__)

typedef struct Type Type;

struct Type{
	size_t 	size;

	fptr(void, undo, void *self);
	fptr(void, make, void *self, const void *value);
	fptr(void, repl, void *other, const void *self);
	fptr(void*, fresh, const void *value);
	fptr(void, del, void **self);
	
	fptr(void*, assign, const void *value);
	fptr(void, clear, void *self);
	fptr(void, display, const void *self);
	fptr(bool, compare, const void *self, const void *other);
	fptr(void, replace, void *self, const void *value);
};

#endif /*TYPING_H*/
