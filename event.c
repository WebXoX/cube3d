/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:10:28 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 13:33:25 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	setmove(int *key)
{
	if (*key == 0)
		*key = 1;
	else
		*key = 0;
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
	return (0);
}

int	map_key(int keycode, t_data *vars)
{
	if (keycode == 109 || keycode == 46)
	{
		setmove(&vars->key_m);
		move(vars);
	}
	return (0);
}
