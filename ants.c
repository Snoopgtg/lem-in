#include "lem-in.h"

void 	check_all_way(t_sr *way, int nway, char *start, int *antsinend)
{
	t_wr1	*tmp;
	int 	i;

	i = -1;
	while (++i < nway)
	{
		if (!way[i].ww)
			return ;
		tmp = way[i].ww;
		if (tmp->nx->in != 0)
		{
			(*antsinend)++;
			ft_printf("L%d-%s ", tmp->nx->in, tmp->n);
			tmp->nx->in = 0;
		}
		tmp = tmp->nx;
		while (tmp)
		{
			if (tmp->in == 0 && (!ft_strequ(tmp->n, start)))
				if (tmp->nx->in)
				{
					tmp->in = tmp->nx->in;
					tmp->nx->in = 0;
					ft_printf("L%d-%s ", tmp->in, tmp->n);
				}
			tmp = tmp->nx;
		}
	}
}

void 	check_start(t_lb *bs, int *antisend)
{
	int		i;
	t_wr1	*tmp;

	if (antisend)
		;
	i = -1;
	while (++i < bs->nway )
	{
		if (bs->naa <= 0)
			return ;
		if ((i != 0 && ((bs->go1[i].l - bs->go1[0].l + 1) < bs->na)) || i == 0)
		{

			tmp = bs->go1[i].ww;
			if (tmp)
			{
				while (tmp->nx && tmp->nx->nx)
					tmp = tmp->nx;
				if (ft_strequ(tmp->n, bs->end))
					(*antisend)++;
				tmp->in = bs->na - bs->naa + 1;
				ft_printf("L%d-%s ", tmp->in, tmp->n);
				bs->naa--;
			}
		}
	}
}

int 	push_ants(t_lb *bs)
{
	int i;

	i = 0;
	bs->naa = bs->na;
	write(1, "\n", 1);
	if (!bs->go1[0].ww)
		return (0);
	while (i < bs->na)
	{
		check_all_way(bs->go1, bs->nway, bs->start, &i);
		check_start(bs, &i);
		if ((ft_strequ(bs->go1[0].ww->n, bs->end) &&ft_strequ(bs->go1[0].ww->nx->n, bs->start)))
			;
		else
			write(1, "\n", 1);
	}
	if (ft_strequ(bs->go1[0].ww->n, bs->end) && ft_strequ(bs->go1[0].ww->nx->n, bs->start))
		write(1, "\n", 1);
	return (1);
}
//****************************************
// правильність виводу!!!!!!!!!!!!!!!!