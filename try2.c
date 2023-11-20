/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/11/16 17:07:00 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.1415926535
#include "cube3d.h"
int	move(t_data *img,float x,float y);
void	drawline(int *vals, t_data *img, int *color_list);
void ray(t_data *img);




int	moves(int keycode, t_data *vars)
{
	printf("keycode :: %d\n",keycode);
	if (keycode == 13 || keycode == 119)
	{
		vars->player.x += vars->player.dx; 
		vars->player.y += vars->player.dy; 
		
		move(vars,0,5);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 1|| keycode == 115)
	{
		vars->player.x -= vars->player.dx; 
		vars->player.y -= vars->player.dy; 
		
		move(vars,0,-5);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		
		return (1);
	}
    else if (keycode == 0|| keycode == 97)
	{
		vars->player.da -=0.1;
		if (vars->player.da < 0)
		{
			vars->player.da += 2*PI;
		}
		vars->player.dx = cos(vars->player.da)*5;
		vars->player.dy = sin(vars->player.da)*5;
		move(vars,5,0);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
    else if (keycode == 2|| keycode == 100)
	{
		vars->player.da +=0.1;
		if (vars->player.da >2*PI)
		{
			vars->player.da -= 2*PI;
		}
		vars->player.dx = cos(vars->player.da)*5;
		vars->player.dy = sin(vars->player.da)*5;
		move(vars,-5,0);
		mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		return (1);
	}
	if (keycode < 0)
		exit(1);
	return (0);
}
void ray(t_data *img)
{
	int map[24]={1,1,1,1,1,1,1,0,1,0,0,1,1,0,2,0,0,1,1,1,1,1,1,1};
	int r,mx,my,mp,dof;
	float rx,ry,ra,xo,yo;
	ra = img->player.da;
	for (r = 0; r < 1; r++)
	{
		/* code */
		dof=0;
		float aTan = -1/tan(ra);
		if(ra > PI)
		{
			ry=(((int)img->player.y >>6)<<6)-0.0001;
			rx=  (img->player.y-ry)*aTan+img->player.x;
			yo=-64;
			xo=yo*aTan;
		}
		if(ra < PI)
		{
			ry=(((int)img->player.y >>6)<<6)+64;
			rx=  (img->player.y-ry)*aTan+img->player.x;
			yo=64;
			xo=yo*aTan;
		}
		if(ra==0||ra==PI)
		{
			ry=img->player.y;
			rx= img->player.x;
			dof=8;
		}
		while (dof<8)
		{
			mx=(int)(rx)>>6;
			my=(int)(ry)>>6;
			mp=my*6*mx;
			if(mp<4*6 &&map[mp]==1)
				dof=8;
			else
			{
				rx+=xo;
				ry+=yo;
				dof+=1;
			}
		}
		drawline((int []){img->player.x,img->player.y,rx,ry},img,(int[]){0xFf0000});
		
	}
	
}
void	run(t_data *canva)
{
	mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
		0);
		mlx_hook(canva->win_ptr, 2, 1L << 1, moves, &(*canva));
	mlx_key_hook(canva->win_ptr, moves, &(*canva));
	mlx_loop(canva->mlx_ptr);
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

int cast(t_data *canva)
{
	float x1 = 0;
	float x2 = 0;
	float dir_x = -10;
    float dir_y = 0;
	float y1 = canva->height;
	float y2 = canva->width;

	float x3 = canva->player.x;
	float y3 = canva->player.y;
	float x4 = canva->player.x + dir_x;
	float y4 = canva->player.y + dir_y;

	// printf("HEREEEEEE %f %f %f %f \n", x3, x4, y3, y4);
	// drawline((int[]){0,0,400,800},canva,(int[]){0x880808});
	// drawline((int[]){x3,y3,x4,y4},canva,(int[]){0x880808});
	float den = (((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
	if (den == 0)
		return 0;
	float t = (((x1-x3) * (y3-y4)) - ((y1 - y3) * (x3 - x4)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
	float u = (((x1-x3) * (y1-y2)) - ((y1 - y3) * (x1 - x2)))/(((x1-x2) * (y3-y4)) - ((y1 - y2) * (x3 - x4)));
	if(t >= 0 && t <= 1 && u >= 0 && u >= 0)
		return 1;
	else
		return 0;
}

void render(t_data *img)
{
    int i   =   0;
    int j   =   0;
int map[4][6] = {   {1,1,1,1,1,1},
					{1,0,1,0,0,1},
					{1,0,2,0,0,1},
					{1,1,1,1,1,1}   };
    coordinate_t    point;
    point.x =    0;
    point.y =    0;
    int ratio_y = img->height/4;
    int ratio_x = img->width/6;
	 while (i < 4)
    {
        j=0;
        while (j < 6)
        {
                int c = 0;
                    while (c < ratio_y - 10)
                    {
                        drawline((int[]){point.x ,point.y + c ,point.x
                                + ratio_x-10 ,point.y + c} , img, (int[]){0x00});
                        c++;
                    }
            point.x+=ratio_x;
            j++;
        }
        point.x=0;
        point.y+=ratio_y;
        i++;
    }
	i=0;
	j=0;
        point.x=0;
        point.y=0;

    while (i < 4)
    {
        j=0;
        while (j < 6)
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
				if(map[i][j] == 0)
                {
                    while (c < ratio_y - 10)
                    {
                        drawline((int[]){point.x ,point.y + c ,point.x
                                + ratio_x-10 ,point.y + c} , img, (int[]){0x00});
                        c++;
                    }
                }
				//draw player
                if(map[i][j] == 2)
                {
					img->player.x = point.x  + ratio_x/2;
					img->player.y = point.y  + ratio_y/2;
					// point.x += ratio_x/2;
					// point.y += ratio_y/2;
				    int cs = 0;
					// img->player.y = point.y ;
                    while (cs <10)
                    {
						// printf("in player y:%f  %f\n",point.y, img->player.y);
						// printf("in player x:%f  %f\n",point.x, img->player.x);
                        drawline((int[]){img->player.x ,img->player.y + cs ,img->player.x+ 10 ,img->player.y + cs} ,img,(int[]){0xFFFFFFF});
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
	drawline((int[]){img->player.x,img->player.y,img->player.x -img->player.dx*5,img->player.y-img->player.dy *5},img,(int[]){0xFFFFFFF});
	printf("THE ANSWER IS: %d\n", cast(img));
	ray(img);
    run(&(*img));
}


int	move(t_data *img,float x, float y)
{
	int i = 0;
	 int ratio_y = img->height/8;
    int ratio_x = img->width/8;
	printf("in player y:%f\n",img->player.y);
	printf("in player x:%f\n", img->player.x);
	drawline((int[]){img->player.x,img->player.y,img->player.x -img->player.dx*5,img->player.y-img->player.dy *5},img,(int[]){0x0000});

	// drawline((int[]){img->player.x,img->player.y,img->player.x+3,img->player.y},img,(int[]){0x000});

	// drawline((int[]){img->player.x,img->player.y  ,img->player.x - 10 ,img->player.y },img,(int[]){0x000});
	while (i <10)
	{
		//draw over old pos
		drawline((int[]){img->player.x  ,img->player.y + i ,img->player.x + 10  ,img->player.y + i },img,(int[]){0x000});
		i++;
	}
	// drawline((int[]){img->player.x,img->player.y,img->player.x+3,img->player.y},img,(int[]){0xFFFFFFF});
	img->player.y -= y;
	img->player.x -= x;
	i=0;


			printf("in player x:%f\n", img->player.x);
			printf("in player y:%f\n",img->player.y);
	drawline((int[]){img->player.x,img->player.y,img->player.x -img->player.dx*5,img->player.y-img->player.dy *5},img,(int[]){0xFFFFFFF});

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
void map(t_data *img)
{
	int ratio_y = img->height/4;
    int ratio_x = img->width/6;
	int i=0;
	while (i < img->height)
	{
		
		drawline((int[]){0,i ,img->width ,i} ,img, (int[]){0x880});
		i++;
	}
	int j;
	i=0;
	int x;
	// int y;
	//  while (i < 4)
    // {
    //     j=0;
    //     while (j < 6)
    //     {
    //             int c = 0;
	// 			//draw map
            
    //                 while (c < ratio_y - 10)
    //                 {
    //                     drawline((int[]){x ,y + c ,x
    //                             + ratio_x-10 ,y + c} , img, (int[]){0x00});
    //                     c++;
    //                 }
	// 			j++;
	// 			x+=ratio_x;
    //             }
    //     i++;
	// 	y+=ratio_y;
    //     }
	// // run(img);
	
}

void	call(t_data *canva)
{
	int		status;

	canva->img = mlx_new_image(canva->mlx_ptr, canva->width, canva->height);
	canva->addr = mlx_get_data_addr(canva->img, &canva->bpp,
			&canva->line_bytes, &canva->endian);
	canva->win_ptr = mlx_new_window(canva->mlx_ptr, canva->width, canva->height,
				"cub3d");
	map(canva);
	render(canva);
}

int	main(int argv, char *argc[])
{

	t_data	canva;
	canva.height = 800;
	canva.width = 1000;
	canva.mlx_ptr = mlx_init();
	call( &canva);
	return (0);
}
