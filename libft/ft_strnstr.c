/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:24:42 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:26:40 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
if the word to be found is empty, return back the haystack.
Else while going thorugh the haystack, check for word to be
found. if it is found, return the location of the start of the
word in the haystack.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (len != 0)
	{
		while (haystack[i] != '\0' && i <= len - 1)
		{
			j = 0;
			temp = i;
			while (haystack[temp] == needle[j] && haystack[temp] != '\0'
				&& needle[j] != '\0' && temp <= len - 1)
			{
				j++;
				temp++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			i++;
		}
	}
	return (0);
}
