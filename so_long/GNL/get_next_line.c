/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:17:55 by oharoon           #+#    #+#             */
/*   Updated: 2023/03/06 18:01:42 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = make_line(line, buff);
		if (ft_check_next_line(buff) == 1)
			break ;
		if (read(fd, buff, BUFFER_SIZE) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

/*int main()
{
	int fd = open("test.txt", O_RDONLY);;
	char *str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
/* has to search for \n in "line", {LINE 32}
	breaks if it finds "\n", else return(1) */