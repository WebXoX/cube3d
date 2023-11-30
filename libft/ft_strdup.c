/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:37:50 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 18:59:06 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

/*
Allocate space for the length of the string passed including space for null
terminator and then copy the string to the new space.
*/
char	*ft_strdup(const char *src)
{
	char	*copy;

	copy = (char *)malloc(ft_strlen(src) + 1);
	if (!copy)
		return (0);
	ft_strcpy(copy, (char *)src);
	return (copy);
}
