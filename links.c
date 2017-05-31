#include "lem-in.h"

void	print_links(t_lb *bs)
{
	t_lnk *tmp;

	tmp = bs->link;
	while (tmp)
	{
		ft_printf(YEL"n1 = %s, n2 = %s\n"RC, tmp->n1, tmp->n2);
		tmp = tmp->nx;
	}
}

int		fill_links(char *s, char *str, int i, t_lb *bs)
{
	t_lnk *tmp;

	if (!(tmp = (t_lnk *)malloc(sizeof(t_lnk))))
		return (0);
	tmp->n1 = ft_strdup(str);
	tmp->n2 = ft_strdup(s + i + 1);
	tmp->nx = bs->link;
	bs->link = tmp;
	print_links(bs);
	return (1);
}

int		check_links(char *s, t_lb *bs)
{
	t_rn 	*tmp;
	char 	*str;
	int		i;
	int		f;
	int		t;

	t = 0;
	f = 0;
	i = 0;
	if (!bs->rnm)
		return (0);
	while (s[i] != '-')
		i++;
	str = ft_strsub(s, 0, (size_t)i);
	tmp = bs->rnm;
	while (tmp)
	{
		if (ft_strequ(str, tmp->n))
			f = 1;
		if (ft_strequ(s + i + 1, tmp->n))
			t = 1;
		tmp = tmp->nx;
	}
	if (!f || !t)
	{
		ft_strdel(&str);
		return (0);
	}
	return (fill_links(s, str, i, bs));
}

// перевірити на одинакові імена в лінкі