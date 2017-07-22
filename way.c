#include "lem-in.h"

int 	is_temp_l(t_rs *rooms, int i, int min)
{
	int c;

	c = 0;
	while (c < i)
	{
		if (!rooms[c].fl && rooms[c].in && rooms[c].l != 2147483647)
		{
			min = rooms[c].l;
			return (1);
		}
		c++;
	}
	return (0);
}

int 	set_const_l(t_rs *rooms, int i, int *min)
{
	int c;
	int f;
	int t;

	t = 0;
	f = 0;
	c = 0;
	if (!is_temp_l(rooms, i, *min))
		return (-1);
	while (c < i)
	{
		if (!rooms[c].fl && rooms[c].in && rooms[c].l <= *min)
		{
			*min = rooms[c].l;
			f = c;
			t++;
		}
		c++;
	}
	if (t)
		rooms[f].fl = 1;
	if (rooms[f].fl && rooms[f].fen)
		return (1);
	if (!t)
		return (-2);
	return (f);
}

void find_name_n2(t_lb *bs, int *l, t_lnk *link)
{
	int	c;

	c = 0;
	while (c < bs->c)
	{
		if (!bs->r[c].fl && bs->r[c].in && ft_strequ(link->n2, bs->r[c].n))
		{
			if (*l == 2147483647)
				*l = 1;
			if (*l + 1 <= bs->r[c].l)
			{
				if (bs->r[c].l == 2147483647)
					bs->r[c].l = 1;
				if (bs->r[c].q)
					ft_strdel(&bs->r[c].q);
				bs->r[c].q = ft_strdup(link->n1);
				bs->r[c].l = (*l + 1 == bs->r[c].l) ? *l + 1 : bs->r[c].l + *l;
				bs->min = bs->r[c].l;
			}
			return ;
		}
		c++;
	}
}

void find_name_n1(t_lb *bs, int *l, t_lnk *link)
{
	int	c;

	c = 0;
	while (c < bs->c)
	{
		if (!bs->r[c].fl && bs->r[c].in && ft_strequ(link->n1, bs->r[c].n))
		{
			if (*l == 2147483647)
				*l = 1;
			if (*l + 1 <= bs->r[c].l)
			{
				if (bs->r[c].l == 2147483647)
					bs->r[c].l = 1;
				if (bs->r[c].q)
					ft_strdel(&bs->r[c].q);
				bs->r[c].q = ft_strdup(link->n2);
				bs->r[c].l = (*l + 1 == bs->r[c].l) ? *l + 1 : bs->r[c].l + *l;
				bs->min = bs->r[c].l;
			}
			return ;
		}
		c++;
	}
}

int find_link(t_lb *bs)
{
	t_lnk	*tmp;
	int		f;

	tmp = bs->link;
	if ((f = set_const_l((bs->r), bs->c, &bs->min)) == -1)
		return (1);
	if (f == -2)
		return (-2);
	while (tmp)
	{
		if ((ft_strequ(bs->r[f].n, tmp->n1) && tmp->in))
			find_name_n2(bs, &(bs->r[f].l), tmp);
		else if (ft_strequ(bs->r[f].n, tmp->n2) && tmp->in)
			find_name_n1(bs, &(bs->r[f].l), tmp);
		tmp = tmp->nx;
	}
	return (2);
}

int		counte_start_end(t_rs *room, t_lnk *links, int k)
{
	int 	s;
	int 	e;
	int		c;
	int		l;
	t_lnk	*tmp;

	s = 0;
	e = 0;
	c = 0;
	l = 0;
	while (--k >= 0)
	{
		(room[k].fst == 1) ? c = k : 0;
		(room[k].fen == 1) ? l = k : 0;
	}
	tmp = links;
	while (tmp)
	{
		if (ft_strequ(room[c].n, tmp->n1) || ft_strequ(room[c].n, tmp->n2))
			s++;
		if (ft_strequ(room[l].n, tmp->n1) || ft_strequ(room[l].n, tmp->n2))
			e++;
		tmp = tmp->nx;
	}
	return ((s < e) ? s : e);
}

int		try_way(t_lb *bs)
{
	int r;

	bs->mysor = -1;
	if ((bs->nway = counte_start_end(bs->r, bs->link, bs->c)) <= 0)
		return (0);
	if (!(bs->go1 = (t_sr *)malloc(sizeof(t_sr) * bs->nway)))
		return (0);
	while (++bs->mysor < bs->nway)
	{
		bs->go1[bs->mysor].ww = NULL;
		while (1)
		{
			r = find_link(bs);
			if (r == 1)
				break;
			else if (r == 0)
				return (0);
			if (r == -2)
				return (0);
		}
		get_way(bs, bs->mysor);
	}
	if (!push_ants(bs))
		return (0);
	return (1);
}
