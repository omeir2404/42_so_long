/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:48:46 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:36:32 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define ERROR 1

# define PIXELS 64

typedef struct s_player
{
	int	x;
	int	y;
	int	collectable;
	
}	t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	void	*imgs[300];
	int		collectables;
	int		line;
	int		collumn;
	int		exits;
	int		players;
	char	**check;
	int		check_exits;
	//
	
}	t_map;

// window info
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	int			moves;
	t_player	player;
	int			count;
}	t_data;

int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
t_data	setup_img_hooks(t_data data, char **argv);
void	destroy_free_window(t_data *data);

//GNL
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*make_line(char *line, char *buff);
int		ft_check_next_line(char *str);
// \GNL

int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);

//checks
int		checks(t_data *data, char **argv, char **map, int ac);
int		check_map(t_data *data, char **map, char **av);
int		check_square_and_borders(t_data *data, char **map, char **av);
int		check_first_last_line_borders(char **map, char **av);
void	copy_map(t_data *data, int counter, int fd, char ***map);
int		map_line_count_map(char **map);
int		check_file(char *map_file);
int		check_args(int ac);
int		check_help1(char **map, int prev_column, int column, int line_hold);
int		check_help2(t_data *data);
int		check_map_chars(t_data *data);
static int	can_go(t_data *data, int x, int y);
void	check_path(t_data *data, int x, int y);
int		path(t_data *data);

// \checks
void	free_map(char **map, int len);

void	make_map(t_data *data);
void	make_imgs(t_data *data);

int		alter_map(t_data *data, char *movement);
int		move_player(t_data *data, char *movement, int line, int column);

void	destroy_free_map(t_data *data);

int		end_all(t_data *data);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif