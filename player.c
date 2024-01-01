#include "cube3d.h"
void set_map_value(t_data *data, char c)
{
	if (c == 'N')
		data->player.da = 90.0f;
	else if (c == 'S')
		data->player.da = 270.0f;
	else if (c == 'E')
		data->player.da = 0.0f;
	else if (c == 'W')
		data->player.da = 360.0f;
	data->player.mdx = cos(radiansfd(data->player.da));
	data->player.mdy = sin(radiansfd(data->player.da));
}

void	set_values(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.dy = -1.0;
		data->camaera.x = 0.66;
		data->directionstart = 1;
	}
	else if (c == 'S')
	{
		data->player.dy += 1;
		data->camaera.x -= 0.66;
		data->directionstart = 1;
	}
	else if (c == 'E')
	{
		data->player.dx = 1;
		data->camaera.y -= 0.66;
		data->directionstart = -1;
	}
	else if (c == 'W')
	{
		data->player.dx -= 1;
		data->camaera.y += 0.66;
		data->directionstart = -1;
	}
	set_map_value(data,c);

}

int	ft_isplayer(char c, t_data *data, int i, int row_num)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		(data->player_count)++;
		data->cx = i;
		data->cy = row_num;
		set_values(data, c);
		return (1);
	}
	else
		return (0);
}

void player(t_data *img)
{
    int i;
    int j;
    int c;
    coordinate_t point;

    i = -1;
        while (++i < img->final_c)
        {
            j = -1;
            while (++j < img->longest_row)
            {
                if(img->map[i][j]==2)
                {
                    c = -1;
                    while (++c < img->scale/2)
                        drawline((int[]){img->player.x ,img->player.y + c ,
							img->player.x+ 10 ,img->player.y + c} ,img,(int[]){0x735674});
                }
                point.x+=img->scale;
            }
            point.x=0;
            point.y+=img->scale;
        }
    drawline((int[]){img->player.x +10/2,img->player.y + img->scale/4,img->player.x+10/2 -img->player.mdx*10,img->player.y+ img->scale/4 - img->player.mdy *10},img,(int[]){0x735674});
}
