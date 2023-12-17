#include "cube3d.h"

void re_tile(t_data *img,coordinate_t  *point, int c)
{
     while (c < img->scale - 2)
    {
        drawline((int[]){point->x ,point->y + c ,point->x
                + img->scale-2 ,point->y + c} , img, (int[]){0x000});
        c++;
    }
}

// void tile(t_data *img)
// {
//     int i;
//     int j;
//     coordinate_t point;

//     i = -1;
//     while (++i <img->final_c)
//     {
//         j = -1;
//         while (++j < img->longest_row)
//         {
//             int c;
//             if(img->map[i][j]==0 || img->map[i][j]== 2)
//             {
//                 c = -1;
//                 while (++c < img->scale + 2)
//                     drawline((int[]){point.x -1 ,point.y-1 + c ,point.x
//                             + img->scale + 1 ,point.y -1 + c} , img, (int[]){0x045680});
//                 re_tile(img, point, -1);
//             }
//             point.x+=img->scale;
//         }
//         point.x=0;
//         point.y+=img->scale;
//     }
// }





void tile(t_data *img)
{
    int i;
    int j;
    coordinate_t point;
    
    point.x = 0;
    point.y = 0;
    i = -1;
    while (++i <img->final_c)
    {
        j=-1;
        while (++j < img->longest_row)
        {
            int c;
            if(img->map[i][j]==0 || img->map[i][j]== 2)
            {
                c = 0;
                // while (c < img->scale + 2)
                // {
                //     drawline((int[]){point.x -1 ,point.y-1 + c ,point.x
                //             + img->scale + 1 ,point.y -1 + c} , img, (int[]){0x045680});
                //     c++;
                // }
                // c = 0;
                while (c < img->scale - 2)
                {
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + img->scale-2 ,point.y + c} , img, (int[]){create_trgb(0,10,10,10)});
                    c++;
                }
                // re_tile(img, &point, 0);

            }
            point.x+=img->scale;
        }
        point.x=0;
        point.y+=img->scale;
    }
}
