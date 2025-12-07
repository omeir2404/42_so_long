/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:12:03 by oharoon           #+#    #+#             */
/*   Updated: 2025/12/07 22:18:25 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

int	map_line_count_map(char **map)
{
	int		i;
	char	**temp;

	i = 0;
	temp = map;
	while (temp[i] != NULL)
		i++;
	return (i);
}

void	make_map(t_data *data)
{
	int	posi;
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			posi = data->map.map[y][x];
			if (data->map.imgs[posi])
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->map.imgs[posi], \
					x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}

void	copy_map(t_data *data, int counter, int fd, char ***map)
{
	char	*gnl;

	gnl = get_next_line(fd);
	if (gnl != NULL)
		copy_map(data, counter + 1, fd, map);
	else
	{
		(*map) = malloc(sizeof(char *) * (counter + 1));
		data->map.height = counter;
	}
	(*map)[counter] = gnl;
}