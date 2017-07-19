#include "lem-in.h"

void check_all_way(t_sr *way, int nway, char *start, char *end)
{
	t_wr1	*tmp;
	int 	i;

	i = -1;
	while (++i < nway)
	{
		tmp = way[i].ww;
		while (tmp != way[i].ww)
		{
			if (tmp->in && (ft_strcmp(tmp->n, start) || ft_strcmp(tmp->n, end)))
				if (tmp->nx)
					tmp->nx->in = tmp->in;
			tmp = tmp->pr;
		}
	}
}

void	push_ants(t_lb *bs)
{
	int i;

	i = -1;
	while (i < bs->na)
	{
		check_all_way(bs->go1, bs->nway, bs->start, bs->end);
		/*check_start();
		print_ants();*/
	}
}
