/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/11/22 11:15:54 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int	move(t_data *img,float x,float y, char rot);
int	moves(int keycode, t_data *vars);
void render(t_data *img, char ctxt);
void call(t_data *img);


void	run(t_data *canva)
{
	mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
		0);
		mlx_hook(canva->win_ptr, 2, 1L << 1, moves, &(*canva));
	mlx_loop(canva->mlx_ptr);
}


int	moves(int keycode, t_data *vars)
{
	printf("keycode :: %d\n",keycode);
	if (keycode == 13 || keycode == 119)
	{
		move(vars,0,5, 0);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 1|| keycode == 115)
	{
		move(vars,0,-5, 0);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 0|| keycode == 97)
	{
		float x =  vars->dir_x * cos(5 * (M_PI/180)) - vars->dir_y *sin(5* (M_PI/180)) ;
		float y= vars->dir_y * cos(5* (M_PI/180)) + vars->dir_x *sin(5* (M_PI/180));
		move(vars, x, y, 1);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 2|| keycode == 100)
	{
		float x =  vars->dir_x * cos(-5 * (M_PI/180)) - vars->dir_y *sin(-5* (M_PI/180)) ;
		float y = vars->dir_y * cos(-5* (M_PI/180)) + vars->dir_x *sin(-5* (M_PI/180));
		move(vars, x, y, 1);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
	if (keycode < 0)
		exit(1);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((data->width > x && data->height > y) && (0 <= x && 0 <= y))
	{
		dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

// void drawline(float x, float y, float x1, float y1,t_data img, void *mlx_win,int color)
// {
//     float m = (y1-y)/(x1-x);
//     float x2 = x ;
//     float y2 = y;
// 	if(x2 <= x1)
// 	{
// 		while (x2<=x1)
// 		{
// 			my_mlx_pixel_put(&img,x2,y2,color);
// 			x2 = x2 + 0.001;
// 			y2 = m * (x2-x)+y;
// 		}
// 	}
// 	// else
// 	// {
// 	// 	float x2 = x1 ;
//     // 	float y2 = y1;
// 	// 	while (x2<x)
// 	// 	{
// 	// 		my_mlx_pixel_put(&img,x2,y2,color);
// 	// 		x2 = x2 + 0.001;
// 	// 		y2 = m * (x2-x)+y;
// 	// 	}
// 	// }
// }

void	step(int *p2, int *p1, double *error, double dp)
{
	*error = *error + dp;
	if (*p1 < *p2)
		*p1 = *p1 + 1;
	else
		*p1 = *p1 - 1;
}


void	drawline(int *vals, t_data *img, int *color_list)
{
	int	i;
	int color;
	t_line line;

	color = color_list[0];
	line.dx = abs(vals[2] - vals[0]);
	line.dy = -abs(vals[3] - vals[1]);
	line.error = line.dx + line.dy;
	i = 0;
	while (1)
	{
		my_mlx_pixel_put(img, vals[0], vals[1], color);
		if (vals[1] == vals[3] && vals[2] == vals[0])
			break ;
		line.e2 = 2 * line.error;
		if (line.e2 <= line.dx)
		{
			if (vals[3] == vals[1])
				break ;
			step(&vals[3], &vals[1], &(line.error), line.dx);
		}
		if (line.e2 >= line.dy)
		{
			if (vals[0] == vals[2])
				break ;
			step(&vals[2], &vals[0], &(line.error), line.dy);
		}
		i++;
	}
}

// int draw_angles(t_data *canva,int color)
// {
// 		float x1 = 0;
// 	float x2 = canva->width;
// 	// float dir_x = -10;
//     // float dir_y = 0;
// 	float y1 = 0;
// 	float den, t, u;
// 	float y2 = canva->height;

// 	float x3 = canva->player.x + 5;
// 	float y3 = canva->player.y + 5;
// 	int angle;
// 	angle = -45;
// 	while(angle <= 45)
// 	{
// 		float dirx =  canva->dir_x * cos(angle * (M_PI/180)) - canva->dir_y *sin(angle* (M_PI/180)) ;
// 		float diry = canva->dir_y * cos(angle* (M_PI/180)) + canva->dir_x *sin(angle* (M_PI/180));
// 		float x4 = canva->player.x + 5 + dirx;
// 		float y4 = canva->player.y +5 + diry;
// 		den = (((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
// 		if (den == 0)
// 			return 0;
// 		t = (((x1-x3) * (y3-y4)) - ((y1 - y3) * (x3 - x4)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
// 		u = (((x1-x3) * (y1-y2)) - ((y1 - y3) * (x1 - x2)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
// 		angle += 1;
// 		if(t >= 0 && t <= 1 && u >= 0 && u >= 0)
// 		{
// 			x4 = x1 + (t*(x2-x1));
// 			y4 = y1 + (t*(y2-y1));
// 			drawline((int[]){x3,y3,x4,y4},canva,(int[]){color});
// 		}
// 	}
// 	return 0;
// }

int draw_angles(t_data *canva,int color)
{
		float x1 = 0;
	float x2 = canva->width;
	// float dir_x = -10;
    // float dir_y = 0;
	float y1 = 0;
	float den, t, u;
	float y2 = canva->height;

	float x3 = canva->player.x + 5;
	float y3 = canva->player.y + 5;
	int angle;
	angle = -180;
	// while(angle <= 180)
	// {
	// 	float dirx =  canva->dir_x * cos(angle * (M_PI/180)) - canva->dir_y *sin(angle* (M_PI/180)) ;
	// 	float diry = canva->dir_y * cos(angle* (M_PI/180)) + canva->dir_x *sin(angle* (M_PI/180));
		float x4 = canva->player.x + 5 + canva->dir_x;
		float y4 = canva->player.y +5 + canva->dir_y;
		den = (((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
		if (den == 0)
			return 0;
		t = (((x1-x3) * (y3-y4)) - ((y1 - y3) * (x3 - x4)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
		u = (((x1-x3) * (y1-y2)) - ((y1 - y3) * (x1 - x2)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
		// angle += 5;
		if(t >= 0 && t <= 1 && u >= 0 && u >= 0)
		{
			x4 = x1 + (t*(x2-x1));
			y4 = y1 + (t*(y2-y1));
			drawline((int[]){x3,y3,x4,y4},canva,(int[]){color});
		}
	// }
	return 0;
}


int cast(t_data *canva)
{
	float x1 = 0;
	float x2 = canva->width;
	// float dir_x = -10;
    // float dir_y = 0;
	float y1 = 0;
	float den, t, u;
	float y2 = canva->height;



	float x3 = canva->player.x + 5;
	float y3 = canva->player.y + 5;


	// printf("HEREEEEEE %f %f %f %f \n", x3, x4, y3, y4);
	drawline((int[]){x1,y1,x2,y2},canva,(int[]){0x880808});//{x1,y1,x2,y2}
	draw_angles(canva, 0x880808);
		return 0;
}

void render(t_data *img, char ctxt)
{
    int i   =   0;
    int j   =   0;
int map[4][4] = {   {1,1,1,1},
                        {1,0,0,1},
                        {1,0,2,1},
                        {1,1,1,1}   };
    coordinate_t    point;
    point.x =    0;
    point.y =    0;
    int ratio_y = img->height/4;
    int ratio_x = img->width/4;
    while (i < 4)
    {
        j=0;
        while (j < 4)
        {
                int c = 0;
				//draw map
                if(map[i][j] == 1)
                {
                    while (c < ratio_y - 10)
                    {
                        drawline((int[]){point.x ,point.y + c ,point.x
                                + ratio_x-10 ,point.y + c} , img, (int[]){0xFFFFFFF});
                        c++;
                    }
                }
				//draw player
                if(map[i][j] == 2 && ctxt == 0)
                {
					img->player.x = point.x  + ratio_x/2;
				    int cs = 0;
					img->player.y = point.y ;
                    while (cs <10)
                    {
						// printf("in player y:%f  %f\n",point.y, img->player.y);
						// printf("in player x:%f  %f\n",point.x, img->player.x);
                        drawline((int[]){point.x  + ratio_x/2,point.y + cs ,point.x + 10  + ratio_x/2,point.y + cs} ,img,(int[]){0xFFFFFFF});
                        cs++;
                    }
                }
            printf("x:%f\n",point.x);
            printf("y:%f\n",point.y);
            point.x+=ratio_x;
            j++;
        }
        point.x=0;
        point.y+=ratio_y;
        i++;
    }
	printf("THE ANSWER IS: %d\n", cast(img));
	if(ctxt == 0)
    	run(&(*img));
}


int	move(t_data *img,float x, float y, char rot)
{
	int i = 0;
	 int ratio_y = img->height/8;
    int ratio_x = img->width/8;
			printf("in player y:%f\n",img->player.y);
			printf("in player x:%f\n", img->player.x);
	// drawline((int[]){img->player.x + 5,img->player.y +5  ,img->player.x +5 +img->dir_x ,img->player.y + 5+img->dir_y},img,(int[]){0x000});
	// while (i <10)
	// {
	// 	//draw over old pos
	// 	drawline((int[]){img->player.x  ,img->player.y + i ,img->player.x + 10  ,img->player.y + i },img,(int[]){0x000});
	// 	i++;
	// }
	if(rot)
	{
		img->dir_x = x;
		img->dir_y = y;
	}
	else
	{
		img->player.y -= y;
		img->player.x -= x;
	}
	img->img = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_bytes, &img->endian);
	render(img, 1);
	i=0;
			printf("in player x:%f\n", img->player.x);
			printf("in player y:%f\n",img->player.y);
	while (i <10)
	{
		//draw new pos
		drawline((int[]){img->player.x ,img->player.y + i ,img->player.x + 10 ,img->player.y + i} ,img, (int[]){0xFFFFFFF});
		i++;
	}
	printf("THE ANSWER IS: %d\n", cast(img));
    run(img);
	return (0);
}

void	call(t_data *canva)
{
	int		status;


	canva->img = mlx_new_image(canva->mlx_ptr, canva->width, canva->height);
	canva->addr = mlx_get_data_addr(canva->img, &canva->bpp,
			&canva->line_bytes, &canva->endian);
	canva->win_ptr = mlx_new_window(canva->mlx_ptr, canva->width, canva->height,
				"cub3d");
}

int	main(int argv, char *argc[])
{

	t_data	canva;
	canva.height = 800;
	canva.width = 400;
	canva.dir_x = -10;
	canva.dir_y = 0;
	canva.mlx_ptr = mlx_init();
	call( &canva);
	render(&canva, 0);
	return (0);
}
