/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:12:44 by afarheen          #+#    #+#             */
/*   Updated: 2023/11/08 09:25:20 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

void	step(int *p2, int *p1, double *error, double dp)
{
	*error = *error + dp;
	if (*p1 < *p2)
		*p1 = *p1 + 1;
	else
		*p1 = *p1 - 1;
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

/*
vals - x0 y0 x1 y1
E2 is kind of a decision parameter which decies whether we will be stepping
x or y. The step value is determined in the step function whihc goes forward
or backward depending on the value. The values or continuously stepped until
they become equal to the final values.
*/
void	draw_pixels(int *vals, t_data *img, int *color_list)
{
	int	i;
	int color;
	t_line line;

	color = color_list[0];
	line.dx = abs(vals[2] - vals[0]);
	line.dy = -abs(vals[3] - vals[1]);
	line.error = line.dx + line.dy;
	i = 0;
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
		i++;
	}
}

void	ft_free(void **mat, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(mat[i++]);
	free(mat);
}

void inits(t_data **img, void **mlx_ptr, void **win_ptr)
{
	(*img) = calloc(1, sizeof(t_data));
	if (!(*img))
		return ;
	(*img)->mlx_ptr = mlx_ptr;
	(*img)->win_ptr = win_ptr;
	(*img)->width = 1920;
	(*img)->height = 1080;
	*mlx_ptr = mlx_init();
	*win_ptr = mlx_new_window(*mlx_ptr, (*img)->width, (*img)->height, "mlx");
	(*img)->img = mlx_new_image(*mlx_ptr, (*img)->width, (*img)->height);
	(*img)->addr = mlx_get_data_addr((*img)->img, &((*img)->bpp),
			&((*img)->line_bytes), &((*img)->endian));
}

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
	(void) argv;
	if (argc == 1)
	{
		inits(&img, &mlx_ptr, &win_ptr);
		draw_pixels((int[]){1,1,100,100}, img, (int[]){0x00FF0000});

		mlx_put_image_to_window(*(img->mlx_ptr), *(img->win_ptr), img->img, 0, 0);
		mlx_loop(*(img->mlx_ptr));
	}
	else
		write(2, "Error Invalid number of arguments!\n", 35);
	return (0);

}
