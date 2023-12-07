#include "cube3d.h"

int setmove(int key)
{
	if(key == 0)
		key = 1;
	else
		key = 0;
	return(1);
}
int moves(int keycode, t_data *vars)
{
	if ((keycode == 13 || keycode == 119) && setmove(vars->move_w))
    {
		move();
	}
	else if ((keycode == 1|| keycode == 115) && setmove(vars->move_s))
    {
		move();
    }//a
    else if ((keycode == 0|| keycode == 97) && setmove(vars->move_a))
    {
		move();
    }//d
    else if ((keycode == 2|| keycode == 100)  && setmove(vars->move_d))
    {
		move();
        
    }
    if (keycode < 0)
        exit(1);
    return (0);
}

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