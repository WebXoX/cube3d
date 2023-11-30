/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:53:53 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/21 18:47:39 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
iterates through a list of tlist elemnts and counts how many elemnts are there.
*/
int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*cur_node;

	if (lst)
		length = 1;
	else
		return (0);
	cur_node = lst;
	while (cur_node -> next)
	{
		length++;
		cur_node = cur_node -> next;
	}
	return (length);
}
