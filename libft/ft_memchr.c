/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:43:33 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:28:28 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compares the unsigned char casted version of integer being passed
with with each character of the array, if its a match, send
the string from that charcter onwards otherwise return 0.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;
	unsigned char	cu;

	str = (char *)s;
	i = 0;
	cu = (unsigned char)c;
	while (i < n)
	{
		if (cu == (unsigned char)str[i])
			return (&str[i]);
		i++;
	}
	return (0);
}
