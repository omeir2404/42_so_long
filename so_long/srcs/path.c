/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:26:12 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:29:24 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

static int	can_go(t_data *data, int x, int y)
{
	if (data->map.check[y][x] == 'C')
		data->player.collectable++;
	if (data->map.check[y][x] == 'E')
		data->map.check_exits++;
	return (data->map.check[y][x] == '0' || data->map.check[y][x] == 'C');
}

void	check_path(t_data *data, int x, int y)
{
	data->count++;
	data->map.check[y][x] = 'P';
	if (can_go(data, x, y - 1))
		check_path(data, x, y - 1);
	if (can_go(data, x - 1, y))
		check_path(data, x - 1, y);
	if (can_go(data, x, y + 1))
		check_path(data, x, y + 1);
	if (can_go(data, x + 1, y))
		check_path(data, x + 1, y);
}

int	path(t_data *data)
{
	int	l;

	l = 0;
	data->map.check = malloc(sizeof(char *) * (data->map.height + 1));
	while (l < data->map.height)
	{
		data->map.check[l] = malloc(sizeof(char) * (data->map.width + 2));
		ft_strlcpy(data->map.check[l], data->map.map[l], (data->map.width + 2));
		l++;
	}
	data->map.check[l] = NULL;
	check_path(data, data->player.x, data->player.y);
	if (data->map.check_exits == 0)
	{
		write(1, "exit path error", 15);
		end_all(data);
	}
	if (data->map.collectables != data->player.collectable)
	{
		write(1, "collectable path error", 22);
		end_all(data);
	}
	return (0);
}
