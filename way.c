#include "lem-in.h"

void	copy_list_name(t_rn *room, t_rs *rs, int i)
{
	t_rn	*tmp;
	int 	c;

	c = 0;
	tmp = room;
	while (c < i)
	{
		rs[c].n = tmp->n;
		rs[c].fst = tmp->fst;
		rs[c].fen = tmp->fen;
		rs[c].q = 0;
		rs[c].l = (tmp->fst) ? 0 : 2147483647;
		rs[c].fl = 0;
		tmp = tmp->nx;
		c++;
	}
}

void	ft_create(t_rn *room, t_rs **rs, int *i)
{
	t_rn *tmp;

	tmp = room;
	while (tmp)
	{
		(*i)++;
		tmp = tmp->nx;
	}
	if (!(*rs = (t_rs *)malloc(sizeof(t_rs) * (*i))))
		return ;
	copy_list_name(room, *rs, (*i));
}

int 	set_const_l(t_rs *rooms, int i, int min)
{
	int c;
	int f;

	f = 0;
	c = 0;
	while (c < i)
	{
		if (rooms[c].fl && rooms[c].fen)
			return (-1);
		if (!rooms[c].fl && rooms[c].l < min)
		{
			min = rooms[c].l;
			f = c;
		}
		c++;
	}
	rooms[f].fl = 1;
	return (f);
}

void 	find_name(t_lnk *link, t_rs *rooms, int i, int l, int min)
{
	int		c;
	char	*trash;

	c = 0;
	while (c < i)
	{
		if (ft_strequ(link->n2, rooms[c].n))
		{
			trash = link->n1;
			rooms[c].q = ft_strdup(trash);
			ft_strdel(&trash);
			if (rooms[c].l == 2147483647)
				rooms[c].l = 1;
			else
				rooms[c].l += l;
			min = rooms[c].l;
			return ;
		}
		c++;
	}
}

int		find_link(t_rs **rooms, t_lnk *link, int i, int *min)
{
	t_lnk	*tmp;
	int		f;
	int		k;

	tmp = link;
	k = 0;
	if ((f = set_const_l((*rooms), i, *min)) < 0)
		return (0);
	while (tmp)
	{
		if (ft_strequ((*rooms)[f].n, tmp->n1))
		{
			find_name(tmp, (*rooms), i, (*rooms)[f].l, *min);
			k = 1;
		}
		tmp = tmp->nx;
	}
	if (k)
		return (1);
	return (0);
}

int		try_way(t_lb *bs)
{
	ft_create(bs->rnm, &bs->r, &bs->c);
	while (1)
	{
		if (!find_link(&bs->r, bs->link, bs->c, &bs->min))
			return (0);
	}
}
