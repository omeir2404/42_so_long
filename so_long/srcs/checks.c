/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:54:26 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:29:02 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

int	check_square_and_borders(t_data *data, char **map, char **av)
{
	(void)av;
	int	line_count;
	int	line_hold;
	int	column;
	int	prev_column;

	line_count = map_line_count_map(map);
	line_hold = 0;
	prev_column = 0;
	while (line_hold < line_count)
	{
		column = 0;
		while (map[line_hold][column + 1] != '\n'
			&& map[line_hold][column + 1] != '\0')
		column++;
		if (check_help1(map, prev_column, column, line_hold) == ERROR)
			return (ERROR);
		line_hold++;
		prev_column = column;
	}
	data->map.width = column;
	return (0);
}

int	check_help2(t_data *data)
{
	if (data->map.map[data->map.line][data->map.collumn] == 'C')
		data->map.collectables++;
	if (data->map.map[data->map.line][data->map.collumn] == 'P')
	{
		data->player.x = data->map.collumn;
		data->player.y = data->map.line;
		data->map.players++;
	}
	if (data->map.map[data->map.line][data->map.collumn] == 'E')
		data->map.exits++;
	return (0);
}

int	check_map_chars(t_data *data)
{
	data->map.line = 0;
	data->map.collectables = 0;
	data->map.players = 0;
	data->map.exits = 0;
	while (data->map.map[data->map.line])
	{
		data->map.collumn = 0;
		while (data->map.map[data->map.line][data->map.collumn])
		{
			check_help2(data);
			data->map.collumn++;
		}
		data->map.line++;
	}
	if (data->map.collectables > 0 && data->map.players == 1
		&& data->map.exits == 1)
		return (0);
	return (ERROR);
}

int	check_map(t_data *data, char **map, char **av)
{

	if (check_first_last_line_borders(map, av) == ERROR)
		return (ERROR);
	if (check_square_and_borders(data, map, av) == ERROR)
		return (ERROR);
	if (check_map_chars(data) == ERROR)
		return (ERROR);
	return (0);
}

int	checks(t_data *data, char **argv, char **map, int ac)
{
	int	i;

	if (!map)
		return (ERROR);
	if (check_args(ac) == ERROR || check_file(argv[1]) == ERROR)
		return (ERROR);
	i = map_line_count_map(map);
	if (!(i > 0))
	{
		write(1, "map has no lines??", 18);
		return (ERROR);
	}
	if (check_map(data, map, argv) == ERROR)
		return (ERROR);
	path(data);
	return (0);
}
