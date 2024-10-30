/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:29:46 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/19 14:50:17 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] == s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include<stdio.h>
#include<string.h>

int	main(void)
{
	char	s1[] = "hell";
	char	s2[] = "hell";
	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d", strncmp(s1, s2, 5));
}*/
