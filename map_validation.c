/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:26 by afarheen          #+#    #+#             */
/*   Updated: 2024/01/02 13:32:01 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_vertical(int i, int j, t_data *canva, int **map)
{
	int	k;

	k = i;
	while (k >= 0)
	{
		if (map[k][j] == 1)
			break ;
		k--;
	}
	if (k == -1)
		error_free(canva, -1, "Error: Invalid zero or player position\n");
	k = i;
	while (k < canva->final_c)
	{
		if (j < canva->longest_row && map[k][j] == 1)
			break ;
		k++;
	}
	if (k == canva->final_c)
		error_free(canva, -1, "Error: Invalid zero or player position\n");
}

void	check_horizontal(int i, int j, t_data *canva, int **map)
{
	int	l;

	l = j;
	while (l >= 0)
	{
		if (map[i][l] == 1)
			break ;
		l--;
	}
	if (l == -1)
		error_free(canva, -1, "Error: Invalid zero or player position\n");
	l = j;
	while (l < canva->longest_row)
	{
		if (map[i][l] == 1)
			break ;
		l++;
	}
	if (l == canva->longest_row)
		error_free(canva, -1, "Error: Invalid zero or player position\n");
}

void	validate_zeroes(int **map, t_data *canva)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < canva->final_c)
	{
		j = 0;
		while (j < canva->longest_row)
		{
			if (map[i][j] == 0 || map[i][j] == 2)
			{
				check_vertical(i, j, canva, map);
				check_horizontal(i, j, canva, map);
			}
			j++;
		}
		i++;
	}
}

int	check_surrounding(int i, int j, int **map, t_data *canva)
{
	int	wrong;

	wrong = 0;
	if (i > 0)
		if (!(map[i - 1][j] == 1 || map[i - 1][j] == ' '))
			wrong++;
	if (j + 1 < canva->longest_row)
		if (!(map[i][j + 1] == 1 || map[i][j + 1] == ' '))
			wrong++;
	if (i + 1 < canva->final_c)
		if (!(map[i + 1][j] == 1 || map[i + 1][j] == ' '))
			wrong++;
	if (j > 0)
		if (!(map[i][j - 1] == 1 || map[i][j - 1] == ' '))
			wrong++;
	return (wrong);
}

void	validate_spaces(int **map, t_data *canva)
{
	int	i;
	int	j;

	i = 0;
	while (i < canva->final_c)
	{
		j = 0;
		while (j < canva->longest_row)
		{
			if (map[i][j] == ' ')
			{
				if (check_surrounding(i, j, map, canva))
					error_free(canva, 1, "Error: Invalid spaces\n");
			}
			j++;
		}
		i++;
	}
}
