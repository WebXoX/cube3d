/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:02:09 by afarheen          #+#    #+#             */
/*   Updated: 2024/01/02 12:02:10 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	validate_file(char *file, t_data *canva, int i)
{
	canva->texture2[i].img = mlx_xpm_file_to_image(canva->mlx_ptr, file,
			&canva->texture2[i].img_wid, &canva->texture2[i].img_hei);
	if (canva->texture2[i].img <= 0
		|| ft_strcmp(ft_strstr(file, "."), ".xpm") != 0)
		error_free(canva, 1, "Error: Invalid texture file\n");
	canva->texture2[i].addr = (int *)mlx_get_data_addr(canva->texture2[i].img,
			&canva->texture2[i].bits_per_pixel, &canva->texture2[i].img_hei,
			&canva->texture2[i].endian);
}

int	tex_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	error_free(t_data *canva, int fd, char *msg)
{
	int	i;

	if (fd != -1)
		close(canva->fd);
	if (canva->cur_tex)
		free(*canva->cur_tex);
	if (canva->cur_line)
		free(*canva->cur_line);
	i = -1;
	while (++i < 4)
		if (canva->texture2[i].img != 0)
			mlx_destroy_image(canva->mlx_ptr, canva->texture2[i].img);
	write (2, msg, ft_strlen(msg));
	if (canva->map)
	{
		i = -1;
		while (++i < canva->final_c)
		{
			if (canva->map[i])
				free(canva->map[i]);
		}
		free(canva->map);
	}
	exit(0);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c < 13) || c == 32)
		return (1);
	return (0);
}
