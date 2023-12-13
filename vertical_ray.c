#include "cube3d.h"

// void ray_vertical(t_data *img, float tan2)
// {
// 	if (img->ra>PI/2 && img->ra <3*PI/2)
// 	{
// 		img->vertical_points.x = (((int)img->player.x/img->scale)*img->scale)-0.0001;
// 		img->vertical_points.y=(img->player.x-img->vertical_points.x)*tan2+img->player.y;
// 		img->vertical_points.dx = -img->scale;
// 		img->vertical_points.dy=-img->vertical_points.dx*tan2;
// 	}
// 	else  if(img->ra<PI/2 || img->ra >3*PI/2)
// 	{
// 		img->vertical_points.x = (((int)img->player.x/img->scale)*img->scale)+img->scale;
// 		img->vertical_points.y=(img->player.x-img->vertical_points.x)*tan2+img->player.y;
// 		img->vertical_points.dx= img->scale;
// 		img->vertical_points.dy=-img->vertical_points.dx*tan2;
// 	}
// 	else if(img->ra==0 || img->ra==PI)
// 	{
// 		img->vertical_points.x=img->player.x; img->vertical_points.y=img->player.y; img->dof=0;
// 	}
// }


void ray_vertical(t_data *img, float tan2)
{
	if (cos(radiansfd(img->ra))> 0.001)
	{
		img->vertical_points.x = (((int)img->player.x/img->scale)*img->scale)-0.0001;
		img->vertical_points.y=(img->player.x-img->vertical_points.x)*tan2+img->player.y;
		img->vertical_points.dx = -img->scale;
		img->vertical_points.dy=-img->vertical_points.dx*tan2;
	}
	else  if(cos(radiansfd(img->ra))<-0.001)
	{
		img->vertical_points.x = (((int)img->player.x/img->scale)*img->scale)+img->scale;
		img->vertical_points.y=(img->player.x-img->vertical_points.x)*tan2+img->player.y;
		img->vertical_points.dx= img->scale;
		img->vertical_points.dy=-img->vertical_points.dx*tan2;
	}
	else
	{
		img->vertical_points.x=img->player.x; img->vertical_points.y=img->player.y; img->dof=img->longest_row-1;
	}
}

/*horizontal intersection using step method*/
float vertical_inter(t_data *img)
{
	int mx;
	int my;
    float tan2;
	// ray_range(&((img->ra)));
	img->ra = FixAng(img->ra);
	
	tan2 = -tan(radiansfd(img->ra));
	// tan2 = -tan(img->ra);
	img->dof =0;

	ray_vertical(img,tan2);
    while(img->dof<img->longest_row)
	{
        mx=(int)(img->vertical_points.x)/img->scale;
		 my=(int)(img->vertical_points.y)/img->scale;
        if((mx < img->longest_row && mx >0 && my < img->final_c && my >0
        && img->map[my][mx]==1)){ img->dof=img->longest_row; }//hit
        else
		{
			img->vertical_points.x+=img->vertical_points.dx; img->vertical_points.y+=img->vertical_points.dy; img->dof+=1;
		}//check next horizontal

	}
	// return(cos(radiansfd(img->ra))*(img->vertical_points.x - img->player.x)-sin(radiansfd(img->ra))*(img->vertical_points.y - img->player.y));
	return( sqrt(pow(img->vertical_points.x - img->player.x, 2) + pow(img->vertical_points.y - img->player.y, 2)));
}
