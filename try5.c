/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:12:05 by jperinch          #+#    #+#             */
/*   Updated: 2023/11/30 10:37:29 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int move(t_data *img,float x,float y);
void drawline(int *vals, t_data *img, int *color_list);
void ray(t_data *img);
void player(t_data *img,float x, float y,int len);
void tile(t_data *img);
void wall(t_data *img);


int moves(int keycode, t_data *vars)
{
    // printf("keycode :: %d\n",keycode);
    //w
    if (keycode == 13 || keycode == 119)
    {
        vars->player.x -= vars->player.dx;
        vars->player.y -= vars->player.dy;

        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
        return (1);
    }//s
    else if (keycode == 1|| keycode == 115)
    {
        vars->player.x += vars->player.dx;
        vars->player.y += vars->player.dy;

        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);

        return (1);
    }//a
    else if (keycode == 0|| keycode == 97)
    {
        vars->player.da -=0.1;
        if (vars->player.da < 0)
        {
            vars->player.da += 2*PI;
        }
        vars->player.dx = cos(vars->player.da)*5;
        vars->player.dy = sin(vars->player.da)*5;
        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
        return (1);
    }//d
    else if (keycode == 2|| keycode == 100)
    {
        vars->player.da +=0.1;
        if (vars->player.da >2*PI)
        {
            vars->player.da -= 2*PI;
        }
        vars->player.dx = cos(vars->player.da)*5;
        vars->player.dy = sin(vars->player.da)*5;
        move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
        return (1);
    }
    if (keycode < 0)
        exit(1);
    return (0);
}
float dist(float ax, float ay, float bx, float by, float amgle)
{
    return (sqrt((bx-ax)*(bx-ax) - (by-ay)*(by-ay)));
}


void    run(t_data *canva)
{  
    printf(" dy %f\n dx %f\n da: %f\n\n\n",canva->player.dy,canva->player.dx,canva->player.da);
    mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
        0);
        mlx_hook(canva->win_ptr, 2, 1L << 1, moves, &(*canva));
    // mlx_key_hook(canva->win_ptr, moves, &(*canva));
    mlx_loop(canva->mlx_ptr);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    if ((data->width > x && data->height > y) && (0 <= x && 0 <= y))
    {
        dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void    step(int *p2, int *p1, double *error, double dp)
{
    *error = *error + dp;
    if (*p1 < *p2)
        *p1 = *p1 + 1;
    else
        *p1 = *p1 - 1;
}


void    drawline(int *vals, t_data *img, int *color_list)
{
    int i;
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
void render(t_data *img)
{
    int i   =   0;
    int j   =   0;
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
    {
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,2,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
    };
    // drawline((int[]){img->player.x,img->player.y,img->player.x -img->player.dx*5,img->player.y-img->player.dy *5},img,(int[]){0xFFFFFFF});
    // ray(img);
    run(&(*img));
}
void clear(t_data *img)
{
     for (size_t i = 0; i < img->width; i++)
     {
        drawline((int[]){i,0,i, img->height},img,(int[]){0x0000});
     }
     
}

int move(t_data *img,float x, float y)
{
    int i ;
    int j =0;
    coordinate_t point;
    point.x=0;
    point.y=0;
    // wall and tile re draw

    // clear(img);
    wall(img);
    tile(img);
    img->player.y -= y;
    img->player.x -= x;
    player(img,img->player.x,img->player.y,img->width/(64 *2));
    ray(img);
    i=0;
    // drawline((int[]){img->player.x,img->player.y+5,img->player.x -(img->player.dx*2),img->player.y-1-(img->player.dy *2)},img,(int[]){0x735674});
    // player(img);

    run(img);
    return (0);
}

void player (t_data *img, float x, float y,int len)
{
    
    int i =0;
    while (i <= len)
    {
        drawline((int[]){x+i,y,x+i,y+len},img,(int[]){0x735674});
        i++;
        /* code */
    }
    img->player_center.x = x + i/2;
    img->player_center.y = y + len/2;
        drawline((int[]){x+i/2,y+len/2,x  -( img->player.dx*(5)),y  - (img->player.dy*(5))},img,(int[]){0xFFF0000});

    // run(img);
    
}
void    call(t_data *canva)
{
    int     status;
    int     ratio_x;
    int     ratio_y;
    canva->img = mlx_new_image(canva->mlx_ptr, canva->width, canva->height);
    canva->addr = mlx_get_data_addr(canva->img, &canva->bpp,
            &canva->line_bytes, &canva->endian);
    canva->win_ptr = mlx_new_window(canva->mlx_ptr, canva->width, canva->height,
                "cub3d");
    
    ratio_x = canva->width/64;
    ratio_y = canva->height/64;
    // canva->player.x = canva->width/2;
    // canva->player.y = canva->height/2;
    // canva->player.x =  ratio_x *2 + canva->width/(64*2);
	// canva->player.y =  ratio_y *6+ canva->height/(64*2);
        canva->player.x = 64 *2  + 64/2;
    canva->player.y = 64 * 6 + 64/2;
    wall(canva);
    tile(canva);
    ray(canva);
    player(canva, canva->player.x,    canva->player.y,canva->width/(64*2));
    // printf("hi");
    run(canva);
    // render(canva);
}

int main(int argv, char *argc[])
{

    t_data  canva;
    canva.height = 640;
    canva.width = 960;
    canva.player.da = 90.0f *PI/180.0F - 0.001;
    canva.player.dx = cos(canva.player.da)*5;
    canva.player.dy = sin(canva.player.da)*5;
    canva.mlx_ptr = mlx_init();
    call( &canva);
    return (0);
}

