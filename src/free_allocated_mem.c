/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated_mem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:10:40 by ade-verd          #+#    #+#             */
/*   Updated: 2017/12/14 09:23:53 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_all(t_point **t_tab, char *str, t_map *mappy)
{
	int		i;
	void	*tmp;

	i = 0;
	while (t_tab[i])
	{
		while (t_tab[i])
		{
			tmp = t_tab[i]->next;
			ft_memdel((void**)&t_tab[i]);
			t_tab[i] = tmp;
		}
		i++;
	}
	ft_memdel((void**)&t_tab);
	ft_memdel((void**)&str);
	ft_memdel((void**)&mappy->map);
	ft_memdel((void**)&mappy);
}
