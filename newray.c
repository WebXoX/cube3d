#include "cube3d.h"
#include <math.h>

float radiansfd(float angle)
{
	return (angle * PI / 180.0f);
}

float FixAng(float a){ if(a>360.0f){ a-=360.0f;} if(a<0.0f){ a+=360.0f;} return a;}
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
            // double deltaDistX = (rayDirX == 0) ? 1e30: fabs(1 / rayDirX);
            // double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
            double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

            double perpWallDist;
            //  perpWallDist = 0;

            int stepX;
            int stepY;

            int hit = 0;
            int side;

            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (float)((posX - mapX) * deltaDistX);
            }
            else
            {
                stepX = 1;
                sideDistX = (float)((mapX + 1.0 - posX) * deltaDistX);
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (float)((posY - mapY) * deltaDistY);
            }
            else
            {
                stepY = 1;
                sideDistY =(float) ((mapY + 1.0 - posY) * deltaDistY);
            }

            while (hit == 0)
            {
                if (sideDistX < sideDistY)
                {
                    sideDistX +=(float) deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += (float)deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                if (mapX < img->longest_row && mapX >= 0 && mapY < img->final_c && mapY >= 0
        && img->map[mapY][mapX] == 1)
            {       

            hit = 1;
                perpWallDist = 0;

            }
            }

            printf("\nmap %d\n",mapX);
            printf("\nmap %d\n",mapY);
            printf("\npos %f\n",posX);
            printf("\npos %f\n",posY);
            printf("\nray %f\n",rayDirX);
            printf("ray %f\n",rayDirY);
            printf("step %d\n",stepX);
            printf("step %d\n",stepY);
            printf("step %f\n",sideDistX);
            printf("step %f\n",sideDistY);
            printf("step %f\n",deltaDistX);
            printf("step %f\n",deltaDistY);
            printf("step %f\n",sideDistX - deltaDistX);
            printf("step %f\n",sideDistY - deltaDistY);
            //  if(side == 0) 
            //  perpWallDist = (sideDistX - deltaDistX);
            //  else         
            //   perpWallDist = (sideDistY - deltaDistY);
            if (side == 0)
                perpWallDist = (mapX - posX + (1 - stepX) / 2.0) / rayDirX +0.01;
            else
                perpWallDist = (mapY - posY + (1 - stepY) / 2.0) / rayDirY +0.01;
            printf("wall %f\n",perpWallDist);

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
