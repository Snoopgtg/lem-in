#include "lem-in.h"

/*
** startend flag for start 1
** 					end 2
**					default 0
** імя має бути чаром;
*/
int		fill_name(char *s, int fse)
{
	s++;
	if (!check_pos(s, 2))
		return (0);
	if (fse == 1)
		st = 1;
	else if (fse == 2)
		end = 1;
	else
		all = 1;
	return (1);
}

int 	ft_hesh(char *s, int *fse)
{
	if (ft_strcmp("##start", s) || ft_strcmp("##end", s))
	{
		if (ft_strcmp("##start", s))
			*fse = 1;
		else
			*fse = 2;
		ft_printf("%s\n", s);
		return (fill_name(s, *fse));
	}
	else if (s[0] == '#' && s[1] != '#')
	{
		ft_printf("%s", s);
		return (1);
	}
	else
	{
		ft_printf("%s\n", s);
		get_next_line(0, &s);
		ft_printf("%s\n", s);
		free(s);
	}
	return (1);

}

int ft_numofant(char *s, int *na, int *fna)
{
	int		i;

	if (*fna)
		return (0);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	if (i > 11 || !check_int(s, 1))
		return (0);
	*na = ft_atoi(s);
	*fna = 1;
	ft_printf("%d\n", *na);
	return (1);
}

int ft_start(char *s, t_lb *bs)
{
	int i;

	i = 0;
	if (*s == '-' || *s == ' ')
		return (0);
	while ((s[i] != ' ' && s[i] != '-') && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_numofant(s, &bs->na, &bs->fna));
	else if (s[i] == ' ')
		return (fill_name(s + i, 0));
	else if (s[i] == '-')
		return (0/*fill_link(s)*/);
	return (0);

}

int		main(void)
{
	char	*line;
	int		r;
	t_lb	bs;
	int 	fd;

	fd = 0;
	bs.rnm = NULL;
	fill_zero(&bs);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '#')
			r = ft_hesh(line, &bs.fse);
		else
			r = ft_start(line, &bs);
		if (r == 0/* && check_start_end_ant(bs)*/)
		{
			write(1, "ERROR\n", 6);
			return (1);
		}
	}
	ft_printf("All CORRECT");
	return 0;
}
// матрица смежности
//18446744073709551619  1 -2147483648 18446744073709551619