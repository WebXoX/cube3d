/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:39:43 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:28:10 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
sets each letter of the array passed to the c being passed
till len number of places has been assigned.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*new;

	new = (char *)b;
	i = 0;
	while (i < len)
	{
		new[i] = c;
		i++;
	}
	return (b);
}
