#include "cube3d.h"

int	*get_numbers(char *line, t_data *canva, int row_num)
{
	int		i;
	int		*numbers;
	t_list	*cur;

	i = -1;
	numbers = malloc(sizeof(int) * canva->longest_row);
	while (line[++i])
	{
		if ((line[i] == '0' || line[i] == '1'))
			numbers[i] = line[i] - '0';
		else if (!canva->player_count && ft_isplayer(line[i], canva))
		{
			numbers[i] = 2;
			canva->cx = i;
			canva->cy = row_num;
		}
		else if (line[i] == ' ')
			numbers[i] = ' ';
		else
		{
			free(numbers);
			error_free(canva, -1, "Error: Invalid characters\n");
		}
	}
	while (i < canva->longest_row)
		numbers[i++] = ' ';
	return (numbers);
}

void	init_struct(t_data *canva)
{
	int	i;

	i = -1;
	canva->longest_row = 0;
	canva->cur_tex = 0;
	canva->cur_line = 0;
	ft_bzero(canva->tex, 4);
	while (++i < 6)
		canva->flag[i] = 0;
	i = -1;
	while (++i < 4)
		canva->texture2[i].img = 0;
	canva->map = 0;
	canva->player_count = 0;
	canva->final_c = 0;
	canva->first_lines = 0;
	canva->player_count = 0;
	canva->player.dx = 0;
	canva->player.dy = 0;
	canva->camaera.x = 0;
	canva->camaera.y = 0;
	canva->height = 1020;
	canva->width = 1060;
	canva->scale = 8;
	canva->player.da = 90.0f * PI / 180.0f;
}


