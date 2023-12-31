#include "cube3d.h"

void	create_arr(char arr[5][3])
{
	ft_strcpy(arr[0], "SO");
	ft_strcpy(arr[1], "NO");
	ft_strcpy(arr[2], "EA");
	ft_strcpy(arr[3], "WE");
}

void	check_valid(char *tex, t_data *canva)
{
	char	arr[5][3];
	int		i;
	int		index;

	index = 2;
	i = 0;
	create_arr(arr);
	while (i < 4)
	{
		if (ft_strncmp(arr[i], tex, 2) == 0)
		{
			while (tex[index] && ft_isspace(tex[index]))
				index++;
			if (index >= 3 && tex[index] && !canva->flag[i])
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

int	check_tex(t_data *canva)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (canva->flag[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	condition_check(t_data *canva, char *line, int fd)
{
	char	*tex;

	tex = ft_strtrim(line, " \n\t\f\r\v");
	canva->cur_tex = &tex;
	if (tex && tex[0] && tex[1])
	{
		if ((tex[0] == 'S' && tex[1] == 'O')
			|| (tex[0] == 'N' && tex[1] == 'O')
			|| (tex[0] == 'W' && tex[1] == 'E')
			|| (tex[0] == 'E' && tex[1] == 'A'))
			check_valid(tex, canva);
		else if (tex[0] == 'F' || tex[0] == 'C')
			add_ceil_floor(tex, canva);
		else
			error_free(canva, 1, "Error: invalid field/field not present\n");
	}
	free(tex);
}

char	*validate_textures(t_data *canva, int fd)
{
	char	*line;

	canva->mlx_ptr = mlx_init();
	line = get_next_line(fd);
	canva->cur_line = &line;
	while (line)
	{
		if (ft_strcmp(line, "\n") && check_tex(canva))
			break ;
		else if (ft_strcmp(line, "\n"))
			condition_check(canva, line, fd);
		canva->first_lines++;
		free(line);
		line = get_next_line(fd);
	}
	canva->cur_tex = 0;
	return (line);
}
