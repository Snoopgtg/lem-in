#include "lem-in.h"

/*
** int start for fill ants in start room
** 1 - is start
**/
void fill_wr(char *str, t_wr1 **resway, int start, int ants)
{
	t_wr1	*temp;
	t_wr1	*curr;

	if (!(temp = (t_wr1 *)malloc(sizeof(t_wr1))))
		return ;
	if (start)
		temp->in = ants;
	else
		temp->in = 0;
	temp->n = ft_strdup(str);
	temp->nx = NULL;
	if (*resway == NULL)
		*resway = temp;
	else
	{
		curr = *resway;
		while (curr->nx)
			curr = curr->nx;
		curr->nx = temp;
	}
}

void look_name(char *n, t_wr1 **pyt, t_lb *bs)
{
	int i;

	i = 0;
	while (i < bs->c)
	{
		if (bs->r[i].fst && ft_strequ(bs->r[i].n, n))
		{
			fill_wr(bs->r[i].n, pyt, 1, bs->na);
			return ;
		}
		if (bs->r[i].fl && ft_strequ(bs->r[i].n, n))
		{
			fill_wr(bs->r[i].n, pyt, 0, bs->na);
			look_name(bs->r[i].q, pyt, bs);
			bs->r[i].in = 0;
		}
		i++;
	}
}
void	get_way(t_lb *bs, int l)
{
	int		i;
	t_rs	*room;

	i = 0;
	room = bs->r;
	while (i < bs->c)
	{
		if (room[i].fl && room[i].fen)
		{
			bs->go1[l].l = room[i].l;
			fill_wr(room[i].n, &bs->go1[l].ww, 0, bs->na);
			look_name(room[i].q, &bs->go1[l].ww, bs);
			break;
		}
		i++;
	}
	check_start_end_in_way(&(bs->go1[l]), bs->start, bs->end);
	set_fl_to_zero(&bs->r, bs->c);
}

void	check_start_end_in_way(t_sr *way, char *start, char *end)
{
	t_wr1	*tmp;
	int 	s;
	int		e;

	s = 0;
	e = 0;
	tmp = way->ww;
	while (tmp)
	{
		(tmp->n && ft_strequ(tmp->n, start)) ? s++ : 0;
		(tmp->n && ft_strequ(tmp->n, end)) ? e++ : 0;
		tmp->in = 0;
		tmp = tmp->nx;
	}
	if (s == 1 && e == 1)
		return;
	tmp = way->ww;
	while (tmp)
	{
		way->ww = way->ww->nx;
		ft_strdel(&tmp->n);
		free(tmp);
		tmp = way->ww;
	}
	way->ww = NULL;
}
