#include "lem-in.h"

void 	set_name(char *str, char **n, int f)
{
	char *trash;

	if (f)
	{
		*n = ft_strdup(str);
		//ft_strdel(&str);
		trash = *n;
		*n = ft_strjoin(trash, "-");
		//ft_strdel(&trash);
	}
	else
	{
		trash = *n;
		*n = ft_strjoin(trash, str);
		//ft_strdel(&trash);
		trash = *n;
		*n = ft_strjoin(trash, "-");
		//ft_strdel(&trash);
	}
}

void fill_wr(char *str, t_sr *resway)
{
	//t_wr	*tmp;
	t_wr1	*temp;

	temp = resway->ww;
	//tmp = *way;
	if (!(temp = (t_wr1 *)malloc(sizeof(t_wr1))))
		return ;
	//set_name(str, &tmp->res, i);
	temp->in = 0;
	temp->n = ft_strdup(str);
	temp->nx = resway->ww;
	if (resway->ww != NULL)
	{
		resway->ww->pr = temp;
		resway->ww->nx = temp;
	}
 	resway->ww = temp;
	temp->pr = NULL;
	//tmp->l = l;
	//tmp->nx = *way;
	//*way = tmp;
}

void look_name(char *n, t_rs **room, int c, t_sr *pyt)
{
	int i;
	//char *trash;

	i = 0;
	while (i < c)
	{
		if ((*room)[i].fst && ft_strequ((*room)[i].n, n))
		{
			fill_wr((*room)[i].n, pyt);
			return ;
		}
		if ((*room)[i].fl && ft_strequ((*room)[i].n, n))
		{
			fill_wr((*room)[i].n, pyt);
			look_name((*room)[i].q, room, c, pyt);
			(*room)[i].in = 0;
		}
		i++;
	}
}
void 	get_way(t_lb *bs, int l)
{
	int		i;
	t_rs	*room;
	//char 	*trash;

	i = 0;
	room = bs->r;
	while (i < bs->c)
	{
		if (room[i].fl && room[i].fen)
		{
			bs->go1[l].l = room[i].l;
			fill_wr(room[i].n, &bs->go1[l]);
			/*trash = room[i].n;
			bs->way = ft_strdup(trash);
			ft_strdel(&trash);
			trash = bs->way;
			bs->way = ft_strjoin(trash, " ");
			ft_strdel(&trash);*/
			look_name(room[i].q, &bs->r, bs->c, &bs->go1[l]);
			break;
		}
		i++;
	}
	check_start_end_in_way(&(bs->go1[l]), bs->start, bs->end);
	ft_printf("-----------WAY--------");
//	ft_printf("%s\n", bs->go->res);
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
