/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:51 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/23 10:15:36 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
checking if charater in set
*/
static int	check_set(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (1);
	return (0);
}

/*
the function checks the string till it finds the first letter in the
string which is not in the set - while the letter exists in set, the
string is cut short to exclude that letter. As soon as it reaches
the condition that it is not in the set, the index is set as the
max index of the current string. it then reduces the max index to
when the last charcater which is not in the set appears. Space
is allocated for the new string and then the modified version
of the string is copied to this new space.
the index is set
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	char	*new;

	i = 0;
	temp = (char *)s1;
	if (!s1 || !set)
		return (0);
	while (check_set(set, s1[i]))
	{
		temp = ft_strchr(temp, s1[i + 1]);
		i++;
	}
	i = ft_strlen(temp) - 1;
	while (check_set(set, temp[i]) && i >= 0)
		i--;
	new = malloc(i + 2);
	if (!new)
		return (0);
	ft_memcpy(new, temp, i + 1);
	new[i + 1] = '\0';
	return (new);
}
