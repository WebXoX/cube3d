/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:46:14 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:27:51 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
write a string in the file using fd
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s)
		while (s[index] != '\0')
			write(fd, &s[index++], 1);
}
