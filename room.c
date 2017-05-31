#include "lem-in.h"

void fill_room(t_lb *bs, char *s)
{
	t_rn *tmp;

	tmp = bs->rnm;
	if (!(tmp = (t_rn *)malloc(sizeof(t_rn))))
		return;
	tmp->n = ft_strdup(s);
	if (bs->fst)
		tmp->fst = bs->fst;
	else if (bs->fen)
		tmp->fen = bs->fen;
	tmp->nt = bs->rnm;
	bs->rnm = tmp;


/*	while (tmp)
	{
		if (tmp->fdc == fd)
			return (&(tmp->s));
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	tmp->s = ft_strnew(0);
	tmp->fdc = fd;
	tmp->next = (*h);
	(*h) = tmp;
	return (&(tmp->s));
*/
}
