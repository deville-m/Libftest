#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	ft_print_result2(int n)
{
	char c;

	if ( n >= 10)
		ft_print_result2(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	iter(unsigned int i, char *c)
{
	ft_print_result2(i);
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int		main(int argc, const char *argv[])
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, &iter);
		write(1, "\n", 1);
		ft_print_result(str);
	}
	return (0);
}
