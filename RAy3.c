#include "cube3d.h"
void drawline(int *vals, t_data *img, int *color_list);
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void ray(t_data *img)
{
    coordinate_t pos;    // player poss
    coordinate_t dir;    // player direction
    coordinate_t plane;  // camera plane
    coordinate_t sideDis;  // ray location
    coordinate_t deltaDis;  // ray location
    float walldis;
    float Fov;   // ration between length of direction and camera plane 
    double cameraX;
    double rayX;
    double rayY;
    int mapX;  // ray location
    int mapY;  // ray location

   Fov = 2*atan(0.66/1.0);
   pos.x= img->cx;
   pos.y= img->cy;
   mapX = (int) pos.x;
   mapY = (int) pos.y;
   dir.x= -1;
   dir.y= 0;
   plane.x= 0;
   plane.y= 0.66;
   for (size_t i = 0; i < img->width; i++)
   {
    cameraX = 2 * i / (double)(img->width) - 1; //x-coordinate in camera space
    rayX = dir.x + plane.x * cameraX;
    rayY = dir.y+ plane.y * cameraX;
        
    //   printf("1. camera x: %f\n", cameraX);
      printf("1. ray1 x: %f y: %f\n", dir.x + plane.x * cameraX , dir.y + plane.y * cameraX);
      printf("1. plane x: %f y: %f\n",plane.x,plane.y);
      printf("1. dir x: %f y: %f\n",dir.x,dir.y);
      printf("1. ray x: %f y: %f\n",rayX,rayY);
      printf("1. delta x: %f y: %f\n",deltaDis.x,deltaDis.y);
    deltaDis.x = (rayX == 0) ? 1e30 : abs(1 / rayX);
    deltaDis.y = (rayY == 0) ? 1e30 : abs(1 / rayY);
      //what direction to step in x or y-direction (either +1 or -1)
      printf("delta x: %f y: %f\n",deltaDis.x,deltaDis.y);
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      if(rayX < 0)
      {
        stepX = -1;
        sideDis.x = (pos.x - mapX) * deltaDis.x;
      }
      else
      {
        stepX = 1;
        sideDis.x = (mapX + 1.0 - pos.x) * deltaDis.x;
      }
      if(rayY < 0)
      {
        stepY = 1;
        sideDis.y = (pos.y - mapY) * deltaDis.y;
      }
      else
      {
        stepY = 1;
        sideDis.y = (mapY + 1.0 - pos.y) * deltaDis.y;
      }
      while(hit == 0)
      {
        // printf("hitting\n");
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDis.x < sideDis.y)
        {
          sideDis.x+= deltaDis.x;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDis.y += deltaDis.y;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        printf("mapx%d mapy%d\n",mapX,mapY);
        printf("mapx %f mapy %f\n", sideDis.x, sideDis.y);
        if(img->map[mapY][mapX] == 1)
         hit = 1;
      }
    if(side == 0) walldis = (sideDis.x - deltaDis.x);
      else          walldis= (sideDis.y- deltaDis.y);

      //Calculate height of line to draw on screen
        printf("side %f  \n", sideDis.x - deltaDis.x);
        printf("side %f  \n", sideDis.y - deltaDis.y);

      int lineHeight = (int)(img->height / walldis);
        printf("ling %f line %d\n", walldis,lineHeight);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + img->height/ 2;
        printf("wall %d\n", drawStart);

      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + img->height / 2;
      if(drawEnd >= img->height) drawEnd = img->height - 1;
    printf("hi %d hi2 %d\n",drawStart, drawEnd);
    // drawline((int []){i, drawStart,i, drawEnd},img,(int[]){create_trgb(0,255,0,0)});

    //   drawline({x, drawStart, drawEnd}, color);   
   }
    printf("adf a\n");

}
