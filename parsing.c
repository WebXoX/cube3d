#include "cube3d.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c < 13) || c == 32)
		return (1);
	return (0);
}

int ft_isplayer(char c)
{
	return (c=='N' || c== 'E' || c== 'W' || c == 'S');
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
		if (ft_isdigit(line[i]) && (line[i] == '0' || line[i] == '1'))
			numbers[i]=line[i] - '0';
		else if(!canva->player_count && ft_isplayer(line[i]))
		{
			(canva->player_count)++;
			printf("%d-????count-------->\n",canva->player_count);
			numbers[i]=2;
		}
		else if(line[i] == ' ')
			numbers[i] = ' ';
		else
		{
			printf("ERORRRRR!!!!\n");
			exit(0);
		}
	}
	canva->lengths[row_num] = i;
	while(i < canva->longest_row)
		numbers[i++] = ' ';
	printf_all(numbers, i);
	return numbers;
}

void validate_zeroes(int **map, t_data canva)
{
	int i = 0;
	int j = 0;
	while(i < canva.final_c)
	{
		j = 0;
		while(j < canva.longest_row)
		{
			if(map[i][j] == 0 || ft_isplayer(map[i][j]))
			{
				int k = i;
				int l = j;
				while(k >= 0)
				{
					if( j < canva.lengths[k] && map[k][j] == 1)
						break;
					else if (j > canva.lengths[k])
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
				while(k < canva.final_c)
				{
					if( j < canva.lengths[k] && map[k][j] == 1)
						break;
					else if (j > canva.lengths[k])
					{
						printf("ERRORZ3!!!\n");
						exit(0);
					}
					k++;
				}
				if(k == canva.final_c)
				{
					printf("ERRORZ4!!!\n");
					exit(0);
				}

				while(l >= 0)
				{
					if( l < canva.lengths[i] && map[i][l] == 1)
						break;
					l--;
				}
				if(l == -1)
				{
					printf("ERRORZ5!!!\n");
					exit(0);
				}
				l = j;
				while(l < canva.lengths[i])
				{
					if( l < canva.lengths[i] && map[i][l] == 1)
						break;
					l++;
				}
				if(l == canva.lengths[i])
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

void validate_spaces(int **map, t_data canva)
{
	int i = 0;
	int j;
	int wrong;
	while(i < canva.final_c)
	{
			j = 0;
		while(j < canva.lengths[i])
		{
			wrong = 0;
			if(map[i][j] == ' ')
			{
				if(i > 0 && j > canva.lengths[i - 1])
					if(!(map[i - 1][j] == 1 || map[i - 1][j] == ' '))
						wrong++;
				if(j + 1 < canva.lengths[i])
					if(!(map[i][j + 1] == 1 || map[i][j + 1] == ' '))
						wrong++;
				if(i + 1 < canva.final_c && j > canva.lengths[i + 1])
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

