/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:47:31 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:36:13 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	main(int ac, char **argv)
{
	static t_data	data;

	data.map.height = 0;
	data.map.width = 1;
	copy_map(&data, data.map.height, open(argv[1], O_RDONLY), &data.map.map);
	data.mlx_ptr = mlx_init();
	if (checks(&data, argv, data.map.map, ac) == ERROR)
		return (ERROR);
	if (data.mlx_ptr == NULL)
		return (ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map.width + 1)
			* PIXELS, data.map.height * PIXELS, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (ERROR);
	}
	make_imgs(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 131072, &end_all, &data);
	make_map(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
