#include "lem-in.h"

//*************************************************************************
#include <fcntl.h>
//*************************************************************************

/*
** startend flag for start 1
** 					end 2
**					default 0
** імя має бути чаром;
*/
int fill_name(char *s, t_lb *bs)
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
	fill_room(bs, tmp);
	ft_strdel(&tmp);
	ft_strdel(&s);
	return (1);
}

int ft_hesh_start_end(char *s, t_lb *bs, int fd)
{
	if (ft_strequ("##start", s))
	{
		if (bs->fst)
		{
			ft_strdel(&s);
			return (0);
		}
		bs->fst = 1;
	}
	else
	{
		if (bs->fen)
		{
			ft_strdel(&s);
			return (0);
		}
		bs->fen = 1;
	}
	ft_printf("%s\n", s);
	ft_strdel(&s);
	get_next_line(fd, &s);
	return (ft_start(s, bs));
}

int ft_hesh(char *s, t_lb *bs, int fd)
{
	if (ft_strequ("##start", s) || ft_strequ("##end", s))
		return (ft_hesh_start_end(s, bs, fd));
	else if (ft_strnequ("##", s, 2) && s[2] != '#')
	{
		ft_printf("%s\n", s);
		ft_strdel(&s);
		get_next_line(fd, &s);
		ft_printf("%s\n", s);
		free(s);
	}
	else
	{
		ft_printf("%s\n", s);
		ft_strdel(&s);
	}
	return (1);

}

int ft_numofant(char *s, int *na, int *fna)
{
	int		i;

	if (*fna)
		return (0);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	if (i > 11 || !check_int(s, 1))
		return (0);
	*na = ft_atoi(s);
	*fna = 1;
	ft_printf("%d\n", *na);
	ft_strdel(&s);
	return (1);
}

int ft_start(char *s, t_lb *bs)
{
	int i;

	i = 0;
	if (*s == '-' || *s == ' ' || *s == 'L')
		return (0);
	while ((s[i] != ' ' && s[i] != '-') && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_numofant(s, &bs->na, &bs->fna));
	else if (s[i] == ' ')
		return (fill_name(s, bs));
	else if (s[i] == '-')
		return (check_links(s, bs));
	return (0);

}

int		main(int argc, char **argv)
{
	char	*line;
	int		r;
	t_lb	bs;
	int 	fd;

	//*****************************DELETE*********************************
	if (argc || argv)
		;
	fd = open(argv[1], O_RDONLY);
	//fd = 0;
	//********************************************************************
	bs.rnm = NULL;
	bs.link = NULL;
	bs.r = NULL;
	bs.go1 = NULL;
	line = 0;
	fill_zero(&bs);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '#')
		{
			r = ft_hesh(line, &bs, fd);
		}
		else
		{
			r = ft_start(line, &bs);
		}
		if (r == 0)
		{
			write(1, "ERROR\n", 6);
			return (1);
		}
	}
	if (!bs.fna || !bs.se || !bs.ee || !ft_create(bs.rnm, &bs.r, &bs.c) || !try_way(&bs))
	{
		write(1, "ERROR in links\n", 15);
		return (1);//спробувати порахувати з тих даних що ввели і ретурт прибрати
	}
	ft_printf("All CORRECT");
	//ft_del(&bs);
	//sleep(120);
	return (0);
}
//18446744073709551619
/*
2
##start
start 0 1
##end
end 100 100
0 94 66
2 39 31
4 35 24
5 52 42
4-0
start-4
start-2
start-5
start-4
end-2
end-5
end-0

2
##start
start 0 1
##end
end 100 100
0 16 99
1 42 7
2 71 8
3 45 64
4 55 63
5 16 59
6 33 98
7 10 27
8 61 64
9 76 89
10 2 53
11 19 92
12 81 4
0-11
1-8
2-4
2-10
3-1
3-11
3-5
3-2
3-11
3-0
3-12
3-4
3-8
3-4
3-0
3-7
4-3
5-2
6-12
6-0
7-12
8-10
8-2
8-1
8-6
8-4
9-12
9-0
9-3
10-3
11-10
12-9
start-3
start-9
start-5
start-7
start-8
end-8
end-10
end-11
end-12
end-4
end-1

мінімальна кількість шляхів
 правильно 2
 не привально 1
3
##start
start 23 3
4 16 7
#comment
1 16 3
3 16 5
2 9 3
##end
end 9 5
start-1
start-3
3-4
3-2
4-end
2-end
 */