#include "stamp.h"

int main(void)
{
	t_string str;
	string(&str, "My name is Rodrigo");
	g_scope.string->display(&str);
	return (0);
}
