/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:09:58 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 13:32:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	radiansfd(float angle)
{
	return (angle * PI / 180.0f);
}

void	texture_render(t_data *img, t_ray *ray, int x)
{
	double	texpos;
	int		texy;

	texy = 0;
	texpos = (ray->drawstart - img->height / 2 + ray->lineheight / 2) * ray->dy;
	while (ray->lo < ray->drawend)
	{
		texy = (int)texpos;
		texpos += ray->dy;
		my_mlx_pixel_put(img, x, ray->lo + 1, img->texture2[ray->idx].addr[(texy
				* img->texture2[ray->idx].img_hei / 4 + (ray->color))]);
		ray->lo += 1;
	}
}

void	texture_calc(t_data *img, t_ray *ray, int x)
{
	ray->wallx = 0;
	ray->perpdis = 0;
	if (ray->side == 0)
	{
		ray->perpdis = (ray->sidedis.x - ray->deltadis.x);
		ray->wallx = ray->pos.y + ray->perpdis * ray->raydir.y;
	}
	else
	{
		ray->perpdis = (ray->sidedis.y - ray->deltadis.y);
		ray->wallx = ray->pos.x + ray->perpdis * ray->raydir.x;
	}
	ray->wallx -= floor((ray->wallx));
	ray->lineheight = 0;
	ray->lineheight = (int)(img->height / ray->perpdis);
	ray->drawstart = img->height / 2 - ray->lineheight / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + img->height / 2;
	if (ray->drawend >= img->height)
		ray->drawend = img->height - 1;
	ray->color = floor(ray->wallx * 64);
	ray->lo = ray->drawstart;
	ray->dy = (64.0) / (ray->lineheight);
	texture_render(img, ray, x);
}

void	idxset(t_data *img, t_ray *ray, int flag)
{
	if (flag == 0)
	{
		if (ray->y >= 0 && ray->x + 1 >= 0 && ray->x + 1 < img->longest_row
			&& ray->y < img->final_c && img->map[ray->y][ray->x + 1] != 1
			&& ray->raydir.x < 0)
			ray->idx = 2;
		else
			ray->idx = 3;
	}
	else
	{
		if (ray->x >= 0 && ray->y - 1 >= 0 && ray->x < img->longest_row
			&& ray->y - 1 < img->final_c && img->map[ray->y - 1][ray->x] != 1
			&& ray->raydir.y > 0)
			ray->idx = 1;
		else
			ray->idx = 0;
	}
}
