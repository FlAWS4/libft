/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:21:59 by mshariar          #+#    #+#             */
/*   Updated: 2025/09/13 20:42:45 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_pf(char *str, size_t *return_val)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str, return_val);
		str++;
	}
}

void	ft_putuint(unsigned int num, size_t *return_val)
{
	char	*str;

	str = ft_convertbase(num, "0123456789");
	ft_putstr_pf(str, return_val);
	free(str);
}

int	ft_putchar_pf(char c, size_t *return_val)
{
	int	error;

	error = write(1, &c, 1);
	if (error == -1)
		return (-1);
	(*return_val)++;
	return (-1);
}

int	ft_format(va_list ap, char *str, size_t *return_val)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(ap, int), return_val);
	else if (*str == 's')
		ft_putstr_pf(va_arg(ap, char *), return_val);
	else if (*str == 'p')
		ft_putptr(va_arg(ap, void *), return_val);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(ap, int), return_val);
	else if (*str == 'u')
		ft_putuint(va_arg(ap, unsigned int), return_val);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex(va_arg(ap, unsigned int), return_val, HEX_LOW_BASE);
		else
			ft_puthex(va_arg(ap, unsigned int), return_val, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar_pf(*str, return_val);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	size_t		return_val;

	if (!str)
		return (-1);
	return_val = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(ap, (char *)str, &return_val);
		}
		else
		{
			ft_putchar_pf(*str, &return_val);
		}
		str++;
	}
	va_end(ap);
	return (return_val);
}

/*
int main(void)
{
    int ret_ft, ret_std;
    char *test_str = "Hello World";
    char c = 'A';
    int num = 42;
    int neg_num = -42;
    unsigned int u_num = 4294967295U;
    void *ptr = &num;

    printf("=== ft_printf vs printf comparison ===\n\n");

    // Test character
    printf("--- Character test ---\n");
    printf("std: ");
    ret_std = printf("Character: %c\n", c);
    printf("ft : ");
    ret_ft = ft_printf("Character: %c\n", c);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test string
    printf("--- String test ---\n");
    printf("std: ");
    ret_std = printf("String: %s\n", test_str);
    printf("ft : ");
    ret_ft = ft_printf("String: %s\n", test_str);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test NULL string
    printf("--- NULL string test ---\n");
    printf("std: ");
    ret_std = printf("NULL string: %s\n", (char *)NULL);
    printf("ft : ");
    ret_ft = ft_printf("NULL string: %s\n", (char *)NULL);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test pointer
    printf("--- Pointer test ---\n");
    printf("std: ");
    ret_std = printf("Pointer: %p\n", ptr);
    printf("ft : ");
    ret_ft = ft_printf("Pointer: %p\n", ptr);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test integers
    printf("--- Integer test ---\n");
    printf("std: ");
    ret_std = printf("Integer: %d, %i\n", num, neg_num);
    printf("ft : ");
    ret_ft = ft_printf("Integer: %d, %i\n", num, neg_num);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test unsigned
    printf("--- Unsigned test ---\n");
    printf("std: ");
    ret_std = printf("Unsigned: %u\n", u_num);
    printf("ft : ");
    ret_ft = ft_printf("Unsigned: %u\n", u_num);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test hexadecimal
    printf("--- Hexadecimal test ---\n");
    printf("std: ");
    ret_std = printf("Hex lower: %x, Hex upper: %X\n", 255, 255);
    printf("ft : ");
    ret_ft = ft_printf("Hex lower: %x, Hex upper: %X\n", 255, 255);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test percent
    printf("--- Percent test ---\n");
    printf("std: ");
    ret_std = printf("Percent: %%\n");
    printf("ft : ");
    ret_ft = ft_printf("Percent: %%\n");
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test edge cases
    printf("--- Edge cases ---\n");
    printf("std: ");
    ret_std = printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
    printf("ft : ");
    ret_ft = ft_printf("INT_MAX: %d, INT_MIN: %d\n", INT_MAX, INT_MIN);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test zero
    printf("--- Zero test ---\n");
    printf("std: ");
    ret_std = printf("Zero: %d, %x, %X\n", 0, 0, 0);
    printf("ft : ");
    ret_ft = ft_printf("Zero: %d, %x, %X\n", 0, 0, 0);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    // Test mixed format
    printf("--- Mixed format test ---\n");
    printf("std: ");
    ret_std = printf("Mixed: %c %s %d %x %p %%\n", 'Z', "test", 123, 0xABC, &c);
    printf("ft : ");
	ret_ft = \
	ft_printf("Mixed: %c %s %d %x %p %%\n", 'Z', "test", 123, 0xABC, &c);
    printf("Return values - std: %d, ft: %d\n\n", ret_std, ret_ft);

    printf("=== Test completed ===\n");
    return (0);
}
*/