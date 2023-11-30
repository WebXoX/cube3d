/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:09:07 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/23 10:18:17 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
the function counts how many charcaters might exist in the new string by
counting either till the string finishes or 'len' is reached. once
it completes this, the necessary space is allocated and then the
required letters are assigned.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	int				j;
	unsigned int	i;
	int				k;

	i = 0;
	j = 0;
	if (!s || !s[0])
		return (0);
	while (s[i] && j == 0)
	{
		if (i == start)
			while (s[i + j] != '\0' && j < (int)len)
				j++;
		i++;
	}
	substr = malloc((j + 1) * sizeof(char));
	if (!substr)
		return (0);
	i--;
	k = 0;
	while (s[i] && k < j)
		substr[k++] = s[i++];
	substr[k] = '\0';
	return (substr);
}
