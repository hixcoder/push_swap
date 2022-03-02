/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:44:58 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/02 10:32:54 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LB "0123456789abcdef"
#define UB "0123456789ABCDEF"
#define DB "0123456789"

static void	ft_print_after_percent(char str, va_list args, int *l)
{
	if (str == 'c')
		*l += ft_putchar((char)va_arg(args, int));
	else if (str == 's')
		*l += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
	{
		*l += ft_putstr("0x");
		*l += ft_putnbr_base2((unsigned long)va_arg(args, void *), LB);
	}
	else if (str == 'd' || str == 'i')
		*l += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		*l += ft_putnbr_base((long)va_arg(args, unsigned int), DB);
	else if (str == 'x')
		*l += ft_putnbr_base((long)va_arg(args, unsigned int), LB);
	else if (str == 'X')
		*l += ft_putnbr_base((long)va_arg(args, unsigned int), UB);
	else if (str == '%')
		*l += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else
		{
			i++;
			ft_print_after_percent(str[i], args, &count);
		}
	}
	va_end(args);
	return (count);
}
