#include "cube3d.h"

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
    drawline((int[]){img->player.x +10/2,img->player.y + img->scale/4,img->player.x+10/2 -img->player.dx*10,img->player.y+ img->scale/4 - img->player.dy *10},img,(int[]){0x735674});
}
