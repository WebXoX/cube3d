/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:19:34 by afarheen          #+#    #+#             */
/*   Updated: 2024/01/02 13:32:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((data->width > x && data->height > y) && (0 <= x && 0 <= y))
	{
		dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	step(int *p2, int *p1, double *error, double dp)
{
	*error = *error + dp;
	if (*p1 < *p2)
		*p1 = *p1 + 1;
	else
		*p1 = *p1 - 1;
}

void	drawline(int *vals, t_data *img, int color)
{
	t_line	line;

	line.dx = abs(vals[2] - vals[0]);
	line.dy = -abs(vals[3] - vals[1]);
	line.error = line.dx + line.dy;
	while (1)
	{
		my_mlx_pixel_put(img, vals[0], vals[1], color);
		if (vals[1] == vals[3] && vals[2] == vals[0])
			break ;
		line.e2 = 2 * line.error;
		if (line.e2 <= line.dx)
		{
			if (vals[3] == vals[1])
				break ;
			step(&vals[3], &vals[1], &(line.error), line.dx);
		}
		if (line.e2 >= line.dy)
		{
			if (vals[0] == vals[2])
				break ;
			step(&vals[2], &vals[0], &(line.error), line.dy);
		}
	}
}
