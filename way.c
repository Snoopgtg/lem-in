#include "lem-in.h"

void	ft_create(t_rn *room, t_rs *rs, int i)
{
	t_rn *tmp;

	tmp = room;
	while (tmp)
	{
		i++;
		tmp = tmp->nx;
	}
	if (!(rs = (t_rs *)malloc(sizeof(t_rs) * i)))
		return ;
}

char	*find_l(t_rs *rooms, int l)
{
	t_rs	*tmp;
	int		min;

	tmp = rooms;
	min = tmp->l;
	while (tmp)
	{
		if (tmp->l < min)
			min = tmp->l;
		tmp = tmp->nx;
	}
	tmp = rooms;
	while (tmp)
	{
		if (min == tmp->l)
			return (tmp->n);
		tmp = tmp->nx;
	}
	return (NULL);
}

int 	find_link(char *n, t_lnk *link)
{
	t_lnk *tmp;

	tmp = link;
	while (tmp)
	{
		if (ft_strequ(n, tmp->n1))
			return (1);
		tmp = tmp->nx;
	}
	return (0);
}

void	try_way(t_lb *bs)
{
	t_rn *tmp;

	tmp = bs->rnm;
	ft_create(bs->rnm, bs->r);
	while (bs->fen)
	{

		if (find_link(find_l(bs->rnm, bs->ll), bs->link))
			bs->ll = 1;
		tmp = tmp->nx;
	}
}
