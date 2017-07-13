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

void	fill_wr(t_wr **way, char *str, int i, int l)
{
	t_wr *tmp;

	tmp = *way;
	while (tmp)
	{
		if (tmp->l == l)
		{
			set_name(str, &tmp->res, i);
			return ;
		}
		tmp = tmp->nx;
	}
	if (!(tmp = (t_wr *)malloc(sizeof(t_wr))))
		return ;
	set_name(str, &tmp->res, i);
	tmp->l = l;
	tmp->nx = *way;
	*way = tmp;
}

void	look_name(char *n, t_rs *room, int c, t_wr **pyt, int l)
{
	int i;
	//char *trash;

	i = 0;
	while (i < c)
	{
		if (room[i].fst && ft_strequ(room[i].n, n))
		{
			fill_wr(pyt, room[i].n, 0, l);
			return ;
		}
		if (room[i].fl && ft_strequ(room[i].n, n))
		{
			fill_wr(pyt, room[i].n, 0, l);
			look_name(room[i].q, room, c, pyt, l);
		}
		i++;
	}
}
void	get_way(t_lb *bs)
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
			bs->min = room[i].l;
			fill_wr(&bs->go, room[i].n, 1, room[i].l);
			/*trash = room[i].n;
			bs->way = ft_strdup(trash);
			ft_strdel(&trash);
			trash = bs->way;
			bs->way = ft_strjoin(trash, " ");
			ft_strdel(&trash);*/
			look_name(room[i].q, room, bs->c, &bs->go, bs->min);
			//прервати цикл, коли знаходимо останню кімнату далі шукати кімнати не потрібно
		}
		i++;
	}
	ft_printf("%s\n", bs->go->res);
}
