#include "cube3d.h"

int moves(int keycode, t_data *vars)
{
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


int move(t_data *img,float x, float y)
{
    int i =0;
    while (i < img->height)
    {

        drawline((int[]){0,i ,img->width ,i} ,img, (int[]){0x045680});
        i++;
    }
    //wall and tile re draw
    tile(img);
    ray(img);
    wall(img);
    player(img);
    img->player.y -= y;
    img->player.x -= x;
    i=0;
    // drawline((int[]){img->player.x,img->player.y+5,img->player.x -(img->player.dx*2),img->player.y+5-(img->player.dy *2)},img,(int[]){0x735674});
    run(img);
    return (0);
}