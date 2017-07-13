#include "lem-in.h"

void ft_del_rs(t_rs *room, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		ft_strdel(&room[i].n);
		if (room[i].q != 0)
			ft_strdel(&room[i].q);
		i++;
	}
	room = NULL;
}

void	del_name(t_rn *name)
{
	t_rn *tmp;
	t_rn *trash;

	trash = name;
	while (trash)
	{
		tmp = trash->nx;
		free(trash);
		trash = tmp;
	}
	name = NULL;
}

void	del_link(t_lnk *name)
{
	t_lnk *tmp;
	t_lnk *trash;

	trash = name;
	while (trash)
	{
		tmp = trash->nx;
		ft_strdel(&trash->n1);
		ft_strdel(&trash->n2);
		free(trash);
		trash = tmp;
	}
	name = NULL;
}

void	ft_del(t_lb *bs)
{
	ft_del_rs(bs->r, bs->c);
	del_name(bs->rnm);
	del_link(bs->link);
}