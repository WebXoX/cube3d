#include "cube3d.h"

void	ray_horizontal_direction(t_data *img, float tan1)
{
	if (sin(radiansfd(img->ra)) > 0.001)
	{
		img->horizontalp.y = (((int)(img->player.y + img->scale / 4)
					/ img->scale) * img->scale) - 0.0001;
		img->horizontalp.x = ((img->player.y + img->scale / 4)
				- img->horizontalp.y) * tan1 + img->player.x + 10 / 2;
		img->horizontalp.dy = -img->scale;
		img->horizontalp.dx = -img->horizontalp.dy * tan1;
	}
	else if (sin(radiansfd(img->ra)) < -0.001)
	{
		img->horizontalp.y = (((int)(img->player.y + img->scale / 4)
					/ img->scale) * img->scale) + img->scale;
		img->horizontalp.x = ((img->player.y + img->scale / 4)
				- img->horizontalp.y) * tan1 + img->player.x + 10 / 2;
		img->horizontalp.dy = img->scale;
		img->horizontalp.dx = -img->horizontalp.dy * tan1;
	}
	else
	{
		img->horizontalp.x = (img->player.x + 10 / 2);
		img->horizontalp.y = (img->player.y + img->scale / 4);
		img->dof = img->final_c - 1;
	}
}

/*horizontal intersection using step method*/
float	horizontal_inter(t_data *img)
{
	float	tan1;
	int		mx;
	int		my;

	img->ra = FixAng(img->ra);
	tan1 = -1 / tan(radiansfd(img->ra));
	img->dof = 0;
	ray_horizontal_direction(img, tan1);
	while (img->dof < img->final_c)
	{
		mx = (int)(img->horizontalp.x) / img->scale;
		my = (int)(img->horizontalp.y) / img->scale;
		if ((mx < img->longest_row && mx >= 0 && my < img->final_c && my >= 0
				&& img->map[my][mx] == 1))
			img->dof = img->final_c;
		else
		{
			img->horizontalp.x += img->horizontalp.dx;
			img->horizontalp.y += img->horizontalp.dy;
			img->dof += 1;
		}
	}
	return (sqrt(pow(img->horizontalp.x - (img->player.x + 10 / 2), 2)
			+ pow(img->horizontalp.y - (img->player.y + img->scale / 4), 2)));
}
