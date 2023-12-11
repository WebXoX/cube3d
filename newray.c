#include "cube3d.h"
#include <math.h>
#define screenWidth 1540
#define screenHeight 1080
#define mapWidth 24
#define mapHeight 24

void draw_pixel(int x, int y, int color, void *mlx, void *win)
{
    mlx_pixel_put(mlx, win, x, y, color);
}


void ray(t_data *img)
{
    double posX = img->cx, posY = img->cy;
    double dirX =img->player.dx, dirY = img->player.dy;
    double planeX = img->camaera.x, planeY =  img->camaera.y;


        for (int x = 0; x < img->width; x++)
        {
            double cameraX = 2 * x / (double)img->width - 1;
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

            int mapX = (int)posX;
            int mapY = (int) posY;

            double sideDistX;
            double sideDistY;
            double deltaDistX = (rayDirX == 0) ? 1e30: abs(1 / rayDirX);
            double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);

            double perpWallDist;

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
                if (img->map[mapY][mapX] > 0)
                    hit = 1;
            }

            if (side == 0)
                perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
            else
                perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

            int lineHeight = (int)(img->height / perpWallDist);
            int drawStart = -lineHeight / 2 + img->height / 2;
            if (drawStart < 0)
                drawStart = 0;
            int drawEnd = lineHeight / 2 + img->height / 2;
            if (drawEnd >= img->height)
                drawEnd = img->height - 1;

            int color;
            switch (side)
            {
            case 1:
                color = 0xFF0000; // Red
                break;
            default:
                color = 0xFFFF00; // Yellow
                break;
            }

            if (side == 1)
                color /= 2;

            drawline((int[]){x, drawStart, x, drawEnd},img,(int[]){color} );
        }
    
}
