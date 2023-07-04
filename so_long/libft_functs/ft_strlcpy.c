/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:56:03 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 16:32:07 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
int	main(void)
{
	size_t s = 5;
	char dst[] = "hello";
	char src[] = "goodbye";
	printf("before: src: %s \n dst: %s \n", src, dst);
	ft_strlcpy(dst, src, s);
	printf("after: src: %s \n dst: %s \n", src, dst);
	char ogdst[] = "hello";
	const char ogsrc[] = "goodbye";
	printf("before og: src: %s \n dst: %s \n", ogsrc, ogdst);
	strlcpy(ogdst, ogsrc, s);
	printf("after og: src: %s \n dst: %s \n", ogsrc, ogdst);
}*/