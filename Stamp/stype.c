# include <string.h>
# include <stype.h>

void	string$(string *self, const char *format)
{
	self.data = ft_strdup(format);
}

string	*new$(const char *format)
{
	string *obj = malloc(sizeof(string));
	return obj;
}

void	del$(string **self)
{
	free(*self);
}
