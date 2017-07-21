#include "lem-in.h"

/*void	print_links(t_lb *bs)
{
	t_lnk *tmp;

	tmp = bs->link;
	while (tmp)
	{
		ft_printf(YEL"n1 = %s, n2 = %s\n"RC, tmp->n1, tmp->n2);
		tmp = tmp->nx;
	}
}*/

int check_dubl_link(t_lnk *link, char *n1, char *n2)
{
	t_lnk *tmp;

	if (!link)
		return (0);
	tmp = link;
	while (tmp)
	{
		if ((ft_strequ(tmp->n1, n1) && ft_strequ(tmp->n2, n2)) ||
			(ft_strequ(tmp->n1, n2) && ft_strequ(tmp->n2, n1)))
			return (1);
		tmp = tmp->nx;
	}
	return (0);
}

int		fill_links(char *s, char *str, int i, t_lb *bs)
{
	t_lnk *tmp;

	if (check_dubl_link(bs->link, str, s + i + 1))
		return (1);
	if (!(tmp = (t_lnk *)malloc(sizeof(t_lnk))))
		return (0);
	tmp->n1 = ft_strdup(str);
	tmp->n2 = ft_strdup(s + i + 1);
	tmp->in = 1;
	tmp->nx = bs->link;
	bs->link = tmp;
	ft_strdel(&s);
	ft_strdel(&str);
	//print_links(bs);
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
	ft_printf("%s\n", s);
	return (fill_links(s, str, i, bs));
}
