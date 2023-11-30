/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:40:18 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/23 17:12:00 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copies each character of the src string to the destination string till
it reaches n characters. it assigns \0 after the last letter assuming
the the size passed includes space for null terminator as well.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*dst_new;
	char	*src_new;

	dst_new = (char *)dst;
	src_new = (char *)src;
	if (!src_new && !dst_new)
		return (0);
	count = 0;
	while (count < n)
	{
		dst_new[count] = src_new[count];
		count++;
	}
	return (dst);
}
