/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:39:08 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:29:01 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
add node to the back of the lst after reaching the
last element whose "next" points to null.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur_node;

	if (!(*lst))
		*lst = new;
	else
	{
		cur_node = *lst;
		while (cur_node -> next)
			cur_node = cur_node -> next;
		cur_node -> next = new;
	}
}
