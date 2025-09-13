/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:05:10 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/31 15:45:35 by mshariar         ###   ########.fr       */
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
	char dest[0];
	char cdest[0];
	char *src = "I am moving";
	char *csrc = "I am moving";
	ft_memmove(dest, src, 0);
	memmove(cdest, csrc, 0);
	printf("%s\n", src);
	printf("%s", csrc);
	return 0;
}
*/