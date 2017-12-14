/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:09:27 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/14 09:23:45 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int	ft_checkall(char **tab)
** Check validity of each Tetrominos with :
**
** ft_check_content : check size and content ('#', '.','\n'))
** &&
** ft_contiguous_places : check if TM has pieces contiguous by at least 1 side.
** At least one '#' in the TM  has to touch two others '#'.
*/

#include "fillit.h"

static int	ft_check_content(char *str)
{
	int		i;
	int		hashtag;
	int		point;
	int		endline;

	hashtag = 0;
	point = 0;
	endline = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hashtag++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			endline++;
		i++;
	}
	if (hashtag == 4 && point == 12 && endline == 4)
		return (1);
	return (0);
}

static int	ft_nbsides_touched(char *str, int pos)
{
	int		nb_sides;
	int		len;

	nb_sides = 0;
	len = ft_strlen(str);
	if ((pos - 1) >= 0 && str[pos - 1] == '#')
		nb_sides++;
	if ((pos + 1) < len && str[pos + 1] == '#')
		nb_sides++;
	if ((pos - 5) >= 0 && str[pos - 5] == '#')
		nb_sides++;
	if ((pos + 5) < len && str[pos + 5] == '#')
		nb_sides++;
	return (nb_sides);
}

static int	ft_contiguous_pieces(char *str)
{
	int		i;
	int		nb_sides;
	int		twosides;

	i = 0;
	twosides = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			nb_sides = ft_nbsides_touched(str, i);
			if (nb_sides >= 2)
				twosides = 1;
			if (nb_sides == 0)
				return (0);
		}
		i++;
	}
	return (twosides);
}

int			ft_check_all(char **tab)
{
	int		tm_nb;

	tm_nb = 0;
	while (tab[tm_nb])
	{
		if (ft_check_content(tab[tm_nb]) == 0)
			return (0);
		if (ft_contiguous_pieces(tab[tm_nb]) == 0)
			return (0);
		tm_nb++;
	}
	if (tm_nb == 0)
		return (0);
	return (1);
}
