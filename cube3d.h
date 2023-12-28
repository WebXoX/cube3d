/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/12/28 20:11:18 by afarheen         ###   ########.fr       */
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

typedef struct	s_tex {
	void	*img;
	int	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int img_wid;
	int img_hei;
}				t_tex;

typedef struct point3d
{
    double x;
    double y;
    float z;
    float dx;
    float dy;
    float da;
}   coordinate_t;


typedef struct ray
{
	coordinate_t	pos;
	coordinate_t	dir;
	coordinate_t	raydir;
	coordinate_t	cam;
	coordinate_t	sidedis;
	coordinate_t	deltadis;
	int				x;
	int				y;
	int				stepx;
	int				stepy;
	int				side;
	int				hit;
	int				idx;
}   ray_t;


typedef struct moves
{
    int		w;
	int		s;
	int		a;
	int		d;
	int		l;
	int		r;
}   move_t;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_bytes;
	int				endian;
	int				width;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	int				**map;
	int				maph;
	int				scale;
	/*movement push keys boolean values*/
	int				mapw;
	move_t  		move;
	float			lookx;
	float			looky;
	/*end*/
	/*player stuff*/
	coordinate_t	player;
	coordinate_t	camaera;
	ray_t			ray;
	// coordinate_t horizontal_points; //rx
	// coordinate_t vertical_points;	//rx
	// int				dof;
	// int				side;
	// float			ra;
	int directionstart;
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
	t_tex texture;
	t_tex texture2[4];
	double cx;
	double cy;
	int fd;
	char **cur_line;
	char **cur_tex;
}	t_data;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	error;
	double	e2;
}	t_line;


float FixAng(float a);
int		ray_starter(t_data *img, int loop);
void ray_range(float *ra);
float horizontal_inter(t_data *img);
int	create_trgb(int t, int r, int g, int b);
float vertical_inter(t_data *img);
int move(t_data *img);
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
