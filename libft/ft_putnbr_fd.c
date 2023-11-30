/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:57:08 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:27:54 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
checks the maximum tenth position the number holds and returns it
*/
static int	check_tens(int num)
{
	int	i;
	int	tens;

	i = 0;
	tens = 1;
	while (num != 0)
	{
		i++;
		num = num / 10;
		if (i != 1)
			tens = tens * 10;
	}
	return (tens);
}

/*
writes the charcater passed using fd
*/
static void	pt_char(int num, int fd)
{
	num = '0' + num;
	write(fd, &num, 1);
}

/*
in case of trailing zeroes, write them till the number is 0.
*/
static void	trailing_zeroes(int num, int fd)
{
	while (num != 0)
	{
		write(fd, "0", 1);
		num = num / 10;
	}
}

/*
For the main number process, the number is continusly divided by the maximum
tens at that iteration. it starts with the initial value returned by
check_tens() and is iteratively divided by ten at each loop. the number at
that tenth position is printed through this way and then the number itself
is multiplied by the tens and subtracted from the number to get the rest of the
digits to repeat this process. If there are trailing zeroes, the number
obviously becomes zero at one point so the these zeroes are printed in the
trailing_zeroes().
*/
void	ft_putnbr_fd(int num, int fd)
{
	int	tens;
	int	cur_num;

	tens = check_tens(num);
	if (num == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(fd, "-", 1);
			num = num * (-1);
		}
		if (num == 0)
			write(fd, "0", 1);
		while (num != 0)
		{
			cur_num = num / tens;
			pt_char(cur_num, fd);
			num = num - (cur_num * tens);
			tens = tens / 10;
			if (num == 0 && tens != 0)
				trailing_zeroes(tens, fd);
		}
	}
}
