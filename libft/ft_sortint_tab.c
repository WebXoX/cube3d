/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortint_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:16 by afarheen          #+#    #+#             */
/*   Updated: 2023/02/18 13:16:31 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	curr;
	int	flag;

	flag = 0;
	i = 1;
	while (i < size)
	{
		curr = tab[i];
		j = i;
		while (j > 0 && flag != 1)
		{
			if (tab[j] < tab[j - 1] && j > 0)
			{
				tab[j] = tab[j - 1];
				j--;
			}
			else
				flag = 1;
			tab[j] = curr;
		}
		flag = 0;
		i++;
	}
}
