/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:52:14 by jperinch          #+#    #+#             */
/*   Updated: 2024/01/02 11:52:15 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void re_tile(t_data *img,coordinate_t  *point, int c)
{
     while (c < img->scale - 2)
    {
        drawline((int[]){point->x ,point->y + c ,point->x
                + img->scale-2 ,point->y + c} , img, 0x000);
        c++;
    }
}

void tile(t_data *img)
{
    int i;
    int j;
    coordinate_t point;
    int c;

    point.x = 0;
    point.y = 0;
    i = -1;
    while (++i <img->final_c)
    {
        j=-1;
        while (++j < img->longest_row)
        {
            if(img->map[i][j]==0 || img->map[i][j]== 2)
            {
                c = -1;
                while (++c < img->scale - 2)
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + img->scale-2 ,point.y + c} , img, create_trgb(0,10,10,10));
            }
            point.x+=img->scale;
        }
        point.x=0;
        point.y+=img->scale;
    }
}
