#ifndef LEM_IN_H
#define LEM_IN_H

# include "libft.h"

/*
** fse		flag for check 1 - is start
** fse						2 - is end
** fse						0 - is empty & default
** s_an		lint of room names
** na		number of ant
** fna		flag for only one number of ant
** fst		flag for only one start
** fen		flag for only one end
** s_rn		list of room name
** s_an		list of ant name
*/

typedef struct		s_rn
{
	char			*n;
	struct s_an		*nt;
	struct s_an		*bg;
}					t_rn;

typedef struct		s_an
{
	char			*n;
	struct s_an		*nt;
	struct s_an		*bg;
}					t_an;

typedef struct		s_lb
{
	t_rn			*rnm;
	t_an			*anm;
	int 			na;
	int				fna;
	int				fst;
	int 			fen;
	int 			fse;
	int 			fr;
	int 			fl;
}					t_lb;

int 			st;
int 			end;
int 			all;

int		check_pos(char *s, int a);
long	ft_longatoi(const char *str);
int		fill_link(char *s);
int 	check_int(char *s, int f);

void	fill_zero(t_lb *bs);

#endif
