/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:06:28 by afarheen          #+#    #+#             */
/*   Updated: 2024/01/02 14:04:56 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

char	*join_all(char **rgb)
{
	int		i;
	char	*new;
	char	*oldnew;

	i = 0;
	new = ft_strdup("");
	while (rgb[i])
	{
		oldnew = new;
		new = ft_strjoin(new, rgb[i++]);
		free(oldnew);
	}
	return (new);
}

int	num_valid(char *str, int i, int num_count)
{
	while (str[i + num_count])
	{
		if (ft_isdigit(str[i + num_count]))
			num_count++;
		else
			break ;
	}
	return (num_count);
}

int	extract_num(char *str, t_data *canva, int val, char type)
{
	int	i;
	int	num_count;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	num_count = num_valid(str, i, 0);
	i = i + num_count;
	if (num_count > 3 || (str[i] && (!ft_isspace(str[i]) && str[i] != ','))
		|| num_count == 0)
		error_free(canva, 1, "Error: RGB values are incorrect\n");
	if (type == 'F' && ft_atoi(str) <= 255)
		canva->floor[val] = ft_atoi(str);
	else if (type == 'C' && ft_atoi(str) <= 255)
		canva->ceil[val] = ft_atoi(str);
	else
		error_free(canva, 1, "Error: RGB values are incorrect\n");
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == ',')
		return (i + 1);
	else if (val != 2)
		error_free(canva, 1, "Error: RGB values are incorrect\n");
	return (i);
}

void	extract_rgb(char *tex, t_data *canva)
{
	int	index;

	if (tex[1] && ft_isspace(tex[1]))
	{
		index = extract_num(&tex[1], canva, 0, tex[0]);
		index += extract_num(&tex[index + 1], canva, 1, tex[0]);
		if (tex[index])
			index += extract_num(&tex[index + 1], canva, 2, tex[0]);
		if (tex[index + 1] || tex[index] == ',')
			error_free(canva, 1, "Error: RGB values are incorrect\n");
	}
	else
		error_free(canva, 1, "Error: RGB values are incorrect\n");
}

void	add_ceil_floor(char *tex, t_data *canva)
{
	int	fd;

	if (tex[0] == 'C' && !canva->flag[5])
		canva->flag[5] = 1;
	else if (tex[0] == 'F' && !canva->flag[4])
		canva->flag[4] = 1;
	else
		error_free(canva, 1, "Error: Repeated Ceiling or floor\n");
	extract_rgb(tex, canva);
}
