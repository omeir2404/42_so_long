/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:34:14 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:35:18 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

int	alter_map(t_data *data, char *movement)
{
	int	hold_c;
	int	hold_l;

	data->map.line = 0;
	data->map.collumn = 0;
	hold_c = -1;
	hold_l = -1;
	while (data->map.map[data->map.line])
	{
		while (data->map.map[data->map.line][data->map.collumn])
		{
			if (data->map.map[data->map.line][data->map.collumn] == 'P')
			{
				hold_c = data->map.collumn;
				hold_l = data->map.line;
			}
			data->map.collumn++;
		}
		data->map.collumn = 0;
		data->map.line++;
	}
	if (!(hold_c != -1 && hold_l != -1))
		return (ERROR);
	move_player(data, movement, hold_l, hold_c);
	return (0);
}

int	move_player4(t_data *data, char *movement, int line, int collumn)
{
	if (ft_strcmp(movement, "left") == 0)
	{
		if (data->map.map[line][collumn - 1] == 'E'
			&& data->map.collectables == 0)
			end_all(data);
		if (data->map.map[line][collumn - 1] == 'C')
			data->map.collectables--;
		if (data->map.map[line][collumn - 1] != '1'
			&& data->map.map[line][collumn - 1] != 'E')
		{
			data->map.map[line][collumn - 1] = 'P';
			data->map.map[line][collumn] = '0';
		}
		else if (data->map.map[line][collumn - 1] == '1')
		{
			printf("wall");
			return (ERROR);
		}
	}
}

int	move_player3(t_data *data, char *movement, int line, int collumn)
{
	if (move_player4(data, movement, line, collumn) == ERROR)
		return (ERROR);
	if (ft_strcmp(movement, "up") == 0)
	{
		if (data->map.map[line - 1][collumn] == '1')
		{
			printf("wall");
			return (ERROR);
		}
		if (data->map.map[line - 1][collumn] == 'C')
			data->map.collectables--;
		if (data->map.map[line - 1][collumn] == 'E'
			&& data->map.collectables == 0)
			end_all(data);
		if (data->map.map[line - 1][collumn] != '1'
			&& data->map.map[line - 1][collumn] != 'E')
		{
			data->map.map[line - 1][collumn] = 'P';
			data->map.map[line][collumn] = '0';
		}
	}
	return (0);
}

int	move_player2(t_data *data, char *movement, int line, int collumn)
{
	if (move_player3(data, movement, line, collumn) == ERROR)
		return (ERROR);
	if (ft_strcmp(movement, "right") == 0)
	{
		if (data->map.map[line][collumn + 1] == 'E'
			&& data->map.collectables == 0)
			end_all(data);
		if (data->map.map[line][collumn + 1] == 'C')
			data->map.collectables--;
		if (data->map.map[line][collumn + 1] != '1'
			&& data->map.map[line][collumn + 1] != 'E')
		{
			data->map.map[line][collumn + 1] = 'P';
			data->map.map[line][collumn] = '0';
		}
		else if (data->map.map[line][collumn + 1] == '1')
		{
			printf("wall");
			return (ERROR);
		}
	}
	return (0);
}

int	move_player(t_data *data, char *movement, int line, int collumn)
{
	if (move_player2(data, movement, line, collumn) == ERROR)
		return (ERROR);
	if (ft_strcmp(movement, "down") == 0)
	{
		if (data->map.map[line + 1][collumn] == 'E'
			&& data->map.collectables == 0)
			end_all(data);
		if (data->map.map[line + 1][collumn] == 'C')
			data->map.collectables--;
		if (data->map.map[line + 1][collumn] != '1'
			&& data->map.map[line + 1][collumn] != 'E')
		{
			data->map.map[line + 1][collumn] = 'P';
			data->map.map[line][collumn] = '0';
		}
		else if (data->map.map[line + 1][collumn] == '1')
		{
			printf("wall");
			return (ERROR);
		}
	}
	return (0);
}
