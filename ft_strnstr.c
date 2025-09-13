/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:38:23 by mshariar          #+#    #+#             */
/*   Updated: 2024/12/19 17:34:21 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	find;

	i = 0;
	find = 0;
	if (little[find] == '\0')
		return ((char *)(big));
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			find = 1;
			while (big[i + find] == little[find]
				&& big[i + find] && i + find < len)
				find++;
			if (little[find] == '\0')
				return ((char *) &big[i]);
		}
		i++;
	}
	return (0);
}
/*#include<string.h>
#include<stdio.h>
int	main()
{
	char str[20] = "can you find yau it?";
	char to_find[] = "yau";
	printf("%p\n", ft_strnstr(str, to_find, 10));
	printf("%p\n", strnstr(str, to_find, 10));
}*/
