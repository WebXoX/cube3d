#include "cube3d.h"

void ray_range(float *ra)
{
	if (*ra<0)
        *ra +=2*PI;
    if (*ra> 2*PI)
        *ra -=2*PI;
}
float FixAng(float a){ if(a>360.0f){ a-=360.0f;} if(a<0.0f){ a+=360.0f;} return a;}
int compare(float d1, float d2, int i , t_data *img)
{

	int color;

	if((d1 == 0 && (d2 > 0)) ||(d1 != 0 && (d2 != 0)) &&( d1 > d2 ))
	{
		drawline((int []){img->player.x +10/2,img->player.y + img->scale/4,img->verticalp.x,img->verticalp.y},img,(int[]){0xFF0000});
	}
	else
	{
		drawline((int []){img->player.x +10/2 ,img->player.y + img->scale/4,img->horizontalp.x,img->horizontalp.y},img,(int[]){0xFF0000});
	}
	
	return 1;
}


int ray_starter(t_data *img, int loop)
{
	int i;
	float ray;

	i = -1;
	ray = FixAng(img->player.da -30);
	while (++i < img->width)
	{
		img->ra =ray+ i*60/img->width ;
		compare(horizontal_inter(img),vertical_inter(img,0,0),i,img);
	}
	return 1;
}