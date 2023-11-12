/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/11/12 19:40:31 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

// #include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
# include "mlx/mlx.h"
// # include "minilibx-linux/mlx.h"
// # include "minilibx-linux/mlx_int.h"
# include "mlx/mlx.h"

typedef struct point3d
{
    float x;
    float y;
    float z;
}   coordinate_t;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;
	void	**mlx_ptr;
	void	**win_ptr;
	int		*map;
	coordinate_t player;
}	t_data;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	error;
	double	e2;
}	t_line;

#endif