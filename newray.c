/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:51:49 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 13:32:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

void	ray_init(t_data *data)
{
	data->ray.pos.x = data->cx;
	data->ray.pos.y = data->cy;
	data->ray.dir.x = data->player.dx;
	data->ray.dir.y = data->player.dy;
	data->ray.cam.x = data->camaera.x;
	data->ray.cam.y = data->camaera.y;
	data->ray.x = (int)data->cx;
	data->ray.y = (int)data->cy;
	data->ray.raydir.x = 0;
	data->ray.raydir.y = 0;
	data->ray.sidedis.x = 0.0;
	data->ray.sidedis.y = 0.0;
	data->ray.deltadis.x = 0.0;
	data->ray.deltadis.y = 0.0;
	data->ray.stepx = 0.0;
	data->ray.stepy = 0.0;
	data->ray.hit = 0.0;
	data->ray.side = 0.0;
	data->ray.idx = 0.0;
	data->ray.perpdis = 0;
	data->ray.fov = 0.0;
}

void	ray_steps(t_data *data, int x)
{
	t_ray	*ray;

	ray = &data->ray;
	ray->fov = 2 * x / (double)data->width - 1;
	ray->raydir.x = ray->dir.x + ray->cam.x * ray->fov;
	ray->raydir.y = ray->dir.y + ray->cam.y * ray->fov;
	ray->x = (int)ray->pos.x;
	ray->y = (int)ray->pos.y;
	ray->deltadis.x = fabs(1 / ray->raydir.x);
	ray->deltadis.y = fabs(1 / ray->raydir.y);
	ray->perpdis = 0.0;
}

void	ray_hit(t_data *img, t_ray *ray)
{
	if (ray->sidedis.x < ray->sidedis.y)
	{
		ray->sidedis.x += ray->deltadis.x;
		ray->x += ray->stepx;
		ray->side = 0;
		idxset(img, ray, 0);
	}
	else
	{
		ray->sidedis.y += ray->deltadis.y;
		ray->y += ray->stepy;
		ray->side = 1;
		idxset(img, ray, 1);
	}
	if (ray->x < img->longest_row && ray->x >= 0 && ray->y < img->final_c
		&& ray->y >= 0 && img->map[ray->y][ray->x] == 1)
	{
		ray->hit = 1;
		ray->perpdis = 0;
	}
}

void	raystep_direction(t_data *img, t_ray *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedis.x = (ray->pos.x - ray->x) * ray->deltadis.x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedis.x = (ray->x + 1.0 - ray->pos.x) * ray->deltadis.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->stepy = -1;
		ray->sidedis.y = (ray->pos.y - ray->y) * ray->deltadis.y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedis.y = (ray->y + 1.0 - ray->pos.y) * ray->deltadis.y;
	}
	ray->idx = 0;
	while (ray->hit == 0)
		ray_hit(img, ray);
}

void	ray(t_data *img)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray_init(img);
	ray = &img->ray;
	while (x < img->width)
	{
		ray_steps(img, x);
		ray->stepx = 0.0;
		ray->stepy = 0.0;
		ray->hit = 0.0;
		ray->side = 0.0;
		ray->perpdis = 0.0;
		raystep_direction(img, ray);
		texture_calc(img, ray, x);
		x++;
	}
}
