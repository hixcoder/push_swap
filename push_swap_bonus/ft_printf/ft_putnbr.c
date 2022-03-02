/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:45:38 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/27 11:45:40 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
		count += ft_putchar(n + '0');
	else if (n > 9 && n <= 2147483647)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else
	{
		count += ft_putchar('-');
		count += ft_putnbr(-n);
	}
	return (count);
}
