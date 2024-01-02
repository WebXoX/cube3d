/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:55 by afarheen          #+#    #+#             */
/*   Updated: 2024/01/02 13:32:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
