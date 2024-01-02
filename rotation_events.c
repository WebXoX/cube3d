/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:08:35 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 12:50:35 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	move_l(t_data *vars)
{
	double	rayangle;
	double	olddirx;
	double	oldplanex;

	while (vars->move.l == 1)
	{
		rayangle = vars->directionstart;
		olddirx = vars->player.dx;
		vars->player.dx = vars->player.dx * cos(-0.15 * rayangle)
			- vars->player.dy * sin(-0.15 * rayangle);
		vars->player.dy = olddirx * sin(-0.15 * rayangle) + vars->player.dy
			* cos(-0.15 * rayangle);
		oldplanex = vars->camaera.x;
		vars->camaera.x = vars->camaera.x * cos(-0.15 * rayangle)
			- vars->camaera.y * sin(-0.15 * rayangle);
		vars->camaera.y = oldplanex * sin(-0.15 * rayangle) + vars->camaera.y
			* cos(-0.15 * rayangle);
		vars->player.da -= (cos(0.15 * rayangle) + sin(0.15 * rayangle)) *7.5;
		vars->player.da = FixAng(vars->player.da);
		vars->player.mdx = cos(radiansfd(vars->player.da));
		vars->player.mdy = sin(radiansfd(vars->player.da));
		move(vars);
	}
	return (1);
}

int	move_r(t_data *vars)
{
	double	rayangle;
	double	olddirx;
	double	oldplanex;

	while (vars->move.r == 1)
	{
		rayangle = vars->directionstart;
		olddirx = vars->player.dx;
		vars->player.dx = vars->player.dx * cos(0.15 * rayangle)
			- vars->player.dy * sin(0.15 * rayangle);
		vars->player.dy = olddirx * sin(0.15 * rayangle) + vars->player.dy
			* cos(0.15 * rayangle);
		oldplanex = vars->camaera.x;
		vars->camaera.x = vars->camaera.x * cos(0.15 * rayangle)
			- vars->camaera.y * sin(0.15 * rayangle);
		vars->camaera.y = oldplanex * sin(0.15 * rayangle) + vars->camaera.y
			* cos(0.15 * rayangle);
		vars->player.da +=  (cos(0.15 * rayangle) + sin(0.15 * rayangle)) *7.5;
		vars->player.da = FixAng(vars->player.da);
		vars->player.mdx = cos(radiansfd(vars->player.da));
		vars->player.mdy = sin(radiansfd(vars->player.da));
		move(vars);
	}
	return (1);
}
