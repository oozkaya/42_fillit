/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozkaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:47:08 by oozkaya           #+#    #+#             */
/*   Updated: 2017/12/14 08:47:18 by oozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int pick)
{
	char	*join;

	if (pick < 0 || pick > 2)
		return (NULL);
	join = ft_strjoin(s1, s2);
	if (pick == 0 || pick == 2)
		free((char*)s1);
	if (pick == 1 || pick == 2)
		free((char*)s2);
	return (join);
}
