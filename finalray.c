#include "cube3d.h"
float radiansfd(float angle)
{
	return (angle * PI / 180.0f);
}
void ray_range(float *ra)
{
	if (*ra<0)
        *ra +=2*PI;
    if (*ra> 2*PI)
        *ra -=2*PI;
}
int compare(float d1, float d2, int i , t_data *img)
{
	// printf("\nhi\n");
	int color;
	float finald;
	printf("from ray");
	if(d1 > d2)
	{
		drawline((int []){img->player.x,img->player.y,img->horizontal_points.x,img->horizontal_points.y},img,(int[]){0xFF0000});
		finald = d2;
		color =create_trgb(0,255,0,0);
	}
	else
	{
		drawline((int []){img->player.x,img->player.y,img->vertical_points.x,img->vertical_points.y},img,(int[]){0xFF0000});
		finald = d1;
		color =create_trgb(0,20,0,0);
	}
	float ca  = img->player.da - img->ra;
	if (ca<0)
	{
		ca +=2*PI;
	}
	if (ca> 2*PI)
	{
		ca -=2*PI;
	}
	finald = finald* cos(ca);
	float lh = (img->scale *640)/finald;
	if(lh >640)
		lh=640;
	float lo = 640/2 -lh/2;
	// drawline((int []){(i*8)+529,0,(i*8)+529,lh},img,(int[]){0xFF0000});
	int j=0;
	while (j < 8)
	{
		drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){color});
		j++;
	}
	img->ra += DR/2;
	ray_range(&img->ra);
	printf("\nhiend");
	return 1;
}


int ray_starter(t_data *img, int loop)
{
	int i;

	i = -1;
	while (++i < loop)
	{
        //horizontal detection
		compare(horizontal_inter(img),vertical_inter(img),i,img);
		// project();
	}
	return 1;
}