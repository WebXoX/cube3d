#include "cube3d.h"
#include <math.h>
#define screenWidth 1540
#define screenHeight 1080
#define mapWidth 24
#define mapHeight 24
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
            // cameraX = fmod(cameraX + 2 * PI, 2 * PI);

             rayDirX = dirX + planeX * cameraX;
             rayDirY = dirY + planeY * cameraX;
            // double rayAngle = atan2l(dirY,dirX) - 0.001;
            // cameraX = rayAngle - (double)(img->camaera.x);
             mapX = (int)posX;
             mapY = (int) posY;

            
            double deltaDistX =  fabs(1 / rayDirX);
            double deltaDistY =  fabs(1 / rayDirY);
            // deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            // deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

            // double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            // double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

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

            while (hit == 0)
            {
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                if (mapX < img->longest_row && mapX >= 0 && mapY < img->final_c && mapY >= 0 && img->map[mapY][mapX] == 1)
                {       
                    hit = 1;
                    perpWallDist = 0;
                }
            }

// if(side == 0) perpWallDist = (sideDistX - deltaDistX);
//       else          perpWallDist = (sideDistY - deltaDistY);
        double wallX, wallY;
        wallX = 0 ;
        wallY = 0 ;
            if (side == 0)
            {
                perpWallDist = (sideDistX - deltaDistX);//* cos(cameraX);
                // perpWallDist = fabs(mapX - posX + (1 - stepX) / 2) / rayDirX* cos(cameraX);
                wallX = posY + perpWallDist * rayDirY;
            }
            else
            {
                // perpWallDist = fabs(mapY - posY + (1 - stepY) / 2) / rayDirY* cos(cameraX);
                 perpWallDist = (sideDistY - deltaDistY);//* cos(cameraX);
                wallX = posX + perpWallDist * rayDirX;
            }
            wallX -= floor((wallX));
            int lineHeight = 0;
             lineHeight = (int)(img->height / perpWallDist);
            // int lineHeight = (int)(img->height / (perpWallDist )* cos(cameraX));

            int drawStart =  img->height / 2 -lineHeight / 2;
            if (drawStart < 0)
                drawStart = 0;
            int drawEnd = lineHeight / 2 + img->height / 2;
            if (drawEnd >= img->height)
                drawEnd = img->height - 1;
            int color;
            if(side == 1)
                    color = floor( wallX*64); // Red
            else
                    color = floor( wallX*64); // Red
            // printf("mapx %d\n",color );

            // if (side == 1)
            //     color /= 2;

            // printf("sidex %f, sidey %f`\n",wallX,wallX);

        // drawline((int []){(i*8)+529,0,(i*8)+529,lh},img,(int[]){0xFF0000});
        int j=0;
        // while (j < 8)
        // {
        //      // my_mlx_pixel_put(img,x,y,color);
        //      drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){color});
        //  j++;
        // }
                // mlx_pixel_put(img->mlx_ptr, img->win_ptr, color, k, img->texture.addr[((k%64) * img->texture.img_wid + (color))]);
        float lo = drawStart;
        float dy =  (lineHeight )/(64.0) ;
        // float ty_off = 0;
        // printf("HEEREEE lh %d dy *64 %f\n", lineHeight, dy*64.0);
            int k = 0;
            lo = drawStart;
            while(k < 64)
            {
                    drawline((int []){((x)),lo,x,lo + dy},img,(int[]){img->texture.addr[(((k)%64) * img->texture.img_hei/4 + (color))]});
                    lo += dy;
                k++;
            }
            j++;
        }
            // drawline((int[]){x, drawStart, x, drawEnd},img,(int[]){color} );

}
