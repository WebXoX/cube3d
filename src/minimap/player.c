/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:52:05 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 15:24:33 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	set_map_value(t_data *data, char c)
{
	if (c == 'N')
		data->player.da = 90.0f;
	else if (c == 'S')
		data->player.da = 270.0f;
	else if (c == 'E')
		data->player.da = 180.0f;
	else if (c == 'W')
		data->player.da = 360.0f;
	data->player.mdx = cos(radiansfd(data->player.da));
	data->player.mdy = sin(radiansfd(data->player.da));
}

void	set_values(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.dy = -1.0;
		data->camaera.x = 0.66;
		data->directionstart = 1;
	}
	else if (c == 'S')
	{
		data->player.dy += 1;
		data->camaera.x -= 0.66;
		data->directionstart = 1;
	}
	else if (c == 'E')
	{
		data->player.dx = 1;
		data->camaera.y = 0.66;
		data->directionstart = 1;
	}
	else if (c == 'W')
	{
		data->player.dx -= 1;
		data->camaera.y -= 0.66;
		data->directionstart = 1;
	}
	set_map_value(data, c);
}

int	ft_isplayer(char c, t_data *data, int i, int row_num)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		(data->player_count)++;
		data->cx = i + 0.5;
		data->cy = row_num + 0.5;
		set_values(data, c);
		return (1);
	}
	else
		return (0);
}

void	draw_player(t_data *img, int i, int j)
{
	int	c;

	if (img->map[i][j] == 2)
	{
		c = -1;
		while (++c < img->scale / 4)
			drawline((int []){img->player.x, img->player.y + c,
				img->player.x + 5, img->player.y + c}, img, 0x735674);
	}
}

void	player(t_data *img)
{
	int				i;
	int				j;
	t_coordinate	point;

	img->player.x = (img->scale * (int)img->cx) + img->scale / 4;
	img->player.y = (img->scale * (int)img->cy) + img->scale / 4;
	i = -1;
	while (++i < img->final_c)
	{
		j = -1;
		while (++j < img->longest_row)
		{
			draw_player(img, i, j);
			point.x += img->scale;
		}
		point.x = 0;
		point.y += img->scale;
	}
	drawline((int []){img->player.x + 10 / 2, img->player.y + img->scale / 4,
		img->player.x + 10 / 2 - img->player.mdx * 10, img->player.y
		+ img->scale / 4 - img->player.mdy * 10}, img, 0x735674);
}
