/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:05:10 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/28 15:12:53 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (!src && !dest)
		return (NULL);
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (dest < src)
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	else if (dest > src)
	{
		cdest = cdest + n - 1;
		csrc = csrc + n - 1;
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>

int	main()
{
	char src[20] = "Geeksfor";
	char csrc[20] = "Geeksfor";
	ft_memmove(src + 0, src, strlen(src) + 1);
	memmove(csrc + 0, csrc, strlen(csrc) + 1);
	printf("%s\n", src);
	printf("%s", csrc);
	return 0;
}*/
