/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oharoon <oharoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:12:40 by oharoon           #+#    #+#             */
/*   Updated: 2023/04/04 17:27:46 by oharoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;

	len = 0;
	while (s[len])
		len++;
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
//
/*int main(void)
{
	const char str[] = "hello world\n";
	printf("%s", ft_strrchr(str, 111));
	printf("%s", strrchr(str, 111));
}*/