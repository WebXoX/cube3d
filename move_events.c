#include "cube3d.h"
int move(t_data *img,float x,float y);
int	move_w(t_data *vars);
int	move_s(t_data *vars);
int	move_a(t_data *vars);
int	move_d(t_data *vars);

int setmove(int* key)
{
	if(*key == 0)
		*key = 1;
	else
		*key = 0;
	return(1);
}
int	move_w(t_data *vars)
{
    printf("keycode :: d");

	while (vars->move_w == 1)
	{
    printf("keycode :: d");

		vars->player.x -= vars->player.dx;
		vars->player.y -= vars->player.dy;
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return(1);
}

int	move_s(t_data *vars)
{
	while (vars->move_s == 1)
	{
		vars->player.x += vars->player.dx;
		vars->player.y += vars->player.dy;
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return(1);
}

int	move_a(t_data *vars)
{
	while (vars->move_a == 1)
	{
		vars->player.da -=0.1;
		if (vars->player.da < 0)
			vars->player.da += 2*PI;
		vars->player.dx = cos(vars->player.da)*5;
		vars->player.dy = sin(vars->player.da)*5;
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return(1);
}
int	move_d(t_data *vars)
{
	while (vars->move_d == 1)
	{
		vars->player.da +=0.1;
		if (vars->player.da >2*PI)
			vars->player.da -= 2*PI;
		vars->player.dx = cos(vars->player.da)*5;
		vars->player.dy = sin(vars->player.da)*5;
		move(vars,0,0);
        mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return(1);
}

int moves(int keycode, t_data *vars)
{
    printf("keycode :: %d\n",keycode);

	if ((keycode == 13 || keycode == 119) && setmove(&vars->move_w))
    {
    printf("w \n");

		move_w(vars);
	}
	else if ((keycode == 1|| keycode == 115) && setmove(&vars->move_s))
    {
		move_s(vars);
    }//a
    else if ((keycode == 0|| keycode == 97) && setmove(&vars->move_a))
    {
		move_a(vars);
    }//d
    else if ((keycode == 2|| keycode == 100)  && setmove(&vars->move_d))
    {
		move_d(vars);
    }
    if (keycode < 0)
        exit(1);
    return (0);
}