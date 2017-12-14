/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:27:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/14 09:27:17 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_del_current
** Deletes char passed in argument.
*/

static void		ft_del_current(char *map, char letter)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == letter)
			map[i] = '.';
		i++;
	}
}

/*
** ft_placement
** Fills the map with the tetrominos passed in argument. The first TM's piece is
** placed from the position 'pos'.
** The function returns zero if TM can't be placed.
*/

static int		ft_placement(t_point *tm, char *map, int pos, int size)
{
	int		i;

	ft_del_current(map, tm->letter);
	while (tm)
	{
		i = pos + tm->x + (tm->y * (size + 1));
		if (!(map[i]) || map[i] != '.')
		{
			ft_del_current(map, tm->letter);
			return (0);
		}
		map[i] = tm->letter;
		tm = tm->next;
	}
	return (1);
}

/*
** ft_solver
** Recursive function using backtracking that tries to find the best solution
** with a map sized by 'size'.
** The function returns zero, if TMs can't be placed.
*/

static int		ft_solver(t_point **tm, t_map *mappy, int pos, int i)
{
	if (!tm[i])
	{
		ft_putstr(mappy->map);
		return (1);
	}
	while (mappy->map[pos])
	{
		if (ft_placement(tm[i], mappy->map, pos, mappy->size) == 1)
		{
			if (ft_solver(tm, mappy, 0, i + 1) == 1)
				return (1);
		}
		pos++;
	}
	return (0);
}

/*
** *ft_run_solver
** Runs ft_solver until it finds the good size of the map.
*/

static t_map	*ft_eventual_resizer(t_point **tm, char *map, int size)
{
	t_map	*mappy;

	if (!(mappy = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	mappy->map = map;
	mappy->size = size;
	while (ft_solver(tm, mappy, 0, 0) == 0)
	{
		mappy->size = mappy->size + 1;
		ft_memdel((void**)&mappy->map);
		mappy->map = ft_create_empty_map(mappy->size);
	}
	return (mappy);
}

/*
** ft_create_tm_struct_tab
** Splits file descriptor into array. Each part of array contains a TM.
** Checks TM's conformity
** For each TM : gets coordinates of each # and attributes a letter
** Puts each TM's structure into an array
** Runs the solver and display solution
*/

void			ft_run_solver(char *str, char letter, int size)
{
	int		i;
	t_map	*mappy;
	char	**tab;
	int		nb;
	t_point	**t_tab;

	i = -1;
	tab = ft_splittetris(str);
	nb = ft_count_tm(str);
	size = ft_sqrt(nb * 4) == 0 ? ft_int_sqrt(nb * 4) + 1 : ft_sqrt(nb * 4);
	if (ft_check_all(tab) == 0)
	{
		ft_putstr_fd("error\n", 1);
		return ;
	}
	if (!(t_tab = (t_point**)malloc(sizeof(**t_tab) * nb + 1)))
		return ;
	t_tab[nb] = 0;
	while (tab[++i])
		t_tab[i] = ft_get_coord_tm(tab[i], 4, letter++);
	mappy = ft_eventual_resizer(t_tab, ft_create_empty_map(size), size);
	ft_free_all(t_tab, str, mappy);
}
