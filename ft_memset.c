/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:53:53 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/18 16:16:54 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *) s;
	while (n > 0)
	{
		*dst = (unsigned char)c;
		dst++;
		n--;
	}
	return (s);
}
/*
int	main ()
{
	char	str[] = "HELLO";
	char	str1[] = "hello";
	size_t len = 3;
	int i = 0;

	ft_memset(str, 'a', len);
	while (len > 0)
	{
		printf("%c", str[i]);
		i++;
		len--;
	}
	i = 0;
	len = 3;
	memset(str1, 'A' , len);
	printf("\n");
	while (len > 0)
	{
		printf("%c", str1[i]);
		i++;
		len--;
	}
}*/	
