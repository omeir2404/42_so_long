/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:13:12 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:35:28 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"
/* The x and y coordinates of the rect corresponds to its upper left corner. */

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
