#include "cube3d.h"

void    run(t_data *canva)
{
    mlx_put_image_to_window(canva->mlx_ptr, canva->win_ptr, (canva)->img, 0,
        0);
        mlx_hook(canva->win_ptr, 2, 1L << 0, moves, &(*canva));
        mlx_hook(canva->win_ptr, 3, 1L << 1, moves, &(*canva));
    // mlx_key_hook(canva->win_ptr, moves, &(*canva));
    mlx_loop(canva->mlx_ptr);
}

int move(t_data *img,float x, float y)
{
    int i =0;
    // int ratio_y = img->height/4;
    // int ratio_x = img->width/6;
    coordinate_t point;
    point.x=0;
    point.y=0;
    while (i < img->height)
    {

        drawline((int[]){0,i ,img->width ,i} ,img, (int[]){0x045680});
        i++;
    }
    //wall and tile re draw
    tile(img);
    ray_starter(img,90);
    wall(img);
    player(img);
    img->player.y -= y;
    img->player.x -= x;
    i=0;

    // printf("hi move \n");
    drawline((int[]){img->player.x ,img->player.y ,img->player.x -img->player.dx*20,img->player.y - img->player.dy *20},img,(int[]){0x735674});

    run(img);
    return (0);
}
void make_zero(t_data *canva)
{
    int i = 0;
    canva->longest_row = 0;
    ft_bzero(canva->tex, 4);
    while(i < 6)
        canva->flag[i++] = 0;
    canva->player_count = 0;
    canva->first_lines = 0;
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
    while (++i < canva->height)
        drawline((int[]){0,i ,canva->width ,i} ,canva, (int[]){0x045680});
    wall(canva);
    tile(canva);
    // ray_starter(canva,60);
    player(canva);
    drawline((int[]){canva->player.x ,canva->player.y ,canva->player.x -canva->player.dx*20,canva->player.y - canva->player.dy *20},canva,(int[]){0x735674});
    run(canva);
}
int main(int argc, char *argv[])
{

    t_data canva;
	int fd;
	char *line;
	char *nl_pos;
	int *numbers;
	int count =0;
    int i = 0;
    int k = 0;
	int line_count = 0;
	int length;
    canva.player_count = 0;

	if(argc > 1)
	{
		fd = open(argv[1], O_RDWR);
         make_zero(&canva);
		line = validate_textures(&canva, fd);
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
				length = ft_strlen(line);
				if (length > canva.longest_row)
					canva.longest_row = length;
				line = get_next_line(fd);
				line_count++;
			}
		}
        // printf(" %d\n", canva.longest_row);
		close(fd);
		fd = open(argv[1], O_RDWR);
		canva.map = malloc(sizeof(int*) * line_count);
		fd = open(argv[1], O_RDWR);
		line = get_next_line(fd);
		canva.lengths = malloc(sizeof(int)*line_count);
        printf("%d\n", canva.first_lines);
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
				nl_pos = ft_strchr(line, '\n');
				if (nl_pos)
					nl_pos[0] = 0;
				canva.map[count] = get_numbers(line, &canva, count);

				free(line);
				line = get_next_line(fd);
				count++;
			}
		}
		close(fd);
			printf("%d-????count-------->\n",canva.player_count);

		if(!(canva.player_count))
		{
			printf("%d-????count-------->\n",canva.player_count);

			error_free(&canva, -1, "Error! no player present!\n");
		}
		canva.final_c = count;
		validate_zeroes(canva.map, &canva);
		validate_spaces(canva.map, &canva);
	}
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

            }
            // else
            //     printf(" ");

        }
            printf("::\n");
    }

    canva.height = 640;
    canva.width = 960;
    canva.scale = 16;
    // canva.player.da = 90.0f * PI/180.0f;
    canva.player.da = 0 ;
    canva.player.dx = cos(radiansfd(canva.player.da));
    canva.player.dy = sin(radiansfd(canva.player.da));

    // canva.player.dx = -1;
    // canva.player.dy = 0;
    // canva.camaera.x = 0;
    // canva.camaera.y = 1;
    canva.mlx_ptr = mlx_init();
    call( &canva);
    return (0);
}

