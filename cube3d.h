/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:01:28 by afarheen          #+#    #+#             */
/*   Updated: 2023/11/07 15:55:36 by afarheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

// #include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
# include "mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;
	void	**mlx_ptr;
	void	**win_ptr;

}	t_data;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	error;
	double	e2;
}	t_line;

#endif