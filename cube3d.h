/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathmanazmeen <fathmanazmeen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/12/10 12:46:05 by fathmanazme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
# include "mlx/mlx.h"
// # include "minilibx-linux/mlx.h"
// # include "minilibx-linux/mlx_int.h"
# include "mlx/mlx.h"
#define PI 3.1415926535
#define DR 0.0174533
typedef struct point3d
{
    double x;
    double y;
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
	int		**map;
	int		maph;
	int		scale;
	int		fov;
	int		mapw;
	int		move_w;
	int		move_s;
	int		move_a;
	int		move_d;
	float	lookx;
	float	looky;
	int longest_row;
	int count;
	int line_count;
	int final_c;
	int *lengths;
	int player_count;
	coordinate_t player;
	char *tex[4];
	int floor[3];
	int flag[6];
	int ceil[3];
	int first_lines;
	int cx;
	int cy;
}	t_data;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	error;
	double	e2;
}	t_line;

#endif
