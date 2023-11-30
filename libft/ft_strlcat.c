/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:36:26 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:27:20 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
If the desired dstination size is less than the current dstination,
nothing more can be added so we return the length of source added to
desired dstination. Otherwise, size-dst_size -1 number of elements are
concatenated to the dstination. The return value is the length of
source + length of original dstination.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	temp;
	size_t	dst_size;

	j = 0;
	dst_size = 0;
	if (dst)
		dst_size = ft_strlen(dst);
	if (dstsize <= dst_size)
		return (ft_strlen(src) + dstsize);
	temp = dst_size;
	while (src[j] != '\0' && j < dstsize - dst_size - 1)
		dst[temp++] = src[j++];
	dst[temp] = '\0';
	return (ft_strlen(src) + dst_size);
}
