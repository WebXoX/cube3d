/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:03:38 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:26:53 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Counts all characters in the string 
*/
size_t	ft_strlen(const char *s)
{
	size_t		index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}
