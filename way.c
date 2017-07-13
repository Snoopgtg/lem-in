#include "lem-in.h"

int 	is_temp_l(t_rs *rooms, int i, int *min)
{
	int c;

	c = 0;
	while (c < i)
	{
		if (!rooms[c].fl)
		{
			*min = rooms[c].l;
			return (1);
		}
		c++;
	}
	return (0);
}

int 	set_const_l(t_rs *rooms, int i, int **min)
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
		if (!rooms[c].fl && rooms[c].l <= **min)
		{
			**min = rooms[c].l;
			f = c;
			t++;
		}
		c++;
	}
	if (t)
		rooms[f].fl = 1;
	//if (rooms[f].fl && rooms[f].fen)
	//	return (-1);
	if (!t)
		return (-2);
	return (f);
}

void 	find_name_n2(t_lnk *link, t_rs *rooms, int i, int *l, int **min)
{
	int		c;

	c = 0;
	while (c < i)
	{
		if (!rooms[c].fl && ft_strequ(link->n2, rooms[c].n))
		{
			if (*l == 2147483647)
				*l = 1;
			if (*l + 1 <= rooms[c].l)
			{
				if (rooms[c].l == 2147483647)
					rooms[c].l = 1;
				rooms[c].q = ft_strdup(link->n1);
				rooms[c].l += *l;
				**min = rooms[c].l;
				//link->in = 0;
			}
			return ;
		}
		c++;
	}
}

void 	find_name_n1(t_lnk *link, t_rs *rooms, int i, int *l, int **min)
{
	int		c;

	c = 0;
	while (c < i)
	{
		if (!rooms[c].fl && ft_strequ(link->n1, rooms[c].n))
		{
			if (*l == 2147483647)
				*l = 1;
			if (*l + 1 <= rooms[c].l)
			{
				if (rooms[c].l == 2147483647)
					rooms[c].l = 1;
				rooms[c].q = ft_strdup(link->n2);
				rooms[c].l += *l;
				**min = rooms[c].l;
				link->in = 0;
			}
			return ;
		}
		c++;
	}
}

int		find_link(t_rs **rooms, t_lnk *link, int i, int *min)
{
	t_lnk	*tmp;
	int		f;

	tmp = link;
	if ((f = set_const_l((*rooms), i, &min)) == -1)
		return (1);
	if (f == -2)
		return (-2);
	while (tmp)
	{
		if (ft_strequ((*rooms)[f].n, tmp->n1) && tmp->in)
			find_name_n2(tmp, (*rooms), i, &(*rooms)[f].l, &min);
		else if (ft_strequ((*rooms)[f].n, tmp->n2) && tmp->in)
			find_name_n1(tmp, (*rooms), i, &(*rooms)[f].l, &min);
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
	int c;

	c = counte_start_end(bs->r, bs->link, bs->c);
	while (--c >= 0)
	{
		while (1)
		{
			r = find_link(&bs->r, bs->link, bs->c, &bs->min);
			if (r == 1)
				break;
			else if (r == 0)
				return (0);
			if (r == -2)
			{
				write(1, "ERROR no link whith finish\n", 27);
				return (0);
			}
		}
		get_way(bs);//записати маршрут і помітити кімнати та лінки як пройдені
	}
	return (1);
}
