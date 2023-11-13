/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/07/13 10:41:05 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int	move(t_data *img,float x,float y);

int	moves(int keycode, t_data *vars)
{
	printf("keycode :: %d\n",keycode);
	if (keycode == 13 || keycode == 119)
	{
		move(vars,0,5);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 1|| keycode == 115)
	{
		move(vars,0,-5);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 0|| keycode == 97)
	{
		move(vars,5,0);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 2|| keycode == 100)
	{
		move(vars,-5,0);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
	if (keycode < 0)
		exit(1);
	return (0);
}
void	run(t_data *canva)
{
	mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
		0);
	mlx_key_hook(canva->win_ptr, moves, &(*canva));
	mlx_loop(canva->mlx_ptr);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
void drawline(float x, float y, float x1, float y1,t_data img, void *mlx_win,int color)
{
    float m = (y1-y)/(x1-x);
    float x2 = x ;
    float y2 = y;
    while (x2<x1)
    {
        my_mlx_pixel_put(&img,x2,y2,color); 
        x2 = x2 + 0.001;
        y2 = m*(x2-x)+y;
    }
}
void render(t_data *img)
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
                if(map[i][j] == 1)
                {
                    while (c < ratio_y - 10)
                    {
                        drawline(point.x ,point.y + c ,point.x 
                                + ratio_x-10 ,point.y + c , *img, img->win_ptr,0xFFFFFFF);
                        c++;
                    }
                }
                if(map[i][j] == 2)
                {
					img->player.x = point.x;
					img->player.y = point.y;
				    int cs = 0;
                    while (cs <10)
                    {
						// printf("in player y:%f  %f\n",point.y, img->player.y);
						// printf("in player x:%f  %f\n",point.x, img->player.x);
                        drawline(point.x  + ratio_x/2,point.y + cs ,point.x + 10  + ratio_x/2,point.y + cs ,*img,img->win_ptr,0xFFFFFFF);
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
    run(&(*img));
}
int	move(t_data *img,float x, float y)
{
	int i = 0;
	 int ratio_y = img->height/8; 
    int ratio_x = img->width/8; 
			printf("in player y:%f\n",img->player.y);
			printf("in player x:%f\n", img->player.x);
	while (i <10)
	{
		drawline(img->player.x  + ratio_x,img->player.y + i ,img->player.x + 10  + ratio_x,img->player.y + i ,*img,img->win_ptr,0x000);
		i++;
	}
	img->player.y -= y;
	img->player.x -= x;
	i=0;
			printf("in player x:%f\n", img->player.x);
			printf("in player y:%f\n",img->player.y);
	while (i <10)
	{
		drawline(img->player.x  + ratio_x ,img->player.y + i ,img->player.x + 10  + ratio_x ,img->player.y + i ,*img,img->win_ptr,0xFFFFFFF);
		i++;
	}
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
	render(canva);
}

int	main(int argv, char *argc[])
{
	
	t_data	canva;	 
	canva.height = 200;
	canva.width = 400;
	canva.mlx_ptr = mlx_init();
	call( &canva);
	return (0);
}
