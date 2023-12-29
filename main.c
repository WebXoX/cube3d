#include "cube3d.h"
int move(t_data *img);

void    run(t_data *canva)
{
    mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,0);
    mlx_hook(canva->win_ptr, 2, 1L << 0, moves, &(*canva));
    mlx_hook(canva->win_ptr, 3, 1L << 1, moves, &(*canva));
    mlx_loop(canva->mlx_ptr);
}

int move(t_data *img)
{
    int i =0;

      while (i < img->height)
    {
        if(i < img->height/2)
            drawline((int[]){0,i ,img->width ,i} ,img, (int[]){create_trgb(0,img->ceil[0], img->ceil[1],img->ceil[2])});
        else
            drawline((int[]){0,i ,img->width ,i} ,img, (int[]){create_trgb(0,img->floor[0], img->floor[1],img->floor[2])});
        i++;
    }
    ray(img);
    tile(img);
	ray_starter(img,120);
    wall(img);
    player(img);
    run(img);
    return (1);
}
void make_zero(t_data *canva)
{
    int i = -1;
    canva->longest_row = 0;
	 canva->cur_tex = 0;
	  canva->cur_line = 0;
    ft_bzero(canva->tex, 4);
    while(++i < 6)
	{
        canva->flag[i] = 0;
		if(i < 4)
			canva->texture2[i].img = 0;
    }
	canva->map =0;
    canva->player_count = 0;
	canva->final_c = 0;
    canva->first_lines = 0;
	canva->lengths=0;
}
void    call(t_data *canva)
{
    int     status;
    int     i;

	i = -1;
    canva->img = mlx_new_image(canva->mlx_ptr, canva->width, canva->height);
    canva->addr = mlx_get_data_addr(canva->img, &canva->bpp,
            &canva->line_bytes, &canva->endian);
    canva->win_ptr = mlx_new_window(canva->mlx_ptr, canva->width, canva->height,
                "cub3d");
    canva->player.x = (canva->scale *canva->cx)  + canva->scale/4;
    canva->player.y = (canva->scale *canva->cy) + canva->scale/4;
    while (i < canva->height)
    {
        if(i < canva->height/2)
            drawline((int[]){0,i ,canva->width ,i} ,canva, (int[]){create_trgb(0,canva->ceil[0], canva->ceil[1],canva->ceil[2])});
        else
            drawline((int[]){0,i ,canva->width ,i} ,canva, (int[]){create_trgb(0,canva->floor[0], canva->floor[1],canva->floor[2])});
        i++;
    }
    ray(canva);
    wall(canva);
    tile(canva);
    player(canva);
    run(canva);
}
int main(int argc, char *argv[])
{

    t_data canva;
	int fd;
	char *line;
	char *nl_pos;
	int *numbers;
    int i = 0;
    int k = 0;
	int line_count = 0;
	int length;
    canva.player_count = 0;

    canva.player.dx = 0;
    canva.player.dy = 0;
    canva.camaera.x = 0;
    canva.camaera.y = 0;

	if(argc > 1)
	{
         make_zero(&canva);
		fd = open(argv[1], O_RDWR);
		if(fd < 0)
			error_free(&canva, -1, "Error: Invalid file\n");
		canva.fd = fd;
         make_zero(&canva);
        //  printf("HELLO %p\n",canva.texture2[0].img );
    canva.mlx_ptr = mlx_init();
		line = validate_textures(&canva, fd);
		canva.cur_tex = 0;
		while(line)
		{
			if(ft_strcmp(line, "\n") == 0)
			{
				while(line)
				{
					if (ft_strcmp(line, "\n") == 0)
					{
						free(line);
						line = get_next_line(fd);
						canva.cur_line = &line;
					}
					else
					{
			            // printf("%d-????count-------->\n",canva.player_count);

						printf("ERROR!!!!!\n");
						exit(0);
                        // free(line);
                        // line = NULL;
					}
                    printf("stuck\n");
				}
			}
			else
			{
				length = ft_strlen(line) - 1;
				if (length > canva.longest_row)
					canva.longest_row = length;
				free(line);
				line = get_next_line(fd);
				line_count++;
			}
		}
        // printf(" %d\n", canva.longest_row);
		close(fd);
		// fd = open(argv[1], O_RDWR);
		canva.map = ft_calloc(sizeof(int*) , line_count);
		fd = open(argv[1], O_RDWR);
		canva.fd = fd;
		line = get_next_line(fd);
		canva.lengths = malloc(sizeof(int)*line_count);
		while (line)
		{
            if(i++ < canva.first_lines)
			{
				free(line);
				line = get_next_line(fd);
			}
			else if (ft_strcmp(line, "\n") == 0)
				{
					free(line);
					line = get_next_line(fd);
				}
			else if(line)
			{
				canva.cur_line = &line;
				nl_pos = ft_strchr(line, '\n');
				if (nl_pos)
					nl_pos[0] = 0;
				canva.map[canva.final_c] = get_numbers(line, &canva, canva.final_c);
				free(line);
				line = get_next_line(fd);
				canva.final_c++;
			}
		}
		close(fd);
		// canva.final_c = count;
		if(!(canva.player_count))
			error_free(&canva, -1, "Error: no player present!\n");
		validate_zeroes(canva.map, &canva);
		validate_spaces(canva.map, &canva);
    for (size_t i = 0; i < canva.final_c; i++)
    {
        for (size_t j = 0; j < canva.longest_row; j++)
        {
            printf("%d",canva.map[i][j]);
            if(canva.map[i][j]==2)
            {
                canva.cx = j;
                canva.cy = i;
                // printf("%d\n",canva.cx);
                // printf("%d\n",canva.cy);

                printf("\n%f\n",canva.cx);
                printf("%f\n",canva.cy);
            }
            // else
            //     printf(" ");

        }
            printf("::\n");
    }

    canva.height = 1020;
    canva.width = 1060;
    canva.scale = 8;
    canva.player.da = 90.0f * PI/180.0f;
    // canva.player.da = 90 ;
    // canva.player.dx = cos(radiansfd(canva.player.da));
    // canva.player.dy = sin(radiansfd(canva.player.da));

    // canva.player.dx = -1;
    // canva.player.dy = 0;
    // canva.camaera.x = 0;
    // canva.camaera.y = 0.66;
    call( &canva);
	}
    return (0);
}

