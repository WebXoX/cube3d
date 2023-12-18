#include "cube3d.h"

void ray_range(float *ra)
{
	if (*ra<0)
        *ra +=2*PI;
    if (*ra> 2*PI)
        *ra -=2*PI;
}
float radiansfd(float angle)
{
	return (angle * PI / 180.0f);
}

float FixAng(float a){ if(a>360.0f){ a-=360.0f;} if(a<0.0f){ a+=360.0f;} return a;}
int compare(float d1, float d2, int i , t_data *img)
{

	int color;
	float finald;

	if(d1 > d2)
	{
		// drawline((int []){img->player.x +10/2,img->player.y + img->scale/4,img->vertical_points.x,img->vertical_points.y},img,(int[]){0xFF0000});
		finald = d2;
		// finald = d1;
		color =create_trgb(0,255,0,0);
	}
	else
	{
		// drawline((int []){img->player.x +10/2 ,img->player.y + img->scale/4,img->horizontal_points.x,img->horizontal_points.y},img,(int[]){0xFF0000});
		finald = d1;
		// finald = d2;
		color =create_trgb(0,0,0,0);
		// printf("%f ra\n",img->ra);
	}
	// float ca  = radiansfd(FixAng( img->player.da -img->ra ));
	float ca  = radiansfd(FixAng( img->ra - img->player.da));
	
	// float ca  = (img->player.da - img->ra);
	// if (ca<0)
	// {
	// 	ca +=2*PI;
	// }
	// if (ca> 2*PI)
	// {
	// 	ca -=2*PI;
	// }

	finald = finald* cos(ca) ;
	// finald = finald* cos(ca) ;
	// finald = finald / cos(ca);
	int lh = (img->scale * img->height) / finald;
	if(lh >img->height)
	{
		lh=img->height;
	}
	int lo = img->height/2 - (lh/2);
	// drawline((int []){(i*8)+529,0,(i*8)+529,lh},img,(int[]){0xFF0000});
	int j=0;
	while (j < 8)
	{
		// if((img->ra >90 && img->ra < 180) || (img->ra >180 && img->ra < 270) || (img->ra >270 && img->ra < 360))
		// {
			drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){color});
			// drawline((int []){((i*8) + j),lo- 2/(i+1),(i*8)+j,lh+lo - 2/(i+1)},img,(int[]){create_trgb(0,100,100,0)});
		// }
		// else
		// {
		// 	printf("\nout the angle %f------------------->",img->ra);
		// 	drawline((int []){((i*8) + j),lo,(i*8)+j,lh+lo},img,(int[]){color});
		// }
		j++;
	}
		
	
	
	if(d1 > d2)
		drawline((int []){img->player.x +10/2,img->player.y + img->scale/4,img->vertical_points.x,img->vertical_points.y},img,(int[]){0xFF0000});
	else
		drawline((int []){img->player.x +10/2 ,img->player.y + img->scale/4,img->horizontal_points.x,img->horizontal_points.y},img,(int[]){0xFF0000});
	// player(img);
	// img->ra += DR/2;
	img->ra=FixAng(img->ra + 0.5); 
	// ray_range(&img->ra);
	// img->ra = FixAng(img->ra);
	// printf("\nhiend");
	return 1;
}


int ray_starter(t_data *img, int loop)
{
	int i;

	i = -1;
    // img->ra = img->player.da +PI;
    img->ra = FixAng(img->player.da -30);
	while (++i < loop)
	{
        //horizontal detection
		compare(horizontal_inter(img),vertical_inter(img),i,img);
		// printf("loop rayy%f\n",);
		// img->ra += DR/2;
		// ray_range(&img->ra);
		// project();
	}
	printf("yes\n");
	tile(img);
	wall(img);
	player(img);
	printf("yesend\n");

	return 1;
}