#include "cube3d.h"
#include <math.h>
float radiansfd(float angle)
{
	return (angle * PI / 180.0f);
}
void draw_pixel(int x, int y, int color, void *mlx, void *win)
{
    mlx_pixel_put(mlx, win, x, y, color);
}


void ray(t_data *img)
{
    double posX = img->cx, posY = img->cy;
    double dirX =img->player.dx, dirY = img->player.dy;
    double planeX = img->camaera.x, planeY =  img->camaera.y;

            double cameraX = 0;
            double rayDirX = 0;
            double rayDirY = 0;
            int mapX = 0;
            int mapY = 0;
            double sideDistX = 0;
            double sideDistY = 0;
            double deltaDistX = 0;
            double deltaDistY = 0;
        for (int x = 0; x < img->width; x++)
        {
             cameraX = 2 * x / (double)img->width - 1 ;

             rayDirX = dirX + planeX * cameraX;
             rayDirY = dirY + planeY * cameraX;
             mapX = (int)posX;
             mapY = (int) posY;


            deltaDistX =  fabs(1 / rayDirX);
            deltaDistY =  fabs(1 / rayDirY);

            double perpWallDist = 0;

            int stepX;
            int stepY;

            int hit = 0;
            int side;

            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }
            int idx;
            while (hit == 0)
            {
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                     if (mapY >=0 && mapX+1 >= 0 && mapX+1 <img->longest_row && mapY < img->final_c && img->map[mapY][mapX+1] != 1 && rayDirX < 0)
                        idx = 2;
                    else
                        idx = 3;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                    if (mapX >=0 && mapY-1 >= 0 && mapX <img->longest_row && mapY-1 < img->final_c && img->map[mapY-1][mapX] != 1 && rayDirY > 0)
                        idx = 1;
                    else
                        idx = 0;
                }
                if (mapX < img->longest_row && mapX >= 0 && mapY < img->final_c && mapY >= 0 && img->map[mapY][mapX] == 1)
                {
                    hit = 1;
                    perpWallDist = 0;
                }
            }
        double wallX, wallY;
        wallX = 0 ;
        wallY = 0 ;
            if (side == 0)
            {
                perpWallDist = (sideDistX - deltaDistX);//* cos(cameraX);
                wallX = posY + perpWallDist * rayDirY;
            }
            else
            {
                 perpWallDist = (sideDistY - deltaDistY);//* cos(cameraX);
                wallX = posX + perpWallDist * rayDirX;
            }
            wallX -= floor((wallX));
            int lineHeight = 0;
             lineHeight = (int)(img->height / perpWallDist);

            int drawStart =  img->height / 2 -lineHeight / 2;
            if (drawStart < 0)
                drawStart = 0;
            int drawEnd = lineHeight / 2 + img->height / 2;
            if (drawEnd >= img->height)
                drawEnd = img->height - 1;
            int color;
            color = floor( wallX*64);
            // printf("mapx %d\n",color );

            // if (side == 1)
            //     color /= 2;

            // printf("sidex %f, sidey %f`\n",wallX,wallX);

        // drawline((int []){(i*8)+529,0,(i*8)+529,lh},img,(int[]){0xFF0000});
       		float lo = drawStart;
        float dy =  (64.0)/(lineHeight ) ;
            lo = drawStart;
			double texPos = (drawStart - img->height / 2 + lineHeight / 2) * dy;
            while(lo < drawEnd)
            {
					int texy = (int)texPos;
					texPos+=dy;
                    // drawline((int []){((x)),lo,x,lo+1},img,(int[]){img->texture2[idx].addr[(texy * img->texture2[idx].img_hei/4 + (color))]});
					my_mlx_pixel_put(img, x, lo+1, img->texture2[idx].addr[(texy * img->texture2[idx].img_hei/4 + (color))]);
                    lo += 1;
            }
        }
}
