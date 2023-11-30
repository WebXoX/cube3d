/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:02:31 by afarheen          #+#    #+#             */
/*   Updated: 2022/11/22 16:28:49 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
iterates through a list and finds the last element of the list
and returns this.
*/
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur_node;

	if (lst)
		cur_node = lst;
	else
		return (0);
	while (cur_node -> next)
		cur_node = cur_node -> next;
	return (cur_node);
}
