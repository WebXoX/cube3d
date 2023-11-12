#include "cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_bytes + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
void drawline(float x, float y, float x1, float y1,t_data img, void *mlx_win,int color)
{
    float m = (y1-y)/(x1-x);
    float x2 = x ;
    float y2 = y;
    while (x2<x1)
    {
        my_mlx_pixel_put(&img,800/2 + x2, 800/2+ y2,color); 
        x2 = x2 + 0.001;
        y2 = m*(x2-x)+y;
    }
}
void wall (t_data *img, void * mlx_win, int map[4][4],int color)
{
    int i   =   0;
    int j   =   0;

    coordinate_t    point;
    point.x =    0;   
    point.y =    0;   
    while (i < 4)
    {
        j=0;
        while (j < 4)
        {
                int c = 0;
                if(map[i][j] == 1)
                {
                    while (c < 190)
                    {
                        drawline(point.x - 400,point.y + c - 400,point.x 
                                + 190 - 400,point.y + c - 400, *img, mlx_win,0xFFFFFFF);
                        c++;
                    }
                }
                if(map[i][j] == 2)
                {
					img->player.x = point.x;
					img->player.y = point.y;
				    int cs = 0;
                    while (cs <10)
                    {
						printf("in player y:%f  %f\n",point.y, img->player.y);
						printf("in player x:%f  %f\n",point.x, img->player.x);
                        drawline(point.x - 400 + 100,point.y + cs - 400,point.x + 10 - 400 + 100,point.y + cs - 400,*img,mlx_win,0xFFFFFFF);
                        cs++;
                    }
                }
            printf("x:%f\n",point.x);
            printf("y:%f\n",point.y);
            point.x+=200;
            j++;
        }
        point.x=0;
        point.y+=200;
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
	*win_ptr = mlx_new_window(*mlx_ptr, (*img)->width, (*img)->height, "mlx");
	(*img)->img = mlx_new_image(*mlx_ptr, (*img)->width, (*img)->height);
	(*img)->addr = mlx_get_data_addr((*img)->img, &((*img)->bpp),
			&((*img)->line_bytes), &((*img)->endian));
}

int	move(t_data *img)
{
	int i = 0;
	while (i <10)
	{
			// printf("in player y:%f\n",img->player.y);
			// printf("in player x:%f\n", img->player.x);
		drawline(img->player.x - 400 + 100,img->player.y + i - 400,img->player.x + 10 - 400 + 100,img->player.y + i - 400,*img,img->win_ptr,0x000);
		i++;
	}
	img->player.y += 100;
	i=0;
	while (i <10)
	{
			// printf("in player y:%f\n",img->player.y);
			// printf("in player x:%f\n", img->player.x);
		drawline(img->player.x - 400 + 100,img->player.y + i - 400,img->player.x + 10 - 400 + 100,img->player.y + i - 400,*img,img->win_ptr,0x0FFF);
		i++;
	}

	return (0);
}
// keycode : 13 w
// keycode :: 0	a
// keycode :: 1	s
// keycode :: 2	d
// void	run(t_data *canva);

int	moves(int keycode, t_data *vars)
{
	printf("keycode :: %d\n",keycode);
	if (keycode == 13)
	{
		move(vars);
		// mlx_clear_window((vars)->mlx_ptr, (vars)->win_ptr);
		// mlx_destroy_image(vars->mlx_ptr, vars->img);
		// mlx_destroy_window((vars)->mlx_ptr, (vars)->win_ptr);
		// exit(1);
		// run(vars);
		return (1);
	}
	if (keycode < 0)
		exit(1);
	return (0);
}

void	run(t_data *canva)
{
	mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
		0);
	// mlx_hook(canva->win_ptr, 17, 0, (void *)moves, &(*canva));
	// mlx_key_hook(canva->win_ptr, moves, &(*canva));
	// mlx_mouse_hook(canva->win_ptr, zoom, &(*canva));
	mlx_loop(canva->mlx_ptr);
}

int main(int argc, char **argv)
{
    int map[4][4] = {   {1,1,1,1},
                        {1,0,0,1},
                        {1,0,2,1},
                        {1,1,1,1}   };
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img;
	(void) argv;
	if (argc == 1)
	{
		inits(&img, &mlx_ptr, &win_ptr);

		wall(img,win_ptr,map,0x00FFFFFF);
		// move(img);
		mlx_put_image_to_window(*(img->mlx_ptr), *(img->win_ptr), img->img, 0, 0);
		mlx_key_hook(win_ptr,(void *)moves,img);
		mlx_loop(*(img->mlx_ptr));
		// run(img);
	}
	else
		write(2, "Error Invalid number of arguments!\n", 35);
	return (0);
}
