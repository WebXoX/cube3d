/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:51:40 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 12:09:09 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
	double	rayangle;

	while (vars->move.a == 1)
	{
		rayangle = (atan2l(vars->player.dy, vars->player.dx)
				- vars->directionstart * (PI / 2));
		if (vars->cx + cos(rayangle) * 0.8 < vars->longest_row && vars->cx
			+ cos(rayangle) * 0.8 >= 0 && vars->cy < vars->final_c
			&& vars->cy >= 0 && vars->map[(int)vars->cy][(int)(vars->cx
			+ cos(rayangle) * 0.8)] != 1)
			vars->cx += cos(rayangle) * 0.52;
		if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
			+ sin(rayangle) * 0.8) < vars->final_c && (int)(vars->cy
			+ sin(rayangle) * 0.8) >= 0 && vars->map[(int)(vars->cy
			+ sin(rayangle) * 0.8)][(int)(vars->cx)] != 1)
			vars->cy += sin(rayangle) * 0.52;
		move(vars);
	}
	return (1);
}

int	move_d(t_data *vars)
{
	double	rayangle;

	while (vars->move.d == 1)
	{
		rayangle = (atan2l(vars->player.dy, vars->player.dx)
				- vars->directionstart * (PI / 2));
		if (vars->cx - cos(rayangle) * 0.8 < vars->longest_row && vars->cx
			- cos(rayangle) * 0.8 >= 0 && vars->cy - sin(rayangle)
			* 0.8 < vars->final_c && vars->cy - sin(rayangle) * 0.8 >= 0
			&& vars->map[(int)(vars->cy)][(int)(vars->cx - cos(rayangle)
			* 0.8)] != 1)
			vars->cx -= cos(rayangle) * 0.52;
		if (vars->cx < vars->longest_row && (vars->cx) >= 0 && (int)(vars->cy
			- sin(rayangle) * 0.8) < vars->final_c && (int)(vars->cy
			- sin(rayangle) * 0.8) >= 0 && vars->map[(int)(vars->cy
			- sin(rayangle) * 0.8)][(int)(vars->cx)] != 1)
			vars->cy -= sin(rayangle) * 0.52;
		move(vars);
	}
	return (1);
}
