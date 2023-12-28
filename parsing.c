#include "cube3d.h"

void error_free(t_data *canva, int fd, char *msg)
{
	if(fd != -1)
		close(fd);
	// if(canva)
	// {
		write(2, msg, ft_strlen(msg));
		// free(canva->map);
		int i = 0;
		// printf("%s\n", canva.tex[i]);
		// while(canva.tex[i] && i < 4)
		// 	free(canva.tex[i++]);
		// if(canva.lengths)
		// 	free(canva.lengths);
		// free(canva);
		exit(0);
	// }
}
int	ft_isspace(char c)
{
	if ((c >= 9 && c < 13) || c == 32)
		return (1);
	return (0);
}

int ft_isplayer(char c, t_data *data)
{
	if(c=='N')
	{
		data->camaera.x = 0.66;
		data->player.dy = -1.0;
		data->directionstart = 1;
	}
	else if(c=='S')
	{
		data->player.dy += 1;
		data->camaera.x -= 0.66;
		data->directionstart = 1;

	}
	else if(c=='E')
	{
		data->player.dx=1;
		data->camaera.y-= 0.66;
		data->directionstart = -1;

	}
	else if(c== 'W')
	{
		data->player.dx-=1;
		data->camaera.y+= 0.66;
		data->directionstart = -1;

	}
	else
		return 0;
	return (1);
}

void	ft_free(char **mat)
{
	int	i;

	i = 0;
	if (mat)
	{
		while (mat[i])
			free(mat[i++]);
		free(mat);
		mat = NULL;
	}
}

void printf_all(int *nums, int num)
{
	int i = -1;
	while(++i < num)
		printf("%d ", nums[i]);
	printf("\n");
}

int *get_numbers(char *line, t_data *canva, int row_num)
{
	int i = -1;
	int *numbers;
	t_list *cur;

	numbers = malloc(sizeof(int) * canva->longest_row);
	printf("%s", line);
	while(line[++i])
	{

		if ((line[i] == '0' || line[i] == '1'))
			numbers[i]=line[i] - '0';
		else if(!canva->player_count && ft_isplayer(line[i],canva))
		{
			(canva->player_count)++;
			printf("%d-????count-------.\n",canva->player_count);
			numbers[i]=2;
		}
		else if(line[i] == ' ')
			numbers[i] = ' ';
		else
		{
			printf("%c", line[i]);
			printf("???ERORRRRR!!!!\n");
			exit(0);
		}
	}
	canva->lengths[row_num] = i;
	while(i < canva->longest_row)
		numbers[i++] = ' ';
		// printf(" %d %d ", i, canva.longest_row);
	return numbers;
}

void validate_zeroes(int **map, t_data *canva)
{
	int i = 0;
	int j = 0;
	while(i < canva->final_c)
	{
		j = 0;
		while(j < canva->longest_row)
		{
			if(map[i][j] == 0 || ft_isplayer(map[i][j],canva))
			{
				int k = i;
				int l = j;
				while(k >= 0)
				{
					if( j < canva->lengths[k] && map[k][j] == 1)
						break;
					else if (j > canva->lengths[k])
					{
						printf("ERRORZ1!!!\n");
						exit(0);
					}
					k--;
				}
				if(k == -1)
				{
					printf("ERRORZ2!!!\n");
					exit(0);
				}
				k = i;
				while(k < canva->final_c)
				{
					if( j < canva->lengths[k] && map[k][j] == 1)
						break;
					else if (j > canva->lengths[k])
					{
						printf("ERRORZ3!!!\n");
						exit(0);
					}
					k++;
				}
				if(k == canva->final_c)
				{
					printf("ERRORZ4!!!\n");
					exit(0);
				}

				while(l >= 0)
				{
					if( l < canva->lengths[i] && map[i][l] == 1)
						break;
					l--;
				}
				if(l == -1)
				{
					printf("ERRORZ5!!!\n");
					exit(0);
				}
				l = j;
				while(l < canva->lengths[i])
				{
					if( l < canva->lengths[i] && map[i][l] == 1)
						break;
					l++;
				}
				if(l == canva->lengths[i])
				{
					printf("ERRORZ6!!!\n");
					exit(0);
				}
			}
		j++;
		}
		i++;
	}

}

void validate_spaces(int **map, t_data *canva)
{
	int i = 0;
	int j;
	int wrong;
	while(i < canva->final_c)
	{
			j = 0;
		while(j < canva->lengths[i])
		{
			wrong = 0;
			if(map[i][j] == ' ')
			{
				if(i > 0 && j > canva->lengths[i - 1])
					if(!(map[i - 1][j] == 1 || map[i - 1][j] == ' '))
						wrong++;
				if(j + 1 < canva->lengths[i])
					if(!(map[i][j + 1] == 1 || map[i][j + 1] == ' '))
						wrong++;
				if(i + 1 < canva->final_c && j > canva->lengths[i + 1])
					if(!(map[i + 1][j] == 1 || map[i + 1][j] == ' '))
						wrong++;
				if(j > 0)
					if(!(map[i][j - 1] == 1 || map[i][j - 1] == ' '))
						wrong++;
				if(wrong)
					{
					printf("ERROR!!!\n");
					exit(0);
				}
			}
			j++;
		}
		i++;
	}

}

int tex_len(char **arr)
{
	int i = 0;
	while(arr[i])
		i++;
	return i;
}

char *join_all(char **rgb)
{
	int i = 0;
	char *new;
	char *oldnew;
	new = ft_strdup("");
	while(rgb[i])
	{
		oldnew = new;
		new = ft_strjoin(new, rgb[i++]);
		free(oldnew);
	}
	return new;
}


void check_valid(char *tex, t_data *canva)
{
	char arr[5][3];
	ft_strcpy(arr[0], "SO");
	ft_strcpy(arr[1], "NO");
	ft_strcpy(arr[2], "EA");
	ft_strcpy(arr[3], "WE");
	int i = 0;
	int fd;
	int index = 2;
	while(i < 4)
	{
		if(ft_strncmp(arr[i], tex, 2) == 0)
		{
			while(tex[index] && ft_isspace(tex[index]))
				index++;
			if(index >= 3 && tex[index] && !canva->flag[i])
			{
				canva->flag[i] = 1;
				canva->tex[i] = ft_strdup(&tex[index]);
			}
			else
				{
					printf("ERROR!!!!\n");
					exit(0);
				}

		}
		i++;
	}
}

int extract_num(char *str, t_data *canva, int val, char type)
{
	int i = 0;
	int num_count = 0;
	while(str[i] && ft_isspace(str[i]))
		i++;
	while(str[i + num_count])
	{
		if(ft_isdigit(str[i + num_count]))
			num_count++;
		else
			break;
	}
	i = i + num_count;
	if(num_count > 3 || (str[i] && (!ft_isspace(str[i]) && str[i] != ',')) || num_count == 0)
	{
		printf("ERRORo!!\n");
		exit(0);
	}
	if(type == 'F')
		canva->floor[val] = ft_atoi(str);
	else if(type == 'C')
		canva->ceil[val] = ft_atoi(str);
	while(str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == ',')
		return i + 1;
	return i;
}

void add_ceil_floor(char *tex, t_data *canva)
{
	int fd;
	int index;

	if(tex[0] == 'C' && !canva->flag[5])
		canva->flag[5] = 1;
	else if(tex[0] == 'F' && !canva->flag[4])
		canva->flag[4] = 1;
	else
	{
		printf("ERROR!!\n");
		exit(0);
	}
	if(tex[1] && ft_isspace(tex[1]))
	{
		index = extract_num(&tex[1], canva, 0, tex[0]);
		index += extract_num(&tex[index + 1], canva, 1, tex[0]);
		if(tex[index])
			index += extract_num(&tex[index + 1], canva, 2, tex[0]);
		if(tex[index + 1] || tex[index] ==',')
		{
			printf("error\n");
			exit(0);
		}
	}
	else
	{
		printf("ERROR!!\n");
		exit(0);
	}

}

int check_tex(t_data *canva)
{
	int i = 0;
	i = 0;
	while(i < 6)
	{
		if(canva->flag[i])
			i++;
		else
			return 0;
	}
	return 1;
}

char *validate_textures(t_data *canva, int fd)
{
	char *line;

	line = get_next_line(fd);
	while(line)
	{
		// printf("%s\n", line);
		if (ft_strcmp(line, "\n") && check_tex(canva))
			return line;
		else if(ft_strcmp(line, "\n"))
		{
			char *tex = ft_strtrim(line, " \n\t\f\r\v");
			if(tex && tex[0] && tex[1])
			{
				if((tex[0] =='S' && tex[1] == 'O') ||
					(tex[0] =='N' && tex[1] == 'O') ||
					(tex[0] =='W' && tex[1] == 'E') ||
					(tex[0] =='E' && tex[1] == 'A'))
				{

					check_valid(tex, canva);
				}
				else if(tex[0] =='F' || tex[0] == 'C')
				{
					add_ceil_floor(tex, canva);
				}
				else
					error_free(canva, fd, "ERRORRRR\n");
			}
			free(tex);
		}
				// else
				// 	error_free(canva, fd, "ERRORRRR\n");
		canva->first_lines++;
		free(line);
		line = get_next_line(fd);
	}
	return line;
	// printf("%s\n", line);

}


// int main(int argc, char **argv)
// {
	// t_data *canva;
	// int fd;
	// char *line;
	// char *nl_pos;
	// int *numbers;
	// int count =0;
	// int line_count = 0;
	// int length;


	// canva = ft_calloc(1, sizeof(t_data));
	// if(argc > 1)
	// {
	// 	fd = open(argv[1], O_RDWR);
	// 	line = get_next_line(fd);
	// 	while(line)
	// 	{
	// 		if(ft_strcmp(line, "\n") == 0)
	// 		{
	// 			while(line)
	// 			{
	// 				if (ft_strcmp(line, "\n") == 0)
	// 				{
	// 					free(line);
	// 					line = get_next_line(fd);
	// 				}
	// 				else
	// 				{
	// 					printf("ERROR!!!!!\n");
	// 					exit(0);
	// 				}
	// 			}
	// 		}
	// 		else
	// 		{
	// 			length = ft_strlen(line);
	// 			if (length > canva->longest_row)
	// 				canva->longest_row = length;
	// 			line = get_next_line(fd);
	// 			line_count++;
	// 		}
	// 	}
	// 	close(fd);
	// 	fd = open(argv[1], O_RDWR);
	// 	canva->map = malloc(sizeof(int*) * line_count);
	// 	fd = open(argv[1], O_RDWR);
	// 	line = get_next_line(fd);
	// 	canva->lengths = malloc(sizeof(int)*line_count);
	// 	while (line)
	// 	{
	// 		if (ft_strcmp(line, "\n") == 0)
	// 			{
	// 				free(line);
	// 				line = get_next_line(fd);
	// 			}
	// 		else if(line)
	// 		{
	// 			nl_pos = ft_strchr(line, '\n');
	// 			if (nl_pos)
	// 				nl_pos[0] = 0;
	// 			canva->map[count] = get_numbers(line, canva, count);
	// 			free(line);
	// 			line = get_next_line(fd);
	// 			count++;
	// 		}
	// 	}
	// 	close(fd);
	// 	if(!(canva->player_count))
	// 	{
	// 		printf("ERROR!!!!!\n");
	// 		exit(0);
	// 	}
	// 	canva->final_c = count;
	// 	validate_zeroes(canva->map, canva);
	// 	validate_spaces(canva->map, canva);
	// }
	// return 0;
// }

