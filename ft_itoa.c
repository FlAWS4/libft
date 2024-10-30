/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:25:38 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/26 16:54:20 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	slen(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*str;

	num = (long)n;
	len = slen(n);
	str = (char *)malloc (len + 1);
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (n < 0)
		num *= -1;
	while (num > 0)
	{
		*(str + len--) = num % 10 + '0';
		num /= 10;
	}
	if (str[1] == '\0' && len == 0)
		*(str + len) = '0';
	else if (str[1] != '\0' && len == 0)
		*(str + len) = '-';
	return (str);
}

/*
#include <limits.h>
int	main()
{
	printf("%s\n", ft_itoa(INT_MIN));
}
*/