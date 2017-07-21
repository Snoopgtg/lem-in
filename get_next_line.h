/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalata <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:59:52 by ysalata           #+#    #+#             */
/*   Updated: 2017/03/20 18:38:56 by ysalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int					get_next_line(int const fd, char **line);

typedef	struct		s_fdlist
{
	int				fd;
	char			*buf;
	struct s_fdlist	*next;

}					t_fdlist;

#endif
