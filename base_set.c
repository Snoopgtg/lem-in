#include "lem-in.h"

void	fill_zero(t_lb *bs)
{
	bs->fna = 0;
	bs->fst = 0;
	bs->fen = 0;
	bs->ll = 0;
	bs->c = 0;
	bs->se = 0;
	bs->ee = 0;
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
		rs[c].lw = NULL;
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

void	fill_q(t_aw **name, char *n, t_aw *lq)
{
	t_aw *tmp;
	t_aw *tmplq;

	tmp = *name;
	tmplq = lq;
	if (!tmplq)
	{
		if (!((tmp) = (t_aw *)malloc(sizeof(t_aw))))
			return ;
		set_name(n, &tmp->q, 1);
		(tmp)->len = 1;
		(tmp)->nx = *name;
		*name = tmp;
	}
	while (tmplq)
	{
		if (!((tmp) = (t_aw *)malloc(sizeof(t_aw))))
			return ;
		set_name(tmplq->q, &tmp->q, 1);
		set_name(n, &tmp->q, 0);
		tmp->len = tmplq->len + 1;
		(tmp)->nx = *name;
		*name = tmp;
		tmplq = tmplq->nx;
	}
}

int		min_from_listq(t_aw *q)
{
	t_aw	*tmp;
	int 	min;

	tmp = q;
	min = tmp->len;
	while (tmp)
	{
		if (tmp->len < min)
			min = tmp->len;
		tmp = tmp->nx;
	}
	return (min);
}