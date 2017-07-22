#include "lem-in.h"

void	fill_zero(t_lb *bs)
{
	bs->rnm = NULL;
	bs->link = NULL;
	bs->r = NULL;
	bs->go1 = NULL;
	bs->fna = 0;
	bs->fst = 0;
	bs->fen = 0;
	bs->c = 0;
	bs->se = 0;
	bs->ee = 0;
	bs->re = 0;
	bs->min = 2147483647;
}

void	copy_list_name(t_rn *room, t_rs *rs, int i)
{
	t_rn	*tmp;
	int 	c;

	c = 0;
	tmp = room;
	while (c < i)
	{
		rs[c].n = ft_strdup(tmp->n);
		ft_strdel(&tmp->n);
		rs[c].fst = tmp->fst;
		rs[c].fen = tmp->fen;
		rs[c].q = 0;
		rs[c].l = (tmp->fst) ? 0 : 2147483647;
		rs[c].fl = 0;
		rs[c].in = 1;
		tmp = tmp->nx;
		c++;
	}
}

int		ft_create(t_rn *room, t_rs **rs, int *i)
{
	t_rn *tmp;

	tmp = room;
	while (tmp)
	{
		(*i)++;
		tmp = tmp->nx;
	}
	if (!(*rs = (t_rs *)malloc(sizeof(t_rs) * (*i))))
		return (0);
	copy_list_name(room, *rs, (*i));
	return (1);
}

void	set_fl_to_zero(t_rs **room, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		(*room)[i].fl = 0;
		if ((*room)[i].q)
			ft_strdel(&(*room)[i].q);
		(*room)[i].l = ((*room)[i].fst) ? 0 : 2147483647;
		i++;
	}
}