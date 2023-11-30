/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:41:12 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:26:35 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
works then same as strchr but stores the location each time
the character is encountered and then is finally returned
only after the string gets over which ensures that its the last
occurance instead of the first unlike strchr.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*location;

	location = 0;
	i = 0;
	while (i <= (int)ft_strlen((char *)s))
	{
		if ((char)c == s[i])
			location = (char *) &s[i];
		i++;
	}
	return (location);
}
