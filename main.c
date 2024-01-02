/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:53:13 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 11:53:13 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	close_win(t_data *vars)
{
	error_free(vars, -1, "Exit\n");
	return (0);
}

void	run(t_data *canva)
{
	mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0, 0);
	mlx_hook(canva->win_ptr, 2, 1L << 0, moves, &(*canva));
	mlx_hook(canva->win_ptr, 3, 1L << 1, moves, &(*canva));
	mlx_key_hook(canva->win_ptr, &map_key, &(*canva));
	mlx_hook(canva->win_ptr, 17, 0, close_win, canva);
	mlx_loop(canva->mlx_ptr);
}

int	move(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->height)
	{
		if (i < img->height / 2)
			drawline((int []){0, i, img->width, i}, img,
			create_trgb(0, img->ceil[0], img->ceil[1], img->ceil[2]));
		else
			drawline((int []){0, i, img->width, i}, img,
			create_trgb(0, img->floor[0], img->floor[1], img->floor[2]));
		i++;
	}

	ray(img);
	if (img->key_m == 1)
    {
		wall(img);
		tile(img);
		player(img);
		ray_starter(img, 120);
    }
	run(img);
	return (1);
}
void	call(t_data *img)
{
	int	status;
	int	i;

	i = -1;
	img->img = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_bytes, &img->endian);
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->width, img->height, "3d");
	img->player.x = (img->scale * img->cx) + img->scale / 4;
	img->player.y = (img->scale * img->cy) + img->scale / 4;
	while (i < img->height)
	{
		if (i < img->height / 2)
			drawline((int []){0, i, img->width, i}, img,
			create_trgb(0, img->ceil[0], img->ceil[1], img->ceil[2]));
		else
			drawline((int []){0, i, img->width, i}, img,
			create_trgb(0, img->floor[0], img->floor[1], img->floor[2]));
		i++;
	}
	ray(img);
	run(img);
}

int	main(int argc, char *argv[])
{
	t_data	canva;
	char	*line;
	int		*numbers;

	if (argc > 1)
	{
		init_struct(&canva);
		canva.fd = open(argv[1], O_RDWR);
		if (canva.fd < 0 || ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") != 0)
			error_free(&canva, -1, "Error: Invalid file\n");
		line = validate_textures(&canva, canva.fd);
		map_first_check(line, &canva);
		map_filling(&canva, argv[1]);
		close(canva.fd);
		if (!(canva.player_count))
			error_free(&canva, -1, "Error: no player present!\n");
		validate_zeroes(canva.map, &canva);
		validate_spaces(canva.map, &canva);
		call(&canva);
	}
	return (0);
}
