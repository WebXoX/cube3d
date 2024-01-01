#include "cube3d.h"
#include <math.h>

float	radiansfd(float angle)
{
	return (angle * PI / 180.0f);
}

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
	ray_t	*ray;

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
void	idxset(t_data *img, ray_t *ray, int flag)
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
void	ray_hit(t_data *img, ray_t *ray)
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

void	raystep_direction(t_data *img, ray_t *ray)
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

void	texture_render(t_data *img, ray_t *ray, int x)
{
	double	texPos;
	int		texy;

	texy = 0;
	texPos = (ray->drawStart - img->height / 2 + ray->lineHeight / 2) * ray->dy;
	while (ray->lo < ray->drawEnd)
	{
		texy = (int)texPos;
		texPos += ray->dy;
		my_mlx_pixel_put(img, x, ray->lo + 1, img->texture2[ray->idx].addr[(texy
				* img->texture2[ray->idx].img_hei / 4 + (ray->color))]);
		ray->lo += 1;
	}
}

void	texture_calc(t_data *img, ray_t *ray, int x)
{
	ray->wallx = 0;
	ray->perpdis = 0;
	if (ray->side == 0)
	{
		ray->perpdis = (ray->sidedis.x - ray->deltadis.x); //* cos(ray->fov);
		ray->wallx = ray->pos.y + ray->perpdis * ray->raydir.y;
	}
	else
	{
		ray->perpdis = (ray->sidedis.y - ray->deltadis.y); //* cos(ray->fov);
		ray->wallx = ray->pos.x + ray->perpdis * ray->raydir.x;
	}
	ray->wallx -= floor((ray->wallx));
	ray->lineHeight = 0;
	ray->lineHeight = (int)(img->height / ray->perpdis);
	ray->drawStart = img->height / 2 - ray->lineHeight / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + img->height / 2;
	if (ray->drawEnd >= img->height)
		ray->drawEnd = img->height - 1;
	ray->color = floor(ray->wallx * 64);
	ray->lo = ray->drawStart;
	ray->dy = (64.0) / (ray->lineHeight);
	ray->lo = ray->drawStart;
	texture_render(img, ray, x);
}

void	ray(t_data *img)
{
	ray_t	*ray;
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
