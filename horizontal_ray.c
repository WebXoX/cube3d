#include "cube3d.h"

void ray_horizontal_direction(t_data *img, float tan1)
{
	printf("\nhorizontal\n");
    if (img->ra > PI)
	{
		//left  angles
		img->horizontal_points.y = (((int)img->player.y/img->scale)*img->scale)-0.0001;
		img->horizontal_points.x=(img->player.y-img->horizontal_points.y)*tan1+img->player.x;
		img->horizontal_points.dy = -img->scale;
		img->horizontal_points.dx=-img->horizontal_points.dy*tan1;
	}
	if(img->ra < PI)
	{
		// right side angles
		img->horizontal_points.y = (((int)img->player.y/img->scale)*img->scale)+img->scale;
		img->horizontal_points.x=(img->player.y-img->horizontal_points.y)*tan1+img->player.x;
		img->horizontal_points.dy= img->scale;
		img->horizontal_points.dx=-img->horizontal_points.dy*tan1;
	}
	if(img->ra==0 || img->ra==PI)
	{
		//when angle is 180
		img->horizontal_points.x=img->player.x; img->horizontal_points.y=img->player.y; img->dof=img->final_c;
	}
}

/*horizontal intersection using step method*/
float horizontal_inter(t_data *img)
{
	float tan1;
	int mx;
	int my;

	ray_range(&(img->ra));
	img->dof = 0;
	// tan1 = -1/tan(radiansfd(img->ra));
	tan1 = -1/tan(img->ra);
	ray_horizontal_direction(img,tan1);
	printf("\nhorizontalout\n");

	while(img->dof<img->final_c)
	{
		mx=(int)(img->horizontal_points.x)/img->scale;
		my=(int)(img->horizontal_points.y)/img->scale;
		if((mx < img->longest_row && mx >0 && my < img->final_c && my >0
		&& img->map[my][mx]==1))
			img->dof=img->final_c; //hit
		else
		{
			img->horizontal_points.x+=img->horizontal_points.dx;
			 img->horizontal_points.y+=img->horizontal_points.dy; img->dof+=1;
		}
	}
	printf("\nhorizontalend\n");

	return (sqrt(pow(img->horizontal_points.x - img->player.x, 2) + pow(img->horizontal_points.y - img->player.y, 2)));
}