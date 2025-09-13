/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:52:17 by mshariar          #+#    #+#             */
/*   Updated: 2025/09/13 20:39:40 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(void *ptr, size_t *return_val)
{
	char			*str;
	unsigned long	ptr_address;

	if (!ptr)
	{
		ft_putstr("(nil)", return_val);
		return ;
	}
	ptr_address = (unsigned long)ptr;
	ft_putstr("0x", return_val);
	str = ft_convertbase(ptr_address, HEX_LOW_BASE);
	ft_putstr(str, return_val);
	free(str);
}

void	ft_putnbr_pf(int n, size_t *return_val)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_pf('-', return_val);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_pf(nb / 10, return_val);
	ft_putchar_pf((nb % 10 + '0'), return_val);
}

void	ft_puthex(unsigned int num, size_t *return_val, char *base)
{
	char	*str;

	str = ft_convertbase(num, base);
	ft_putstr(str, return_val);
	free(str);
}

static size_t	ft_len(size_t n, char *base)
{
	size_t				len;
	size_t				nb;

	len = 1;
	nb = ft_strlen(base);
	while (n >= nb)
	{
		n /= nb;
		len++;
	}
	return (len);
}

char	*ft_convertbase(size_t n, char *base)
{
	char	*str;
	int		len;
	int		nb;
	int		i;

	len = ft_len(n, base);
	nb = ft_strlen(base);
	str = malloc((len + 1) * sizeof(char));
	if (!str || !base)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		str[i] = '\0';
		i++;
	}
	while (len > 0)
	{
		len--;
		str[len] = base[n % nb];
		n /= nb;
	}
	return (str);
}
