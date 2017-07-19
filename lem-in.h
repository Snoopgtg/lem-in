#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft.h"

/*
** fse		flag for check 1 - is start
** fse						2 - is end
** fse						0 - is empty & default
** s_lnk	links of rooms
** s_rn		list of room names
** *nx		next element of list
** *bg		begin first element of list
** na		number of ant
** fna		flag for only one number of ant
** fst		flag for only one start
** fen		flag for only one end
** s_rn		list of room name
** s_an		list of ant name
** s_w		list of ready way
** t_wr		list of way result
** t_aw		all possible way
** s_wr1	list of all possible way
** s_sr		array of list of all possible way
** q 		name of room from
** len		length of way in current room
** m		weight of link
** fl		1 - const mark
** 			0 - temp mark
** c		number of elements in list room names
** se		for check start error
** ee		for check end error
** min		min l in room
** nway		number of way
*/


typedef struct		s_wr1
{
	char 			*n;
	int 			in;
	struct s_wr1	*nx;
	struct s_wr1	*pr;

}					t_wr1;

typedef struct		s_sr
{
	int 			l;
	struct s_wr1	*ww;
	struct s_wr1	*jopa;


}					t_sr;

typedef struct 		s_rs
{
	char			*n;
	int				fst;
	int 			fen;
	int 			l;
	int 			fl;
	char			*q;
	int 			in;
}					t_rs;

typedef struct		s_rn
{
	char			*n;
	int				fst;
	int 			fen;
	int 			l;
	int 			fl;
	struct s_rn		*nx;
	struct s_rn		*bg;
}					t_rn;

typedef struct		s_lnk
{
	char			*n1;
	char 			*n2;
	int 			in;
	struct s_lnk	*nx;
	struct s_lnk	*bg;
}					t_lnk;

typedef struct		s_lb
{
	t_rn			*rnm;
	t_lnk			*link;
	t_rs			*r;
	t_sr			*go1;
	char			*start;
	char			*end;
	int				c;
	int 			na;
	int				fna;
	int				fst;
	int 			fen;
	int				se;
	int 			ee;
	int				min;
	int				nway;
}					t_lb;


int		check_pos(char *s, int a);
long	ft_longatoi(const char *str);
int 	check_int(char *s, int f);

void	fill_zero(t_lb *bs);
void	set_fl_to_zero(t_rs **room, int c);
//int		min_from_listq(t_aw *q);

int		ft_create(t_rn *room, t_rs **rs, int *i);

void 	fill_room(t_lb *bs, char *s);

int 	ft_start(char *s, t_lb *bs);

int		check_links(char *s, t_lb *bs);

int 	try_way(t_lb *bs);

void 	set_name(char *str, char **n, int f);
void 	get_way(t_lb *bs, int l);
void	check_start_end_in_way(t_sr *way, char *start, char *end);

void	ft_del(t_lb *bs);

void	push_ants(t_lb *bs);

//void	fill_q(t_aw **name, char *n, t_aw *lq);

#endif
