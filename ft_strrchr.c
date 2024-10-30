/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:44:38 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/28 16:37:12 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char) c)
			p = s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char) c)
		return ((char *) s);
	return ((char *) p);
}
/*
#include <stdio.h>
#include <string.h>

int	main ()
{
	char *str = "can you find it";
	char *res = ft_strrchr(str, ' ');
	char *str1 = "can you find it";
	char *res1 = strrchr(str1, ' ');

	printf ("%s\n", res);
	printf ("%s", res1);
}
*/