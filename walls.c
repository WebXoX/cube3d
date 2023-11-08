#include "cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
void drawline(float x, float y, float x1, float y1,t_data img, void *mlx_win)
{
    float m = (y1-y)/(x1-x);
    float x2 = x ;
    float y2 = y;
    while (x2<x1)
    {
        my_mlx_pixel_put(&img,800/2 + x2, 800/2+ y2,0x00FFFFF); 
        x2 = x2 + 0.001;
        y2 = m*(x2-x)+y;
    }
}
void wall(t_data img, void * mlx_win, int map[4][4],int color)
{
    int i = 0;
    int j = 0;

    coordinate_t point;
    point.x=0;   
    point.y=0;   
  while (i < 4)
  {
    j=0;
    while (j < 4)
    {
        int c = 0;

        if(map[i][j] == 1)
        {
            while (c <100)
            {
                    drawline(point.x,point.y+c,point.x+100,point.y+c,img,mlx_win);
                c++;
            }
        }
        printf("x:%f\n",point.x);
        printf("y:%f\n",point.y);
        point.x+=100;
        j++;
    }
        point.x=0;
        point.y+=100;

    i++;
  }
  
}

void inits(t_data **img, void **mlx_ptr, void **win_ptr)
{
	(*img) = calloc(1, sizeof(t_data));
	if (!(*img))
		return ;
	(*img)->mlx_ptr = mlx_ptr;
	(*img)->win_ptr = win_ptr;
	(*img)->width = 800;
	(*img)->height = 800;
	*mlx_ptr = mlx_init();
	*win_ptr = mlx_new_window(*mlx_ptr, (*img)->width+100, (*img)->height+100, "mlx");
	(*img)->img = mlx_new_image(*mlx_ptr, (*img)->width, (*img)->height);
	(*img)->addr = mlx_get_data_addr((*img)->img, &((*img)->bpp),
			&((*img)->line_bytes), &((*img)->endian));
}

int main(int argc, char **argv)
{
    int map[4][4] = {   {1,1,1,1},
                        {1,0,0,1},
                        {1,0,0,1},
                        {1,1,1,1}   };
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
	(void) argv;
	if (argc == 1)
	{
		inits(&img, &mlx_ptr, &win_ptr);

		wall(*img,win_ptr,map,0x00FF0000);

		mlx_put_image_to_window(*(img->mlx_ptr), *(img->win_ptr), img->img, -400, -400);
		mlx_loop(*(img->mlx_ptr));
	}
	else
		write(2, "Error Invalid number of arguments!\n", 35);
	return (0);

}