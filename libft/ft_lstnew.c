/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:26:36 by afarheen          #+#    #+#             */
/*   Updated: 2023/11/30 14:17:03 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
allocates space for a new element and assigns the "next" as NULL
and the content as the content that was passed. Finally this node is returned
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(1 * sizeof(t_list));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
