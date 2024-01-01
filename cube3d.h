/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathmanazmeen <fathmanazmeen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/12/31 18:20:27 by fathmanazme      ###   ########.fr       */
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
	float mdx;
    float mdy;
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
	double			fov;
	double			perpdis;
	float			lo;
	float			dy;
	int				x;
	int				y;
	int				stepx;
	int				stepy;
	int				side;
	int				hit;
	int				idx;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				color;
	double			wallx;
	int				wally;
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
	void			*mlx_ptr;
	void			*win_ptr;
	int				bpp;
	int				line_bytes;
	int				endian;
	int				width;
	int				height;
	int				**map;
	int				scale;
	/*movement push keys boolean values*/
	move_t  		move;
	int				key_m;
	/*end*/
	/*player stuff*/
	coordinate_t	player;
	coordinate_t	camaera;
	coordinate_t 	horizontalp; //rx
	coordinate_t 	verticalp;	//rx
	ray_t			ray;
	int				dof;
	int				side;
	int				directionstart;
	float			ra;
	/*end of player stuff*/

	int				longest_row;
	int				final_c;
	int				player_count;
	int				floor[3];
	int				flag[6];
	int				ceil[3];
	int				first_lines;
	t_tex			texture2[4];
	double			cx;
	double			cy;
	int				fd;
	char			**cur_line;
	char			**cur_tex;
}	t_data;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	error;
	double	e2;
}	t_line;

int		map_key(int keycode,t_data *vars);
int		collisionNS(t_data *C, int i);
char	*join_all(char **rgb);
int		num_valid(char *str, int i, int num_count);
int		extract_num(char *str, t_data *canva, int val, char type);
void	extract_rgb(char *tex, t_data *canva);
void	add_ceil_floor(char *tex, t_data *canva);
void	create_arr(char arr[5][3]);
void	check_valid(char *tex, t_data *canva);
int		check_tex(t_data *canva);
void	condition_check(t_data *canva, char *line, int fd);
int		ft_isspace(char c);
void	error_free(t_data *canva, int fd, char *msg);
void	validate_file(char *file, t_data *canva, int i);
int		tex_len(char **arr);
void	check_vertical(int i, int j, t_data *canva, int **map);
void	check_horizontal(int i, int j, t_data *canva, int **map);
void	validate_zeroes(int **map, t_data *canva);
int		check_surrounding(int i, int j, int **map, t_data *canva);
void	validate_spaces(int **map, t_data *canva);
int		*get_numbers(char *line, t_data *canva, int row_num);
char	*new_line_check(char *line, t_data *canva);
void	map_first_check(char *line, t_data *canva);
char	*add_to_map(char *line, t_data *canva);
void	map_filling(t_data *canva, char *file);
void	init_struct(t_data *canva);
void	validate_zeroes(int **map, t_data *canva);
void	validate_spaces(int **map, t_data *canva);
void	error_free(t_data *canva, int fd, char *msg);
char	*validate_textures(t_data *canva, int fd);

char	*validate_textures(t_data *canva, int fd);
void	set_values(t_data *data, char c);
int		ft_isplayer(char c, t_data *data, int i, int row_num);
// int	ft_isplayer(char c, t_data *data);

float	FixAng(float a);
int		ray_starter(t_data *img, int loop);
void	ray_range(float *ra);
float	horizontal_inter(t_data *img);
int		create_trgb(int t, int r, int g, int b);
float	vertical_inter(t_data *img,int mx,int my);
int		move(t_data *img);
int		move_w(t_data *vars);
int		move_s(t_data *vars);
int		move_a(t_data *vars);
int		move_d(t_data *vars);

int		moves(int keycode, t_data *vars);
int		*get_numbers(char *line, t_data *canva, int row_num);
float	radiansfd(float angle);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	drawline(int *vals, t_data *img, int *color_list);
void	ray(t_data *img);
void	wall(t_data *img);
void	tile(t_data *img);
void	player(t_data *img);

#endif
