/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/12/11 14:11:05 by jperinch         ###   ########.fr       */
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
	/*movement push keys boolean values*/
	int		mapw;
	int		move_w;
	int		move_s;
	int		move_a;
	int		move_d;
	float	lookx;
	float	looky;
	/*end*/
	/*player stuff*/
	coordinate_t player;
	coordinate_t camaera;
	coordinate_t horizontal_points; //rx
	coordinate_t vertical_points;	//rx
	int				dof; 
	int				side;
	float			ra;
	/*end of player stuff*/

	int longest_row;
	int count;
	int line_count;
	int final_c;
	int *lengths;
	int player_count;
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

int		move(t_data *img,float x,float y);
int		ray_starter(t_data *img, int loop);
void ray_range(float *ra);
float horizontal_inter(t_data *img);
int	create_trgb(int t, int r, int g, int b);
float vertical_inter(t_data *img);
int move(t_data *img,float x,float y);
int	move_w(t_data *vars);
int	move_s(t_data *vars);
int	move_a(t_data *vars);
int	move_d(t_data *vars);

int		moves(int keycode, t_data *vars);
int		*get_numbers(char *line, t_data *canva, int row_num);
float	radiansfd(float angle);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	drawline(int *vals, t_data *img, int *color_list);
void	ray(t_data *img);
void	wall(t_data *img);
void	tile(t_data *img);
void	player(t_data *img);
void	validate_zeroes(int **map, t_data *canva);
void	validate_spaces(int **map, t_data *canva);
void	error_free(t_data *canva, int fd, char *msg);
char	*validate_textures(t_data *canva, int fd);

#endif
