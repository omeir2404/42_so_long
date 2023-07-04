/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:54:26 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/01 16:10:32 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

int	check_args(int ac)
{
	if (ac == 1)
	{
		printf("no map indicated\n");
		return (ERROR);
	}
	if (ac > 2)
	{
		printf("only one map can be used!!\n");
		return (ERROR);
	}
	if (!(ac == 2))
		return (ERROR);
	return (0);
}

int	check_file(char *map_file)
{
	int		fd;
	char	*extension;

	fd = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("file open returned error\n");
		return (ERROR);
	}
	extension = ft_strrchr(map_file, '.');
	if (extension == NULL || ft_strcmp(".ber", extension) != 0)
	{
		printf("wrong file extension\n");
		return (ERROR);
	}
	return (0);
}

int	check_first_last_line_borders(char **map, char **av)
{
	int	line;
	int	column;

	column = 0;
	line = map_line_count_map(map) - 1;
	while (map[0][column] != '\n')
	{
		if (map[0][column] != '1')
		{
			printf("found 0 on top border");
			return (ERROR);
		}
		column++;
	}
	column = 0;
	while (map[line][column])
	{
		if (map[line][column] != '1')
		{
			printf("found 0 on bottom border");
			return (ERROR);
		}
		column++;
	}
	return (0);
}

int	check_help1(char **map, int prev_column, int column, int line_hold)
{
	if (map[line_hold][0] != '1')
	{
		printf("first column has value not 1");
		return (ERROR);
	}
	if (prev_column != 0 && prev_column != column)
	{
		printf("NOT RECT!");
		return (ERROR);
	}
	if (map[line_hold][column] != '1')
	{
		printf("last column has value not 1");
		return (ERROR);
	}
	return (0);
}
