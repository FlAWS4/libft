/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:45:04 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/28 16:33:36 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	j;

	i = 0;
	j = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size < d || size == 0)
		return (s + size);
	j = d;
	while (src[i] != '\0' && j < (size - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (d + s);
}
/*
int	main(void)
{
	char	dest[20] = " come on";
	char    dest1[20] = " come on";
	char	src[] = " copy that";
	char    src1[] = " copy that";
	printf("%zu\n %s\n", ft_strlcat(dest, src, 1), dest);
	printf("%zu\n %s\n", strlcat(dest1, src1, 1), dest1);
}*/
