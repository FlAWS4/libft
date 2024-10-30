/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:42:22 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/28 15:21:19 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*p;

	p = (const char *)s;
	i = -1;
	while (++i < n)
	{
		if ((char)*(p + i) == (char)c)
			return ((void *)(p + i));
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str = "copy that";
	char	*res = ft_memchr(str, ' ', 5);
	char	*str1 = "copy that";
	char	*res1 = ft_memchr(str1, ' ', 5);

	printf("%s\n", res);
	printf("%s", res1);
}*/