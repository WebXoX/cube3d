/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:08:58 by afarheen          #+#    #+#             */
/*   Updated: 2023/03/15 16:16:36 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
uses malloc to allocate the space as required by the
arguments and then assigns 0 to each element of the array by using bzero().
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	arr = malloc(size * count);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * count);
	return (arr);
}
