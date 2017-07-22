#include "lem-in.h"

/*
** startend flag for start 1
** 					end 2
**					default 0
** імя має бути чаром;
*/
int 	fill_name(char *s, t_lb *bs)
{
	int i;
	char *tmp;

	i = 0;
	while (s[i] != ' ')
		i++;
	i++;
	if (!check_pos(s + i, 2))
		return (0);
	tmp = ft_strsub(s, 0 , (size_t)(i - 1));
	ft_printf("%s\n", s);
	ft_strdel(&s);
	fill_room(bs, tmp, NULL);
	ft_strdel(&tmp);
	ft_strdel(&s);
	return (1);
}

int 	check_room_name(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '-')
	{
		if (ft_isalnum(s[i]))
			i++;
		else
			return (1);
	}
	return (0);
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

void 	fill_room(t_lb *bs, char *s, t_rn *tmp)
{
	if (bs->rnm && (bs->re = 1) && check_dubl_name(bs->rnm, s))
		return ;
	if (!(tmp = (t_rn *)malloc(sizeof(t_rn))))
		return ;
	tmp->n = ft_strdup(s);
	if (bs->fst && (tmp->fst = 1))
	{
		tmp->fen = 0;
		bs->fst = 0;
		bs->se = 1;
		bs->min = 0;
		bs->start = ft_strdup(tmp->n);
	}
	else if (bs->fen && (tmp->fen = 1))
	{
		tmp->fst = 0;
		bs->fen = 0;
		bs->ee = 1;
		bs->end = ft_strdup(tmp->n);
	}
	else if (!(tmp->fst = 0))
		tmp->fen = 0;
	tmp->nx = bs->rnm;
	bs->rnm = tmp;
}

