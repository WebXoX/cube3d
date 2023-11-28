#include "cube3d.h"
void drawline(int *vals, t_data *img, int *color_list);

void tile(t_data *img)
{
    int i;
    int j;
    coordinate_t point;
    int map[8][8]=           //the map array. Edit to change level but keep the outer walls
    {
    {1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,1,0,1},
    {1,0,2,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
    };
    i=0;
    int ratio_y = img->height/64;
    int ratio_x = img->width/64;
    while (i < 8)
    {
        j=0;
        while (j < 8)
        {
            int c;
            if(map[i][j]==0 || map[i][j]== 2)
            {
                c = 0;
                while (c < ratio_y - 2)
                {
                    drawline((int[]){point.x ,point.y + c ,point.x
                            + ratio_x-2 ,point.y + c} , img, (int[]){0x000});
                    c++;
                }
            }
            point.x+=ratio_x;
            j++;
        }
        point.x=0;
        point.y+=ratio_y;
        i++;
    }
}