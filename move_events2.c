#include "cube3d.h"

int	setmove(int *key)
{
	if (*key == 0)
		*key = 1;
	else
		*key = 0;
	return (1);
}

int	move_w(t_data *vars)
{
	while (vars->move.w == 1)
	{
	if (vars->cx + vars->player.dx * 0.1 < vars->longest_row && vars->cx
		+ vars->player.dx * 0.1 >= 0 &&(int)(vars->cy
			+ vars->player.dy * 0.1) < vars->final_c
		&& (int)(vars->cy
			+ vars->player.dy * 0.1)>= 0 && (vars->map[(int)(vars->cy
			+ vars->player.dy * 0.1)][(int)(vars->cx
			+ vars->player.dx * 0.1)] != 1 ))
	{	
        vars->cx += vars->player.dx * (0.05);
		vars->cy += vars->player.dy * (0.05);
    }
	// // if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
	// // 		+ vars->player.dy * 0.3) < vars->final_c && (int)(vars->cy
	// // 		+ vars->player.dy * 0.3) >= 0 && vars->map[(int)(vars->cy
	// // 		+ vars->player.dy * 0.3)][(int)(vars->cx)] != 1)
    //      printf("wmove x------->%d\n", vars->map[(int)vars->cy][(int)(vars->cx
	// 		+ vars->player.dx * 0.3)]);
    // printf("wmove y------->%d\n", vars->map[(int)(vars->cy
	// 		+ vars->player.dy * 0.3)][(int)(vars->cx)]);
	move(vars);
	}
	return (1);
}
int	move_s(t_data *vars)
{
	while (vars->move.s == 1)
	{
	if ((int)vars->cx - vars->player.dx < vars->longest_row && (int)vars->cx - vars->player.dx >= 0
		&& (int)(vars->cy
			- vars->player.dy * 0.1) < vars->final_c && (int)(vars->cy
			- vars->player.dy * 0.1) >= 0 && vars->map[(int)(vars->cy
			- vars->player.dy * 0.1)][(int)(vars->cx - vars->player.dx
				* 0.1)] != 1)
                {
                    vars->cx -= vars->player.dx * 0.05;
                    vars->cy -= vars->player.dy * 0.05;

                }
	// if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
	// 		+ vars->player.dy * 0.3) < vars->final_c && (int)(vars->cy
	// 		+ vars->player.dy * 0.3) >= 0 && vars->map[(int)(vars->cy
	// 		- vars->player.dy * 0.3)][(int)(vars->cx)] != 1)
	move(vars);
	// mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
	}
	return (1);
}
int	move_a(t_data *vars)
{
	double	rayAngle;

	while (vars->move.a == 1)
	{
	rayAngle = (atan2l(vars->player.dy, vars->player.dx) - vars->directionstart
			* (PI / 2));
	if (vars->cx + cos(rayAngle) * 0.1 < vars->longest_row && vars->cx
		+ cos(rayAngle) * 0.1 >= 0 && (int)(vars->cy
			+ sin(rayAngle) * 0.1) < vars->final_c && (int)(vars->cy
			+ sin(rayAngle) * 0.1) >= 0 && vars->map[(int)(vars->cy+ sin(rayAngle) * 0.1)][(int)(vars->cx + cos(rayAngle)
			* 0.1)] != 1)
	{
		vars->cx += cos(rayAngle) * 0.05;
		vars->cy += sin(rayAngle) * 0.05;
	}
	// if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
	// 		+ sin(rayAngle) * 0.95) < vars->final_c && (int)(vars->cy
	// 		+ sin(rayAngle) * 0.95) >= 0 && vars->map[(int)(vars->cy
	// 		+ sin(rayAngle) * 0.95)][(int)(vars->cx)] != 1)
	// {
	// }
	move(vars);
	}
	return (1);
}
int	move_d(t_data *vars)
{
	double	rayAngle;

	while (vars->move.d == 1)
	{
	rayAngle = (atan2l(vars->player.dy, vars->player.dx) - vars->directionstart
			* (PI / 2));
	if (vars->cx - cos(rayAngle) * 0.1 < vars->longest_row && vars->cx
		- cos(rayAngle) * 0.1 >= 0 && vars->cy - sin(rayAngle)
		* 0.1 < vars->final_c && vars->cy - sin(rayAngle) * 0.1 >= 0
		&& vars->map[(int)(vars->cy- sin(rayAngle) * 0.1 -0.01)][(int)(vars->cx - cos(rayAngle)
			* 0.1)] != 1)
	{
		vars->cx -= cos(rayAngle) * 0.05;
		vars->cy -= sin(rayAngle) * 0.05;
	}
    //  printf("moved curr ------->%d %dc %d\n",vars->map[(int)(vars->cy)][(int)(vars->cx)],(int)vars->cx,(int)vars->cy );
    // printf("moved ------->%d\n",vars->map[(int)(vars->cy- sin(rayAngle) * 0.05)][(int)(vars->cx - cos(rayAngle)
	// 		* 0.05)] );
	// if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
	// 		- sin(rayAngle) * 0.95) < vars->final_c && (int)(vars->cy
	// 		- sin(rayAngle) * 0.95) >= 0 && vars->map[(int)(vars->cy
	// 		- sin(rayAngle) * 0.95)][(int)(vars->cx)] != 1)
	// {
	// }
	move(vars);
	}
	return (1);
}
int	move_l(t_data *vars)
{
	double	rayAngle;
	double	oldDirX;
	double	oldPlaneX;

	while (vars->move.l == 1)
	{
	rayAngle = vars->directionstart;
	oldDirX = vars->player.dx;
	vars->player.dx = vars->player.dx * cos(-0.1 * rayAngle) - vars->player.dy
		* sin(-0.1 * rayAngle);
	vars->player.dy = oldDirX * sin(-0.1 * rayAngle) + vars->player.dy
		* cos(-0.1 * rayAngle);
	oldPlaneX = vars->camaera.x;
	vars->camaera.x = vars->camaera.x * cos(-0.1 * rayAngle) - vars->camaera.y
		* sin(-0.1 * rayAngle);
	vars->camaera.y = oldPlaneX * sin(-0.1 * rayAngle) + vars->camaera.y
		* cos(-0.1 * rayAngle);
	vars->player.da -= 6;
	vars->player.da = FixAng(vars->player.da);
	vars->player.mdx = cos(radiansfd(vars->player.da));
	vars->player.mdy = sin(radiansfd(vars->player.da));
	move(vars);
	}
	return (1);
}
int	move_r(t_data *vars)
{
	double	rayAngle;
	double	oldDirX;
	double	oldPlaneX;

	while (vars->move.r == 1)
	{
	rayAngle = vars->directionstart;
	oldDirX = vars->player.dx;
	vars->player.dx = vars->player.dx * cos(0.1 * rayAngle) - vars->player.dy
		* sin(0.1 * rayAngle);
	vars->player.dy = oldDirX * sin(0.1 * rayAngle) + vars->player.dy * cos(0.1
			* rayAngle);
	oldPlaneX = vars->camaera.x;
	vars->camaera.x = vars->camaera.x * cos(0.1 * rayAngle) - vars->camaera.y
		* sin(0.1 * rayAngle);
	vars->camaera.y = oldPlaneX * sin(0.1 * rayAngle) + vars->camaera.y
		* cos(0.1 * rayAngle);
	vars->player.da += 6;
	vars->player.da = FixAng(vars->player.da);
	vars->player.mdx = cos(radiansfd(vars->player.da));
	vars->player.mdy = sin(radiansfd(vars->player.da));
	move(vars);
	}
	return (1);
}
int	moves(int keycode, t_data *vars)
{
	if ((keycode == 13 || keycode == 119) && setmove(&vars->move.w))
		move_w(vars);
	else if ((keycode == 1 || keycode == 115) && setmove(&vars->move.s))
		move_s(vars);
	else if ((keycode == 0 || keycode == 97) && setmove(&vars->move.a))
		move_a(vars);
	else if ((keycode == 2 || keycode == 100) && setmove(&vars->move.d))
		move_d(vars);
	else if ((keycode == 124 || keycode == 65363) && setmove(&vars->move.r))
		move_r(vars);
	else if ((keycode == 123 || keycode == 65361) && setmove(&vars->move.l))
		move_l(vars);
	if (keycode == 53 || keycode == 65307)
	    error_free(vars, -1, "Exit\n");
    if (keycode < 0)
        exit(0);
	return (0);
}

int map_key(int keycode,t_data *vars)
{
    printf("keycodemao :: -> %d\n",keycode);

    if (keycode == 109 || keycode == 0)
    {
        setmove(&vars->key_m);
        move(vars);
    }
    return (0);
}
