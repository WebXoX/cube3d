/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:52:37 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 15:35:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

float	fixang(float a)
{
	if (a > 360.0f)
	{
		a -= 360.0f;
	}
	if (a < 0.0f)
	{
		a += 360.0f;
	}
	return (a);
}

int	compare(float d1, float d2, t_data *img)
{
	if ((d1 == 0 && (d2 > 0)) || ((d1 != 0 && (d2 != 0)) && (d1 > d2)))
		drawline((int []){img->player.x + 10 / 4, img->player.y
			+ img->scale / 6, img->verticalp.x, img->verticalp.y},
			img, 0xFF0000);
	else
		drawline((int []){img->player.x + 10 / 4, img->player.y
			+ img->scale / 6, img->horizontalp.x, img->horizontalp.y},
			img, 0xFF0000);
	return (1);
}

int	ray_starter(t_data *img, int loop)
{
	int		i;
	float	ray;

	i = -1;
	ray = fixang(img->player.da - 33);
	while (++i < loop)
	{
		img->ra = ray + i * 66 / 66;
		compare(horizontal_inter(img), vertical_inter(img, 0, 0), img);
	}
	return (1);
}
