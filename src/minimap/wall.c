/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:52:24 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 14:04:56 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	wall(t_data *img)
{
	int				i;
	int				j;
	t_coordinate	point;
	int				c;

	point.y = 0;
	i = -1;
	while (++i < img->final_c)
	{
		point.x = 0;
		j = -1;
		while (++j < img->longest_row)
		{
			if (img->map[i][j] == 1)
			{
				c = -1;
				while (++c < img->scale - 2)
					drawline((int []){point.x, point.y + c, point.x
						+ img->scale - 2, point.y + c}, img,
						create_trgb(0, 200, 200, 200));
			}
			point.x += img->scale;
		}
		point.y += img->scale;
	}
}
