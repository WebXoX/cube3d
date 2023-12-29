#include "cube3d.h"

void error_free(t_data *canva, int fd, char *msg)
{
	if(fd != -1)
		close(canva->fd);
		if(canva->cur_tex)
			free(*canva->cur_tex);
		if(canva->cur_line)
			free(*canva->cur_line);
			int i = -1;
		printf("%p\n",canva->texture2[0].img );
		while(++i < 4)
			if(canva->texture2[i].img != 0)
				mlx_destroy_image(canva->mlx_ptr, canva->texture2[i].img);
		write(2, msg, ft_strlen(msg));
		if(canva->map)
		{
			i = -1;
			while(++i < canva->final_c)
			{
				if(canva->map[i])
					free(canva->map[i]);
			}
			free(canva->map);
		}
		if(canva->lengths)
			free(canva->lengths);
		exit(0);
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
	while(line[++i])
	{

		if ((line[i] == '0' || line[i] == '1'))
			numbers[i]=line[i] - '0';
		else if(!canva->player_count && ft_isplayer(line[i],canva))
		{
			(canva->player_count)++;
			numbers[i]=2;
		}
		else if(line[i] == ' ')
			numbers[i] = ' ';
		else
		{
			free(numbers);
			error_free(canva, -1, "Error: Invalid characters\n");
		}
	}
	canva->lengths[row_num] = i;
	while(i < canva->longest_row)
		numbers[i++] = ' ';
	return numbers;
}

// void validate_zeroes(int **map, t_data *canva)
// {

// 	int i = 0;
// 	int j = 0;
// 	int wrong;
// 	while(i < canva->final_c)
// 	{
// 			j = 0;
// 		while(j < canva->lengths[i])
// 		{
// 			wrong = 0;
// 			if(map[i][j] == 0)
// 			{
// 				// printf("%d\n", map[i][j]);
// 				if(i > 0)
// 					if(map[i - 1][j] == ' ')
// 						wrong++;
// 				if(j + 1 < canva->longest_row)
// 					if(map[i][j + 1] == ' ')
// 						wrong++;
// 				if(i + 1 < canva->final_c)
// 					if(map[i + 1][j] == ' ')
// 						wrong++;
// 				if(j > 0)
// 					if(map[i][j - 1] == ' ')
// 						wrong++;
// 				if(wrong)
// 					error_free(canva, 1, "Error: Invalid zeroes\n");
// 			}
// 			j++;
// 		}
// 		i++;
// 	}

// }

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
						error_free(canva, -1, "Error: Invalid zeroes\n");
					k--;
				}
				if(k == -1)
					error_free(canva, -1, "Error: Invalid zeroes\n");
				k = i;
				while(k < canva->final_c)
				{
					if( j < canva->lengths[k] && map[k][j] == 1)
						break;
					else if (j > canva->lengths[k])
						error_free(canva, -1, "Error: Invalid zeroes\n");
					k++;
				}
				if(k == canva->final_c)
					error_free(canva, -1, "Error: Invalid zeroes\n");

				while(l >= 0)
				{
					if( l < canva->lengths[i] && map[i][l] == 1)
						break;
					l--;
				}
				if(l == -1)
					error_free(canva, -1, "Error: Invalid zeroes\n");
				l = j;
				while(l < canva->lengths[i])
				{
					if( l < canva->lengths[i] && map[i][l] == 1)
						break;
					l++;
				}
				if(l == canva->lengths[i])
					error_free(canva, -1, "Error: Invalid zeroes\n");
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
				if(i > 0)
					if(!(map[i - 1][j] == 1 || map[i - 1][j] == ' '))
						wrong++;
				if(j + 1 < canva->longest_row)
					if(!(map[i][j + 1] == 1 || map[i][j + 1] == ' '))
						wrong++;
				if(i + 1 < canva->final_c)
					if(!(map[i + 1][j] == 1 || map[i + 1][j] == ' '))
						wrong++;
				if(j > 0)
					if(!(map[i][j - 1] == 1 || map[i][j - 1] == ' '))
						wrong++;
				if(wrong)
					error_free(canva, 1, "Error: Invalid spaces\n");
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

void validate_file(char *file, t_data *canva, int i)
{
<<<<<<< HEAD
	printf(".........%s\n",file);
=======
	printf("%s\n", file);
	// 	exit(0);
>>>>>>> 01e355a6a4b680920f14508a5cf0858527a8a589
	canva->texture2[i].img = mlx_xpm_file_to_image(canva->mlx_ptr, file,
		&canva->texture2[i].img_wid, &canva->texture2[i].img_hei);
	if(canva->texture2[i].img <=0 || ft_strcmp(ft_strstr(file, "."), ".xpm") != 0)
		error_free(canva, 1, "Error: Invalid texture file\n");
	canva->texture2[i].addr = (int *)mlx_get_data_addr(canva->texture2[i].img,
		 &canva->texture2[i].bits_per_pixel, &canva->texture2[i].img_hei,
		 	&canva->texture2[i].endian);
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
				validate_file(canva->tex[i], canva, i);
			}
			else
				error_free(canva, 1, "Error: repeated texture\n");

		}
		i++;
	}
}

int num_valid(char *str, int i, int num_count)
{
	while(str[i + num_count])
	{
		if(ft_isdigit(str[i + num_count]))
			num_count++;
		else
			break;
	}
	return num_count;
}

int extract_num(char *str, t_data *canva, int val, char type)
{
	int i;
	int num_count;

	i = 0;
	while(str[i] && ft_isspace(str[i]))
		i++;
	num_count = num_valid(str, i, 0);
	i = i + num_count;
	
	if(num_count > 3 || (str[i] && (!ft_isspace(str[i]) && str[i] != ',')) || num_count == 0)
	{
		
		error_free(canva, 1, "Error: RGB values are incorrect\n");
	}
	if(type == 'F' && ft_atoi(str) <= 255)
		canva->floor[val] = ft_atoi(str);
	else if(type == 'C' && ft_atoi(str) <= 255)
		canva->ceil[val] = ft_atoi(str);
	else
		error_free(canva, 1, "Error: RGB values are incorrect\n");
	while(str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && str[i] == ',')
		return i + 1;
	else if(val != 2)
		error_free(canva, 1, "Error: RGB values are incorrect\n");
	return i;
}

void extract_rgb(char *tex, t_data *canva)
{
	int index;
	
	if(tex[1] && ft_isspace(tex[1]))
	{
		printf("%s\n", &tex[1]);
			
		index = extract_num(&tex[1], canva, 0, tex[0]);
		index += extract_num(&tex[index + 1], canva, 1, tex[0]);
		if(tex[index])
			index += extract_num(&tex[index + 1], canva, 2, tex[0]);
		if(tex[index + 1] || tex[index] ==',')
			error_free(canva, 1, "Error: RGB values are incorrect\n");
	}
	else
		error_free(canva, 1, "Error: RGB values are incorrect\n");
}

void add_ceil_floor(char *tex, t_data *canva)
{
	int fd;

	if(tex[0] == 'C' && !canva->flag[5])
		canva->flag[5] = 1;
	else if(tex[0] == 'F' && !canva->flag[4])
		canva->flag[4] = 1;
	else
		error_free(canva, 1, "Error: Repeated Ceiling or floor\n");
	extract_rgb(tex, canva);
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

void condition_check(t_data *canva, char *line, int fd)
{
	char *tex;
	tex = ft_strtrim(line, " \n\t\f\r\v");
	canva->cur_tex = &tex;
	
	if (tex && tex[0] && tex[1])
	{
		if((tex[0] =='S' && tex[1] == 'O') ||
			(tex[0] =='N' && tex[1] == 'O') ||
			(tex[0] =='W' && tex[1] == 'E') ||
			(tex[0] =='E' && tex[1] == 'A'))
			check_valid(tex, canva);
		else if(tex[0] =='F' || tex[0] == 'C')
			add_ceil_floor(tex, canva);
		else
			error_free(canva, 1, "Error: invalid field\n");
	}
	free(tex);
}

char *validate_textures(t_data *canva, int fd)
{
	char *line;

	line = get_next_line(fd);
	canva->cur_line = &line;
	while(line)
	{
		if (ft_strcmp(line, "\n") && check_tex(canva))
			return line;
		else if(ft_strcmp(line, "\n"))
			condition_check(canva, line, fd);
		canva->first_lines++;
		free(line);
		line = get_next_line(fd);
	}
	return line;
}
