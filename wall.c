#include "cube3d.h"

void wall(t_data *img)
{
    int i;
    int j;
    coordinate_t point;

    point.x = 0 ;
    point.y = 0 ;

    i   =   -1;
    while (++i < img->final_c)
    {
        j=-1;
        while (++j < img->longest_row)
        {
            int c;
            if(img->map[i][j]==1)
            {
                c = -1;
                while (++c < img->scale - 2)
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + img->scale-2 ,point.y + c} , img, (int[]){create_trgb(0,200,200,200)});
            }
            point.x+=img->scale;
        }
        point.x = 0;
        point.y += img->scale;
    }
}
