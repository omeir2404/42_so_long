/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:13:12 by oharoon           #+#    #+#             */
/*   Updated: 2023/10/10 16:34:10 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"
/* The x and y coordinates of the rect corresponds to its upper left corner. */


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
	return 0;
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

int	end_all(t_data *data)
{
	destroy_free_window(data);
	mlx_destroy_display(data->mlx_ptr);
	exit(0);
}

int	handle_keypress2(int keysym, t_data *data)
{
	if (keysym == 0xff52 || keysym == 0x77)
	{
		if (alter_map(data, "up") == 0)
		{
			make_map(data);
			data->moves++;
			printf("moves: %i\n", data->moves);
		}
	}
	if (keysym == 0xff53 || keysym == 0x64)
	{
		if (alter_map(data, "right") == 0)
		{
			make_map(data);
			data->moves++;
			printf("moves: %i\n", data->moves);
		}
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_all(data);
	if (keysym == 0xff52 || keysym == 0x77)
		handle_keypress2(keysym, data);
	if (keysym == 0xff53 || keysym == 0x64)
		handle_keypress2(keysym, data);
	if (keysym == 0xff51 || keysym == 0x61)
	{
		if (alter_map(data, "left") == 0)
		{
			make_map(data);
			data->moves++;
			printf("moves: %i\n", data->moves);
		}
	}
	if (keysym == 0xff54 || keysym == 0x73)
	{
		if (alter_map(data, "down") == 0)
		{
			make_map(data);
			data->moves++;
			printf("moves: %i\n", data->moves);
		}
	}
	return (0);
}

void	destroy_free_window(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
		free(data->map.map[i++]);
	i = 0;
	while (data->map.check[i])
		free(data->map.check[i++]);
	free(data->map.map);
	free(data->map.check);
	if (data->map.imgs['0'])
		mlx_destroy_image(data->mlx_ptr, data->map.imgs['0']);
	if (data->map.imgs['P'])
		mlx_destroy_image(data->mlx_ptr, data->map.imgs['P']);
	if (data->map.imgs['1'])
		mlx_destroy_image(data->mlx_ptr, data->map.imgs['1']);
	if (data->map.imgs['C'])
		mlx_destroy_image(data->mlx_ptr, data->map.imgs['C']);
	if (data->map.imgs['E'])
		mlx_destroy_image(data->mlx_ptr, data->map.imgs['E']);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	make_imgs(t_data *data)
{
	int	w;
	int	h;

	data->map.imgs['0']
		= mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm_files/lastsea.xpm", &w, &h);
	data->map.imgs['P']
		= mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm_files/Warrior_1.xpm", &w, &h);
	data->map.imgs['1']
		= mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm_files/lastisland.xpm", &w, &h);
	data->map.imgs['C']
		= mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm_files/lastcoin.xpm", &w, &h);
	data->map.imgs['E']
		= mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm_files/cave.xpm", &w, &h);
}
