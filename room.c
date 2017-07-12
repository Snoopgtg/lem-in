#include "lem-in.h"

void	print_list(t_lb *bs)
{
	t_rn *tmp;

	tmp = bs->rnm;
	while (tmp)
	{
		ft_printf(RED"name = %s fst = %d fen = %d\n"RC, tmp->n, tmp->fst, tmp->fen);
		tmp = tmp->nx;
	}
}

int		check_dubl_name(t_rn *rooms, char *n)
{
	t_rn *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->n, n))
			return (1);
		tmp = tmp->nx;
	}
	return (0);
}


void	fill_room(t_lb *bs, char *s)
{
	t_rn *tmp;

	if (bs->rnm && check_dubl_name(bs->rnm, s))
		return ;
	if (!(tmp = (t_rn *)malloc(sizeof(t_rn))))
		return ;
	tmp->n = ft_strdup(s);
	if (bs->fst)
	{
		tmp->fst = 1;
		tmp->fen = 0;
		bs->fst = 0;
		bs->se = 1;
		bs->min = 0;
	}
	else if (bs->fen)
	{
		tmp->fen = 1;
		tmp->fst = 0;
		bs->fen = 0;
		bs->ee = 1;
	}
	else
	{
		tmp->fst = 0;
		tmp->fen = 0;
	}
	tmp->nx = bs->rnm;
	bs->rnm = tmp;
	//print_list(bs);
}
