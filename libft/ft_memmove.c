/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:53:54 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:28:15 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
unlike memcpy, memmove accounts fr overflow thsi functions doe sthis
by chekcing if teh location the source could possibly overlap with the dest
(src < dest) if this is true, the function copies the letters starting from the
back to not allow for the overlap. otherwise it is copied normally from start
to end.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_chars;
	char	*dst_chars;
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	src_chars = (char *)src;
	dst_chars = (char *)dst;
	if (dst == src)
		return (dst);
	if (src < dst)
		while (len-- > 0)
			*(dst_chars + len) = *(src_chars + len);
	else
		while (++i < len)
			*(dst_chars + i) = *(src_chars + i);
	return (dst);
}
