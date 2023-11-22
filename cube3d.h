/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/11/22 11:08:34 by afarheen         ###   ########.fr       */
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
    float dx;
    float dy;
    float da;
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
	void	*mlx_ptr;
	void	*win_ptr;
	int		map[4][4];
		float	dir_x;
	float	dir_y;
	float	lookx;
	float	looky;
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