/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:31:45 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/05 11:33:08 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE ((4 * 4) + 4 + 1) * 26

typedef struct	s_point
{
	int			x;
	int			y;
	char		letter;
	void		*next;
}				t_point;

typedef struct	s_map
{
	char		*map;
	int			size;
}				t_map;

char			*ft_read_buff(int fd);
char			**ft_splittetris(char *str);
int				ft_count_tm(char const *str);
int				ft_check_all(char **tab);
char			*ft_create_empty_map(int side);
t_point			*ft_get_coord_tm(char *src, int size, char letter);
void			ft_run_solver(char *str, char letter, int size);
void			ft_free_all(t_point **t_tab, char *str, t_map *map);

#endif
