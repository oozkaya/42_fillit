/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 09:13:40 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/05 07:47:11 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_read_buff
** Reads and returns the string from the file descriptor.
*/

char	*ft_read_buff(int fd)
{
	char	*str;
	int		len;
	int		ret;

	len = 0;
	if ((str = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (NULL);
	if ((ret = read(fd, str, BUFF_SIZE)) > 0)
		str[ret] = '\0';
	if (ret == -1)
		write(2, "error read()", 13);
	return (str);
}
