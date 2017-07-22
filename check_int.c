#include "lem-in.h"

long	ft_longatoi(const char *str)
{
	int		i;
	int		m;
	long	res;

	i = 0;
	m = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		   str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res = res + m * (str[i] - 48);
		i++;
	}
	return (res);
}

int 	check_int(char *s, int f)
{
	long n;


	n = ft_longatoi(s);
	if (f == 2 && (n <= (-2147483649) || n >= 2147483648))
		return (0);
	else if (f == 1 && (n <= 0 || n >= 2147483648))
		return (0);
	return (1);
}

int		check_pos(char *s, int a)
{
	int		i;

	i = 0;
	if (a == 0)
		return (1);
	(s[i] == '-') ? i++ : 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if ((s[i] != ' ' && a == 2) || (s[i] != '\0' && a == 1))
		return (0);
	if (i > 12 || !check_int(s, 2))
		return (0);
	return (check_pos(s + i + 1, --a));
}
