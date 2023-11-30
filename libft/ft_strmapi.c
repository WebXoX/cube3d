/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:22:13 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/23 10:00:59 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocate space for a new string the same size as the string passed.
Apply function to each element of the string and add it to the new array.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_str;

	if (!s)
		return (0);
	i = 0;
	new_str = (char *) malloc(((ft_strlen(s) + 1) * sizeof(char)));
	if (!new_str)
		return (0);
	while (s[i])
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
