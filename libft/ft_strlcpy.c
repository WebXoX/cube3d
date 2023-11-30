/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:42:26 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 18:54:23 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
It copies the characters from source to destination while accounting
for null terminator. 
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (!dstsize)
		return (src_size);
	count = 0;
	while (src[count] != '\0' && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	if (dstsize > 0)
		dst[count] = '\0';
	return (src_size);
}
