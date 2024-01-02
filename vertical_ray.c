/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:52:19 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 13:32:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_vertical(t_data *img, float tan)
{
	if (cos(radiansfd(img->ra)) > 0.001)
	{
		img->verticalp.x = (((int)(img->player.x + 10 / 2) / img->scale)
				* img->scale) - 0.0001;
		img->verticalp.y = ((img->player.x + 10 / 2) - img->verticalp.x) * tan
			+ (img->player.y + img->scale / 4);
		img->verticalp.dx = -img->scale;
		img->verticalp.dy = -img->verticalp.dx * tan;
	}
	else if (cos(radiansfd(img->ra)) < -0.001)
	{
		img->verticalp.x = (((int)(img->player.x + 10 / 2) / img->scale)
				* img->scale) + img->scale;
		img->verticalp.y = ((img->player.x + 10 / 2) - img->verticalp.x) * tan
			+ (img->player.y + img->scale / 4);
		img->verticalp.dx = img->scale;
		img->verticalp.dy = -img->verticalp.dx * tan;
	}
	else
	{
		img->verticalp.x = (img->player.x + 10 / 2);
		img->verticalp.y = (img->player.y + img->scale / 4);
		img->dof = img->longest_row - 1;
	}
}

/*horizontal intersection using step method*/
float	vertical_inter(t_data *img, int mx, int my)
{
	float	tan2;

	img->ra = fixang(img->ra);
	tan2 = -tan(radiansfd(img->ra));
	img->dof = 0;
	ray_vertical(img, tan2);
	while (img->dof < img->longest_row)
	{
		mx = (int)(img->verticalp.x) / img->scale;
		my = (int)(img->verticalp.y) / img->scale;
		if ((mx < img->longest_row && mx >= 0 && my < img->final_c && my >= 0
				&& img->map[my][mx] == 1))
		{
			img->dof = img->longest_row;
		}
		else
		{
			img->verticalp.x += img->verticalp.dx;
			img->verticalp.y += img->verticalp.dy;
			img->dof += 1;
		}
	}
	return (sqrt(pow(img->verticalp.x - (img->player.x + 10 / 2), 2)
			+ pow(img->verticalp.y - (img->player.y + img->scale / 4), 2)));
}
