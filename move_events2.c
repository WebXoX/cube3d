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
	if (vars->cx + vars->player.dx * 0.8 < vars->longest_row && vars->cx
		+ vars->player.dx * 0.8 >= 0 && vars->cy < vars->final_c
		&& vars->cy >= 0 && vars->map[(int)vars->cy][(int)(vars->cx
			+ vars->player.dx * 0.8)] != 1)
		vars->cx += vars->player.dx * (0.52);
	if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
			+ vars->player.dy * 0.8) < vars->final_c && (int)(vars->cy
			+ vars->player.dy * 0.8) >= 0 && vars->map[(int)(vars->cy
			+ vars->player.dy * 0.8)][(int)(vars->cx)] != 1)
		vars->cy += vars->player.dy * (0.52);
	move(vars);
	}
	return (1);
}
int	move_s(t_data *vars)
{
	while (vars->move.s == 1)
	{
	if ((int)vars->cx < vars->longest_row && (int)vars->cx >= 0
		&& vars->cy < vars->final_c && vars->cy >= 0
		&& vars->map[(int)vars->cy][(int)(vars->cx - vars->player.dx
				* 0.8)] != 1)
		vars->cx -= vars->player.dx * 0.52;
	if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
			+ vars->player.dy * 0.8) < vars->final_c && (int)(vars->cy
			+ vars->player.dy * 0.8) >= 0 && vars->map[(int)(vars->cy
			- vars->player.dy * 0.8)][(int)(vars->cx)] != 1)
		vars->cy -= vars->player.dy * 0.52;
	move(vars);
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
	if (vars->cx + cos(rayAngle) * 0.8 < vars->longest_row && vars->cx
		+ cos(rayAngle) * 0.8 >= 0 && vars->cy < vars->final_c && vars->cy >= 0
		&& vars->map[(int)vars->cy][(int)(vars->cx + cos(rayAngle)
			* 0.8)] != 1)
		vars->cx += cos(rayAngle) * 0.52;
	if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
			+ sin(rayAngle) * 0.8) < vars->final_c && (int)(vars->cy
			+ sin(rayAngle) * 0.8) >= 0 && vars->map[(int)(vars->cy
			+ sin(rayAngle) * 0.8)][(int)(vars->cx)] != 1)
		vars->cy += sin(rayAngle) * 0.52;
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
	if (vars->cx - cos(rayAngle) * 0.8 < vars->longest_row && vars->cx
		- cos(rayAngle) * 0.8 >= 0 && vars->cy - sin(rayAngle)
		* 0.8 < vars->final_c && vars->cy - sin(rayAngle) * 0.8 >= 0
		&& vars->map[(int)(vars->cy)][(int)(vars->cx - cos(rayAngle)
			* 0.8)] != 1)
		vars->cx -= cos(rayAngle) * 0.52;
	if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
			- sin(rayAngle) * 0.8) < vars->final_c && (int)(vars->cy
			- sin(rayAngle) * 0.8) >= 0 && vars->map[(int)(vars->cy
			- sin(rayAngle) * 0.8)][(int)(vars->cx)] != 1)
		vars->cy -= sin(rayAngle) * 0.52;
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
	vars->player.dx = vars->player.dx * cos(-0.15 * rayAngle) - vars->player.dy
		* sin(-0.15 * rayAngle);
	vars->player.dy = oldDirX * sin(-0.15 * rayAngle) + vars->player.dy
		* cos(-0.15 * rayAngle);
	oldPlaneX = vars->camaera.x;
	vars->camaera.x = vars->camaera.x * cos(-0.15 * rayAngle) - vars->camaera.y
		* sin(-0.15 * rayAngle);
	vars->camaera.y = oldPlaneX * sin(-0.15 * rayAngle) + vars->camaera.y
		* cos(-0.15 * rayAngle);
	vars->player.da -= 6 * vars->directionstart;
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
	vars->player.dx = vars->player.dx * cos(0.15 * rayAngle) - vars->player.dy
		* sin(0.15 * rayAngle);
	vars->player.dy = oldDirX * sin(0.15 * rayAngle) + vars->player.dy * cos(0.15
			* rayAngle);
	oldPlaneX = vars->camaera.x;
	vars->camaera.x = vars->camaera.x * cos(0.15 * rayAngle) - vars->camaera.y
		* sin(0.15 * rayAngle);
	vars->camaera.y = oldPlaneX * sin(0.15 * rayAngle) + vars->camaera.y
		* cos(0.15 * rayAngle);
	vars->player.da += 6* vars->directionstart;
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
	{
		move_s(vars);
	} // a
	else if ((keycode == 0 || keycode == 97) && setmove(&vars->move.a))
	{
		move_a(vars);
	} // d
	else if ((keycode == 2 || keycode == 100) && setmove(&vars->move.d))
	{
		move_d(vars);
	}
	else if ((keycode == 124 || keycode == 65363) && setmove(&vars->move.r))
	{
		move_r(vars);
	} // d
	else if ((keycode == 123 || keycode == 65361) && setmove(&vars->move.l))
	{
		move_l(vars);
	}
	if (keycode == 53 || keycode == 65307)
	error_free(vars, -1, "Exit\n");
	return (0);
}

int map_key(int keycode,t_data *vars)
{
    printf("keycodemao :: -> %d\n",keycode);

    if (keycode == 109 || keycode == 46)
    {
        setmove(&vars->key_m);
        move(vars);
    }
    return (0);
}
