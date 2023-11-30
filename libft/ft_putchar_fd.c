/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:04:11 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:28:03 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
writes chacracter to a file using the file descriptor passed.
*/
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
