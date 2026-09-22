#pragma once
#ifndef STYPE_H
# define STYPE_H

#include <stdlib.h>

typedef struct s_string string;
typedef struct s_vstr vstr;
typedef void * iter;

typedef struct s_string{
	iter	start;
	iter	it;
	char	*data;
	size_t	len;
	size_t	size;
	vstr	*v;
	iter	end;
}			string;

typedef struct s_vstr{
	/*...*/
}			vstr;

#endif
