#ifndef C_STRING_H
# define C_STRING_H

# define fptr(RETURN_VALUE, ptr_name, ...) RETURN_VALUE (*ptr_name)(__VA_ARGS__)

# include "funcs/funcs.h"

typedef struct string
{
	size_t len;
	char *value;
	fptr(int, clear, struct string *self);
	fptr(int, length, const struct string *self);
	fptr(int, display, const struct string *self);
	fptr(int, resize, struct string *self, const int n);
	fptr(int, append, struct string *self, const char *vale);
	fptr(int, replace, struct string *self, const char *value);
	fptr(int, compare, const struct string *self, const struct string *other);
} string;

// Methods that mutates the String Class and its Attributes
// Clears the value of the String Object
// by placing '0', keeping its memory size intact
int 	clear(string *self);
// Resize String Object value
int 	resize(string *self, const int n);
// Append new value to String Object value
int 	append(string *self, const char *value);
// Replace the value of String Object
int 	replace(string *self, const char *value);

// Methods that dont mutate the String Class and its Attributes
// Returns the length of the String Object value
int 	length(const string *self);
// Display the String Object value
int 	display(const string *self);
// Compare String Objects
int 	compare(const string *self, const string *other);

// Class Handlers

// String Class Stack Destructor
void 	undo_string(string *self);
// String Class Stack Constructor
void 	make_string(string *self, void *ptr);
// String Class Copy Constructor
string 	*repl_string(string *other, const string *self);
// String Class Heap Constructor
string 	*fresh_string(const char *value);
// String Class Heap Destructor
void 	del_string(string **self);

#endif /* C_STRING_H*/
