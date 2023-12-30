#include "cube3d.h"

void	run(t_data *canva)
{
	mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0, 0);
	mlx_hook(canva->win_ptr, 2, 1L << 0, moves, &(*canva));
	mlx_hook(canva->win_ptr, 3, 1L << 1, moves, &(*canva));
	mlx_loop(canva->mlx_ptr);
}

int	move(t_data *img)
{
	int	i;

	i = 0;
	while (i < img->height)
	{
		if (i < img->height / 2)
			drawline((int []){0, i, img->width, i}, img, (int [])
			{create_trgb(0, img->ceil[0], img->ceil[1], img->ceil[2])});
		else
			drawline((int []){0, i, img->width, i}, img, (int [])
			{create_trgb(0, img->floor[0], img->floor[1], img->floor[2])});
		i++;
	}
	ray(img);
	tile(img);
	ray_starter(img, 120);
	wall(img);
	player(img);
	run(img);
	return (1);
}

void	init_struct(t_data *canva)
{
	int	i;

	i = -1;
	canva->longest_row = 0;
	canva->cur_tex = 0;
	canva->cur_line = 0;
	ft_bzero(canva->tex, 4);
	while (++i < 6)
		canva->flag[i] = 0;
	i = -1;
	while (++i < 4)
		canva->texture2[i].img = 0;
	canva->map = 0;
	canva->player_count = 0;
	canva->final_c = 0;
	canva->first_lines = 0;
	canva->player_count = 0;
	canva->player.dx = 0;
	canva->player.dy = 0;
	canva->camaera.x = 0;
	canva->camaera.y = 0;
	canva->height = 1020;
	canva->width = 1060;
	canva->scale = 8;
	canva->player.da = 90.0f * PI / 180.0f;
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
			drawline((int []){0, i, img->width, i}, img, (int [])
			{create_trgb(0, img->ceil[0], img->ceil[1], img->ceil[2])});
		else
			drawline((int []){0, i, img->width, i}, img, (int [])
			{create_trgb(0, img->floor[0], img->floor[1], img->floor[2])});
		i++;
	}
	ray(img);
	wall(img);
	tile(img);
	player(img);
	run(img);
}

char	*new_line_check(char *line, t_data *canva)
{
	while (line)
	{
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			line = get_next_line(canva->fd);
			canva->cur_line = &line;
		}
		else
			error_free(canva, 1, "Error: lines between map!\n");
	}
	return (line);
}

void	map_first_check(char *line, t_data *canva)
{
	int	length;
	int	line_count;

	line_count = 0;
	while (line)
	{
		canva->cur_line = &line;
		if (ft_strcmp(line, "\n") == 0)
			line = new_line_check(line, canva);
		else
		{
			length = ft_strlen(line) - 1;
			if (length > canva->longest_row)
				canva->longest_row = length;
			free(line);
			line = get_next_line(canva->fd);
			line_count++;
		}
	}
	canva->cur_line = 0;
	close(canva->fd);
	canva->map = ft_calloc(sizeof(int *), line_count);
}

char	*add_to_map(char *line, t_data *canva)
{
	char	*nl_pos;

	nl_pos = ft_strchr(line, '\n');
	if (nl_pos)
		nl_pos[0] = 0;
	canva->map[canva->final_c] = get_numbers(line, canva, canva->final_c);
	free(line);
	line = get_next_line(canva->fd);
	canva->final_c++;
	return (line);
}

void	map_filling(t_data *canva, char *file)
{
	char	*line;
	int		i;

	i = 0;
	canva->fd = open(file, O_RDWR);
	line = get_next_line(canva->fd);
	while (line)
	{
		canva->cur_line = &line;
		if (i++ < canva->first_lines || ft_strcmp(line, "\n") == 0)
		{
			free(line);
			line = get_next_line(canva->fd);
		}
		else if (line)
			line = add_to_map(line, canva);
	}
	canva->cur_line = 0;
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
