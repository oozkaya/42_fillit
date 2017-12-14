/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:47:11 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/04 14:40:47 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	int		size;
	char	*str;

	size = 2;
	if (ac == 2)
	{
		if ((fd = open(av[1], 0, O_RDONLY)) == -1)
		{
			ft_putstr_fd("error open().\n", 2);
			return (-1);
		}
		str = ft_read_buff(fd);
		ft_run_solver(str, 'A', size);
		if (close(fd) == -1)
		{
			ft_putstr_fd("error close().\n", 2);
			return (-1);
		}
	}
	else
		ft_putstr_fd("usage: ./fillit input_file\n", 1);
	return (0);
}
